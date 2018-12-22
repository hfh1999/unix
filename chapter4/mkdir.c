#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main (void)
{
    int state;
    if ( (state = mkdir("hello/thanks/",S_IRWXU|S_IRGRP|S_IROTH)) == 0 )
        printf("Dir made!\n");
    else
    {
        perror("mkdir");
        exit(1);
    }
    return 0;
}
