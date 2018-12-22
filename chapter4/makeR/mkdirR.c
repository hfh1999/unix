#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "solve.h"
#define STRLEN 256
void mkdirP(char * argrec);
void maked( char * path );
int main (int argc,char * argv[])
{
    mkdirP(argv[1]);              //路径名
    return 0;
    printf(" argc is %d",argc);
}
void mkdirP(char * argrec)
{
    char string[STRLEN];
    while ( solve(argrec,string) )
    {
        if ( chdir(string) == 0 ) //成功切换路径
            continue;
        else                      //暂时不考虑权限问题
        {
            maked(string);         //创建目录
            chdir(string);
        }
    }
}
void maked( char * path )
{
    if (mkdir(path,S_IRWXU|S_IXGRP) == 0)    
        return;
    else
    {
        perror("make Dir");
        exit(1);
    }
}
