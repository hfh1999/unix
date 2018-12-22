//查看终端驱动程序中的echo设置是否开启！
#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
int main (void)
{
    struct termios info;
    if(tcgetattr(0,&info) != 0)
    {
        perror("Get  atter");
        exit(1);
    }
    if (info.c_lflag & ECHO)
        printf("echo is on !\n");
    else 
        printf("echo is off!\n");
    return 0;
}
