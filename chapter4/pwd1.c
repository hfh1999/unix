#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define STRLENGTH 51
DIR * getDir(char * dirname);
void printree(void); //递归打印
int name2inode(char *dirtofind);
void inode2name(unsigned long inoderec,DIR * diropened,char * nametostore);
int main (void)
{
  printree();
  putchar('\n');
  return 0;
}
void printree(void) //递归打印
{
    DIR * dirent1,* dirent2;
    unsigned long inode1,inode2;
    char name[STRLENGTH];

    dirent1=getDir(".");
    inode1=name2inode(".");
    chdir("..");
    dirent2=getDir(".");
    inode2name(inode1,dirent2,name);
    inode2=name2inode(".");
    closedir(dirent1);
    closedir(dirent2);

    if (inode1==inode2)
        return;
    else 
    {
        printree();
        printf("/%s",name);
        return;
    }
}
DIR * getDir(char * dirname)
{
    DIR * dirtoret;
    if ((dirtoret=opendir(dirname)) == NULL)//打开目录失败
    {
        printf("Open dir error!!!\n");
        exit(1);
    }
    return dirtoret;
}
//int name2inode(char *dirtofind,DIR * diropened)//返回找到的文件的inode值
//{
//    struct dirent * filelink;//目录里的链接信息 
//    unsigned long inode;
//    while((filelink=readdir(diropened)) != NULL)
//    {
//        if ( strcmp(dirtofind,filelink->d_name) == 0 )//找到了
//        {
//            inode = filelink->d_ino;
//            return inode;
//        }
//    }
//        printf("Error occur!!! read dir Error!!!1\n");
//        exit(1);
//}
int name2inode(char *dirtofind)
{
    struct stat * infodir;
    if ( stat(dirtofind,infodir) == 0 )
        return infodir->st_ino;
    else 
    {
        printf("read stat error!exiting...\n");
        exit(1);
    }
}
void inode2name(unsigned long inoderec,DIR * diropened,char * nametostore)
{
    struct dirent * filelink;
    while ( (filelink=readdir(diropened)) != NULL )
    {
        if (filelink->d_ino == inoderec)
        {
          strcpy(nametostore,filelink->d_name);
          return;
        }
    }
        printf("Error occur!!! read dir Error!!!2\n");
        exit(1);
}
