/*************************************************************************
	> File Name: who3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月21日 星期日 18时52分04秒
 ************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<utmp.h>
#include<time.h>
#include "who3_func.h"
void showinfo(struct utmp *);
void timetran(long );
int main (void)
{
    struct utmp *  infoTodeal;//接收到的的数据
    openUtmp();
    while ((infoTodeal=getnext()) != (struct utmp * )NULL)//当函数有返回utmp数据时进行显示处理
    //返回的是指针
    {
        if (infoTodeal->ut_type == USER_PROCESS)
        showinfo( infoTodeal);//显示数据
    }
    closeUtmp();
    return 0;
}
void showinfo(struct utmp * ptUtmp)//指向数据的指针
{
    printf("%s    ",ptUtmp->ut_user);//用户名
    printf("%s    ",ptUtmp->ut_line);//终端名
    timetran(ptUtmp->ut_tv.tv_sec);//以人类可读的方式显示时间
    //printf("(%s)",ptUtmp->ut_host);//host名
}
void timetran(long  timeSec)//转换时间的函数
{
    char * timestr;//变化过得时间字符串
    timestr=ctime(&timeSec);
    printf("%s",timestr);
}
