#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#define opps(s,n)  {perror(s); exit(n); }
#define QUESTION "Do you like to do again?"
void setmode (int contorl);
int askuser(char * srec);
int main (void)
{
    int retnum;
    retnum=askuser(QUESTION);   
    setmode(1);//标准模式
    printf("%d",retnum);
    return retnum;
}

int askuser(char * srec)
{
   int input;
   setmode(0) ;
   printf("%s(y/n)\n",srec);
   while (1)
   {
       switch(input = getchar())
       {
            case 'y':
            case 'Y':
                return 0;
            case 'n':
            case 'N':
            case EOF:
                return 1;
            default:
                printf("\nPLease enter a char in list!\n");
       }
   }
}
void setmode (int contorl)
{
    struct termios info;
    if (tcgetattr(0,&info) == -1)
        opps("Get atter",1);
    if (contorl)
        info.c_lflag |= ICANON;
    else
        info.c_lflag &= ~ICANON;
    if (tcsetattr(0,TCSANOW,&info) == -1)
        opps("Set atter",2);
}
