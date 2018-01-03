#include <ctype.h>
#include <stdio.h>
#include <ncurses.h>
#include "util.h"
#include "Vfifo.h"
#include "verilated.h"

// The simulator
int main (int argc, char **argv, char **env) {
  int row, col;

  const char* message = "Hello World! ";

  Verilated::commandArgs(argc, argv);

  // Initialize ncurses
	initscr();
  getmaxyx(stdscr, row, col);
  cbreak();
  curs_set(0);
	raw();
	noecho();

  Vfifo* fifo = new Vfifo;

  // Tick the clock until we are done
  bool done = false;
  int spot = 0;
	while(!Verilated::gotFinish() && !done) {

    clear();
    mvprintw(1, 1, "Q: Quit");
    mvprintw(2, 1, "W: Write to FIFO");
    mvprintw(3, 1, "R: Read from FIFO");
    mvprintw(3, 1, "B: Read and Write the FIFO");

    // Print the buffer
    for (int i=0; i < 16; i++) {
      mvprintw(7, 1 + (i * 5), "0x%02X", fifo->fifo__DOT__mem[i]);
    }
    mvprintw(6, 1 + (fifo->fifo__DOT__addr_read * 5), "-Rd-");
    mvprintw(8, 1 + (fifo->fifo__DOT__addr_write * 5), "-Wr-");
    mvprintw(10, 1, "Last read: %c", fifo->o_data);
    mvprintw(11, 1, "Is Empty (neg): %d", fifo->o_empty_n);
    mvprintw(12, 1, "Write Error:    %d", fifo->o_write_error);
    mvprintw(13, 1, "Read Error:     %d", fifo->o_read_error);
    refresh();

    // Get a user command
  	char userCh = getch();
    switch(tolower(userCh)) {
      case 'q':
        done = true;
        break;
      case 'w':
        fifo->i_data = message[spot];
        fifo->i_write = 1;
        fifo->i_read = 0;
        spot += 1;
        break;
      case 'r':
        fifo->i_data = 0;
        fifo->i_write = 0;
        fifo->i_read = 1;
        spot += 0;
        break;
      case 'b':
        fifo->i_data = message[spot];
        fifo->i_write = 1;
        fifo->i_read = 1;
        spot += 1;
        break;
      default:
        fifo->i_data = 0;
        fifo->i_write = 0;
        fifo->i_read = 0;
        spot += 0;
        break;
    }

    if (spot >= 13) {
      spot = 0;
    }

    fifo->i_clk_write = 1;
    fifo->i_clk_read = 1;
    fifo->eval();
    fifo->i_clk_write = 0;
    fifo->i_clk_read = 0;
    fifo->eval();
  }

  endwin();
  delete fifo;
  exit(EXIT_SUCCESS);
}
