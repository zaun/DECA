#include "util.h"
#include "Vblinky.h"
#include "verilated.h"

// Define our test cases
struct TestCase {
	const char* name;
  uint8_t o_led_expected;
  const char* r_counter_expected;
  uint32_t ticks;
};

TestCase testCases[] {
  { "Should default to off and zeroed register", 0, "00000000000000000000000000", 0 },
  { "Should be off with 1 in the register",      0, "00000000000000000000000001", 1 },
  { "Should be off with 2 in the register",      0, "00000000000000000000000010", 2 },
  { "Should be off with 3 in the register",      0, "00000000000000000000000011", 3 },
  { "Should be off with 4 in the register",      0, "00000000000000000000000100", 4 },
  { "Should not turn on before 2^25 ticks",      0, "01111111111111111111111111", 33554432 - 1 },
  { "Should turn on at 2^25 ticks",              1, "10000000000000000000000000", 33554432 },
  { "Should stay on after 2^25 ticks",           1, "10000000000000000001100100", 33554432 + 100 },
  { "Should stay on before 2^50 ticks",          1, "11111111111111111111111111", 33554432 + 33554432 - 1 },
  { "Should turn off at 2^50 ticks",             0, "00000000000000000000000000", 33554432 + 33554432 },
  { "Should stay off after 2^50 ticks",          0, "00000000000000000001100100", 33554432 + 33554432  + 100}
};

// The test runner
int main (int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);

  int numTests = sizeof(testCases)/sizeof(TestCase);
  int failTests = 0;

  printf("\n\nBlinky unit tests\n");
  printf("-----------------\n\n");

  for (int k = 0; k < numTests; k++) {
    // Init the module
    Vblinky* blinky = new Vblinky;
    blinky->i_clk = 0;

    // Run the test
    TestCase *testCase = &testCases[k];
    for (int counter = 0; counter < testCase->ticks; counter++) {
      blinky->i_clk = 1;
      blinky->eval();
      blinky->i_clk = 0;
      blinky->eval();
    }

    // Format the register value
    char binary [27];
    itoa(blinky->blinky__DOT__counter, binary, 2);

    char buffer [27];
    leftPadZero(buffer, binary, 27);

    // Verify the test results
    if (blinky->o_led != testCase->o_led_expected ||
		    strcmp(buffer, testCase->r_counter_expected) != 0) {
      failTests ++;
      printf("(F) %s\n", testCase->name);
      printf("    o_led %d expected to be %d\n", blinky->o_led, testCase->o_led_expected);
      printf("    r_counter %s expected\n", buffer);
      printf("        to be %s\n", testCase->r_counter_expected);
    } else {
      printf("(P) %s\n", testCase->name);
    }

    // Cleanup
    delete blinky;
  }

  // Print a summary
  printf("\n%d of %d failed tests\n\n", failTests, numTests);

  if (failTests > 0) {
    exit(1);
  } else {
    exit(0);
  }
}
