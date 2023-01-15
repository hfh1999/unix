/*************************************************************************
	> File Name: tail1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年10月28日 星期日 15时48分56秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#define BUFLEN 1024
#define LINELEN 256 
int countLine(int);
void echoAll(int);
void echo10(int);
int search(char buf[BUFLEN],int Nsearch);
int main (int arc,char * arv[])
{
    int fd_open;
    int n_line;//文件的行数
    if ((fd_open = open(arv[1],O_RDONLY)) == -1)
    {
        printf("tail:文件不存在！\n");
        exit(1);
    }
    //n_line = countLine(fd_open);//数文件有多少行
    n_line = 5;//数文件有多少行
    if (n_line <= 10)
        echoAll(fd_open);//显示文件的所有
    else 
        echo10(fd_open);//显示末尾10行
    return 0;
}
//int countLine(int fdRec)
//{
//    int sum = 0;//初始的\n符号数目为0
//    int Nkeep = 0;
//    int Nread;
//    while (Nread=read(fdRec,bufpool,BUFLEN))
//    {
//        if (Nread < 0 )
//        {
//            printf("Ops!");
//            exit(1);
//        }
//        else
//            Nkeep = Nread;
//        enterFind = search(bufpool,Nkeep);//在缓冲区的前nkeep字节中搜寻\n
//        sum += enterFind;
//        Nkeep = 0;
//    }
//    return sum+1;
//}
//int search(char buf[BUFLEN],Nsearch)
//{
//    int num;
//    char * chptr = buf;
//    for (num = 0;chptr-buf < Nsearch;chptr++)
//        if (*chptr == '\n')
//            num++;
//    return num;//返回最终的计数结果
//}
void echoAll(int fdEcho)
{
    char buf[BUFLEN];
    char echobuf[LINELEN];
    int Nread;
    char * bufptr;
    lseek(fdEcho,0,SEEK_SET);//移到文件头
    while (Nread = read(fdEcho,buf,BUFLEN))
    {
        int i = 0;
        while(bufptr - buf<Nread)
        {
            *(echobuf+i)=*bufptr;
            if (*bufptr == '\n')//一旦一行结束立即创建一个字符串
            {
               *(echobuf+i+1) = '\0';
                puts(echobuf);//显示这个字符串
                i = -1;//重新覆盖echobuf
            }
            bufptr++;
            i++;
        }
        *(echobuf+i)='\0';
        puts(echobuf);
    }
}
void echo10(int fdEcho )
{

}
