/*************************************************************************
	> File Name: cp1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月28日 星期日 10时13分48秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define COPYMODE 0644
#define BUFLEN 16
char * makename(int argc,char * argv[argc]);
int main (int arc,char * arv[])
{
    int fd_open,fd_copy;
    char * copyname;//复制品的名字
    int n_chars,n_writed;
    char bufpool[BUFLEN];

   if (arc != 3) 
    {
        printf("请检查你的参数个数!\n");
        exit(1);
    }
    if ( ( fd_open=open(arv[1],O_RDONLY) ) == -1 )
    {
        printf("打开文件错误!\n");
        exit(1);
    }

   copyname=makename(arc,arv);//得出复制后文件应该得到的名字
    //以及处理交互问题
    if ((fd_copy = creat(arv[2],COPYMODE)) == -1)
    {
        printf("创建文件失败，请检查你的权限!\n");
        exit(1);
    }
    while ((n_chars = read(fd_open,bufpool,BUFLEN)) > 0)
    {
        n_writed=write(fd_copy,bufpool,n_chars);
        if (n_writed != n_chars)
        {
            printf("OPS！严重错误！\n");
            exit(1);
        }
    }
    if (n_chars == -1)
    {
        printf("读取错误!\n");
        exit(1);
    }
    return 0;
}
char * makename(int argc,char * argv[argc])
{
    if (strcmp(argv[2],argv[1]) == 0)//注意哦！
    {
        char answer;
        printf("两者文件名相同,是否继续：（y/n）\n");
        if((answer=getchar()) == 'y')
            return  argv[2];
        else
            exit(1);
    }
    else
        return argv[2];
}
