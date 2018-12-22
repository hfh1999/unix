#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#define ops(s,n) {perror(s); exit(n);}
int main (int argc,char * argv[])
{
    if (argc != 2)
        printf("usage:setecho [y|n]\n");
    struct termios info;
    if ((tcgetattr(0,&info)) == -1)
        ops("Get attr",1);
    if(argv[1][0] == 'y')
        info.c_lflag |=  ECHO;//更改值
    else
        info.c_lflag &= ~ECHO;//清零
    if (tcsetattr(0,TCSANOW,&info) == -1)
        ops("Set atter",2);
    return 0;
}
