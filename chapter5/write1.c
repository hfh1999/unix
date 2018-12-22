#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFSIZE 256
void wMseg(char * ttyname);
int main (int argc,char * argv[])
{
    if (argc != 2)
    {
        printf("Usage : write1 ttyname\n");
        exit(1);
    }
    wMseg(argv[1]);
    return 0;
}
void wMseg(char * ttyname)
{
    int fd;
    char bufpool[BUFSIZ];
    if ((fd=open(ttyname,O_WRONLY)) == -1)
    {
        fprintf(stderr,"Can not open the tty needed!\n");
        exit(1);
    }
    while (fgets(bufpool,BUFSIZE,stdin) != NULL)//不到EOF的时候一直读取输入
    {
        if (write(fd,bufpool,BUFSIZE) == -1)
        {
            perror("Write");
            exit(1);
        } 
    }
}
