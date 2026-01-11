#include "terminal.h"
#include <clocale>

#define _XOPEN_SOURCE_EXTENDED
#include <ncurses.h>

Terminal::Terminal() {
    setlocale(LC_ALL, "");
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    set_escdelay(1000 / 60);
}

Terminal::~Terminal() {
    flushinp();
    endwin();
}

void Terminal::savePostion() {
    getyx(stdscr, y, x);
}
