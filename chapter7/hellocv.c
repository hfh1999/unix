#include <stdio.h>
#include <curses.h>
int main (void)
{
    initscr();
    clear();
    move(10,20);
    addstr("HEllo!!!");
    standout();
    move(LINES-1,0);
    refresh();
    getch();
    endwin();
}
