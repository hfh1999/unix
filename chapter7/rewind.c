#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <curses.h>
void wait4echo(int time);
void reecho (int signum);
int main (void)
{
    initscr();
    clear();
    printf("Let's DO IT!");
    while (1)
        wait4echo(1);
    return 0;
}
void wait4echo(int time)
{
    signal(SIGALRM,reecho);
    alarm(time);
    pause();
}
void reecho (int signum)
{
    static int i=0;
    clear();
    i=i%LINES;
    move(i,2*i);
    addstr("H");
    refresh();
    i++;
}
