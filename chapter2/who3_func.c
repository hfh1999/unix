/*************************************************************************
	> File Name: who3_func.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月21日 星期日 19时43分33秒
 ************************************************************************/
//带缓冲的读取数据函数接口
#include<stdio.h>
#include<fcntl.h>
#include<utmp.h>
#include<unistd.h>
#include "who3_func.h"
#define BUFLEN 16
#define UTSIZE (sizeof(struct utmp)) 
#define UTNULL ((struct utmp *) NULL)
static int utkeep;//记录缓冲区记录了多少组数据
static struct utmp utmpRoom[BUFLEN];//定义缓冲区
static int utret;//缓冲区正在返回数据的位置
static int utrec;//缓冲区中的数据个数
static int utmpFile = -1;

struct utmp  * getnext(void)
{
    if (utkeep==0)//当缓冲区没有数据时
    {
        utret=0;
        utrec=read(utmpFile,utmpRoom,BUFLEN*UTSIZE);
        if ( utrec == 0 || utmpFile == -1 )//没收到数据,或是文件打开错误
            return UTNULL;
        else
            utkeep = utrec/UTSIZE;//更新区中数据数目,注意!!!!
    }
        utret++;
        utkeep--;
        return utmpRoom + utret-1;//返回数据指针
}

void openUtmp(void)
{
    utmpFile = open(UTMP_FILE,O_RDONLY);
    utret=0;//init process
    utrec=0;
    utkeep=0;
}
void closeUtmp(void)
{
    if (utmpFile != -1)
        close(utmpFile);
}
