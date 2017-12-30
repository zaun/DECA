#include <string.h>

// Convert Decimal into Binary
char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

// Left pad a string with 0
char* leftPadZero(char *result, char * value, int len) {
  for (int i = 0; i < len; i++) {
    result [i] = '0';
  }
  result [len - 1] = '\0';

  for (int j = strlen(value) - 1; j >= 0; j--) {
    result [len - strlen(value) + j - 1] = value [j];
  }

  return result;
}
