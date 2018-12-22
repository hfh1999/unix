/*
*给who程序以更多的参数选项
*给的是who am i 可以给出当
*前使用者-。-
*
*
* */
#include<stdlib.h>
#include<stdio.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
#include<pwd.h>
#include<string.h>
void printinfo(struct utmp * );
void printami(void);//如果模式码为1则开启显示who am i？
void showtime(long);
int modejudge(int argc,char * argv[argc]);//判断模式返回模式码
int main (int  arc,char * arv[])
{
    struct utmp info_recieve;
    int fd;
    int mode = 0;//显示模式,即到底有没有am i 选项
    int reclen = sizeof(info_recieve);//输入的缓冲区长度
    if ((fd = open(UTMP_FILE,O_RDONLY)) == -1)//打开登录记录
    {
        perror(UTMP_FILE);
        exit(1);
    }
    
    mode=modejudge(arc,arv);
    if (mode == -1)//根据mode码判断显示和动作
    {
        printf("你要输入的是who am i 吗？\n");
        exit(1);
    }
    else if(mode == -2)
    {
        printf("请检查你的参数选项！\n");
        exit(1);
    }
    else if(mode == 0)
        while ((read(fd,&info_recieve,reclen)) == reclen)//当读入正常时
            printinfo(&info_recieve); 
    else if (mode == 1)
        printami();
    else 
        printf("ops!出现了严重错误!\n");

    close(fd);//关闭文件
    return  0;
}
int modejudge(int argc,char * argv[argc])
{
   int modecode = 0; 
    if (argc == 1)
        return modecode;
    else if(argc == 3)
    {
        if (strcmp(argv[1],"am") == 0 && strcmp(argv[2],"i") == 0)
            return 1;
        else
                return -1;//是3个参数但是却不是已知命令 
    }
    else 
        return -2;//不是3个参数也不是两个
}
void printinfo(struct utmp * info_print)//显示信息
{
    if ( info_print->ut_type != USER_PROCESS )//确保显示的是登录的用户
        return;
    printf("%s  ",info_print->ut_user) ;
    printf("%s  ",info_print->ut_line);
    showtime(info_print->ut_tv.tv_sec);//显示人类可读的时间
}
void printami(void)
{
    int uid;
    struct passwd * pwd;
    uid = geteuid();
    pwd = getpwuid(uid);
    printf("%s",pwd->pw_name);
    putchar('\n');
}
void showtime(long timevalue)
{
    printf("%s",ctime(&timevalue)+4);
}
