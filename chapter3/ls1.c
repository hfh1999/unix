#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>
//code码为1时应该no显示影藏文件！
void list(char dirname[],int code);
int main (int argc,char * argv[])
{
    int HideDot = 1;//隐藏点文件开启
    int opt;
    while((opt=getopt(argc,argv,"a::")) != -1)
    {
        switch (opt)
        {
            case 'a': 
            argv++;
            argc--;//所有参数左移一个
            optind = 1;
            HideDot = 0;//隐藏点文件关闭
            break;
            default : 
            printf("请明确参数！\n");
        }
    }

    if (argc == 1) 
        list(".",HideDot);
    else 
        while (--argc)
        {
            printf("%s:\n",* ++argv);
            list(* argv,HideDot);
        }
    return 0;
}

//code码为1时应该显示影藏文件！
void list(char dirname[],int code)
{
    DIR * dir_ptr;
    struct dirent * direntp;
    if ((dir_ptr = opendir(dirname)) == NULL) 
        printf("ls1:can not open the dir!\n");
    else
    {
        while((direntp = readdir(dir_ptr)) != NULL )
        {
            if (code == 0)
            printf("%s\n",direntp->d_name);
            else if (code == 1)
            {
                if (*(direntp->d_name) != '.')//一旦有.号就不显示
                    printf("%s\n",direntp->d_name);
            }
            else
                printf("Ops!Occur an unexpected error!\n");
        }
        close(dir_ptr);
    }
}
