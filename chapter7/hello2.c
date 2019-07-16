#include <stdio.h>
#include <curses.h>
int main (void)
{
    int i;
    initscr();
    clear();
    for (i = 0; i<LINES;i++)
    {
        move(i,2*i);
        if (i%2 == 1)
            standout();
        addstr("O");
        if (i%2 == 1)
            standend();
        refresh();
    }
        getch();
        endwin();
        return 0;
}
