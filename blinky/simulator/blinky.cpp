#include <ctype.h>
#include <stdio.h>
#include <ncurses.h>
#include "util.h"
#include "Vblinky.h"
#include "verilated.h"

// The simulator
int main (int argc, char **argv, char **env) {
  int row, col;

  Verilated::commandArgs(argc, argv);

  // Initialize ncurses
	initscr();
  getmaxyx(stdscr, row, col);
  cbreak();
  timeout(0);
  curs_set(0);
	raw();
	noecho();

  Vblinky* blinky = new Vblinky;

  // Tick the clock until we are done
  bool done = false;
  uint64_t ticks = 0;
  int speed = 1;
  bool pause = false;
	while(!Verilated::gotFinish() && !done) {
    // Get a user command
  	char userCh = getch();
    switch(tolower(userCh)) {
      case 'q':
        done = true;
        break;
      case 'p':
        pause = !pause;
        break;
      case '1':
        speed = 1;
        pause = false;
        break;
      case '2':
        speed = 32; // 2^5
        pause = false;
        break;
      case '3':
        speed = 1024; // 2^10
        pause = false;
        break;
      case '4':
        speed = 32768; // 2^15
        pause = false;
        break;
      case '5':
        speed = 131072; // 2^17
        pause = false;
        break;
      case '6':
        speed = 524288; // 2^19
        pause = false;
        break;
      default:
        break;
    }

    // Update the screen
    if (ticks % speed == 0 || pause) {
      // Format the register value
      char binary [27];
      itoa(blinky->blinky__DOT__counter, binary, 2);

      char buffer [27];
      leftPadZero(buffer, binary, 27);

      clear();
      mvprintw(1, 1, "Led: %d", blinky->o_led);
      mvprintw(2, 1, "Reg: %s", buffer);
      mvprintw(row - 2, 0, "q: Quit | 1-6: Speed | p: Pause");
      mvprintw(row - 1, 0, "Clock Ticks: %d", ticks);
      if (!pause) {
        mvprintw(row - 1, col - 21, "Update Speed: %d", speed);
      } else {
        mvprintw(row - 1, col - 21, "Update Speed: paused");
      }
      refresh();
    }

    if (!pause) {
      // Run the simulation
  		blinky->i_clk = 1;
  		blinky->eval();
  		blinky->i_clk = 0;
  		blinky->eval();

      ticks++;
    }
	}

  endwin();
  delete blinky;
  exit(EXIT_SUCCESS);
}
