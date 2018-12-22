/*************************************************************************
	> File Name: who1.c
	> Author: 
	> Mail: mZ
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
void printinfo(struct utmp * );
int main (void)
{
    struct utmp info_recieve;
    int fd;
    int reclen = sizeof(info_recieve);
    if ((fd = open(UTMP_FILE,O_RDONLY)) == -1)//打开登录记录
    {
        perror(UTMP_FILE);
        exit(1);
    }
    while ((read(fd,&info_recieve,reclen)) == reclen)//当读入正常时
        printinfo(&info_recieve);

    close(fd);//关闭文件
    return 0;
}
void printinfo(struct utmp * info_print)//显示信息
{
    printf("%s",info_print->ut_user) ;
    printf("  ");
    printf("%s",info_print->ut_line);
    printf("  ");
    printf("%ld",info_print->ut_tv);//显示unix时间，1970年1月1日起
    printf("(%s)",info_print->ut_host);
    putchar('\n');
}
