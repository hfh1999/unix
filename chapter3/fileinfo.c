#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void showmode( int mode );//以ls格式显示文件mode
void showinfo( char * filename,struct stat * infobuf);//显示文件信息
int main(int argc,char * argv[])
{
    struct stat info;
    if (argc == 1)
        printf("please ensure the filename is entered!\n");
    else
    {
        while(--argc)
        {
            if ( stat( *(++argv),&info) != -1 )
                showinfo(*argv,&info);
            else
            {
                printf("Some errors have occurred!\n");
                exit(1);
            }
        }
    }
    return 0;
}
void showinfo( char * filename,struct stat *  infobuf)
{
    long time;
    printf("   name : %s\n",filename);
    showmode(infobuf->st_mode);//以ls格式显示文件mode
    printf("   links: %d\n",infobuf -> st_nlink);
    printf("   user : %d\n",infobuf -> st_uid);
    printf("   group: %d\n",infobuf -> st_gid);
    printf("   size : %d\n",infobuf -> st_size);
    time = infobuf -> st_mtime;
    printf("modtime : %s\n",ctime(&time));
}
void showmode( int mode )
{
    char str[10 + 1];
    strcpy(str,"----------");//默认是这样的表示，普通文件无权限
    if ( S_ISDIR(mode) ) str[0]='d';
    if ( S_ISCHR(mode) ) str[0]='c';
    if ( S_ISBLK(mode) ) str[0]='b';

    if (mode & S_IRUSR)  str[1]='r';
    if (mode & S_IWUSR)  str[2]='w';
    if (mode & S_IXUSR)  str[3]='x';
    
    if (mode & S_IRGRP)  str[4]='r';
    if (mode & S_IWGRP)  str[5]='w';
    if (mode & S_IXGRP)  str[6]='x';

    if (mode & S_IROTH)  str[7]='r';
    if (mode & S_IWOTH)  str[8]='w';
    if (mode & S_IXOTH)  str[9]='x';

    printf("   mode : %s\n",str);
}

