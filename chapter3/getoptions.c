/*************************************************************************
	> File Name: getoptions.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月23日 星期五 21时03分05秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main (int argc,char ** argv)
{
    int opt;
    while ((opt = getopt(argc,argv,"-a:b:cde")) != -1)
    {
        switch (opt)
        {
            case 'a':
            printf("hello %s",optarg);
            break;
            case 'b':
            printf("bye %s",optarg);
            break;
            case '?':
            putchar('?');
            default: 
            putchar('H');
            break;
        }
    }
    printf("\n %d",optind);
    return 0;
}
