#include<stdlib.h>
#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
void printinfo(struct utmp * );
void showtime(long);
int main (void)
{
    struct utmp info_recieve;
    int fd;
    int reclen = sizeof(info_recieve);//输入的缓冲区长度
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
    if ( info_print->ut_type != USER_PROCESS )//确保显示的是登录的用户
        return;
    printf("%s",info_print->ut_user) ;
    printf("  ");
    printf("%s",info_print->ut_line);
    printf("  ");
    showtime(info_print->ut_tv.tv_sec);//显示人类可读的时间
    printf("(%s)",info_print->ut_host);
    putchar('\n');
}
void showtime(long timevalue)
{
    printf("%s",ctime(&timevalue)+4);
}
