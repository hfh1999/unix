/*探索shell如何在两个命令之间建立管道*/
/*过程是先exec p1,然后exec p2,将其用管道联系在一起*/
/*注意只有所有的写端文件描述符都关闭才会使得read读到EOF*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
int main(){
    pid_t pid_p1,pid_p2;
    int pipe_fds[2];
    if(pipe(pipe_fds) != 0)
    {
       exit(1);
    }
    if((pid_p2 = fork()) == 0)// 子进程1
    {
        dup2(pipe_fds[0],STDIN_FILENO);// 将标准输入重定向到管道的读取端
        close(pipe_fds[0]);
        close(pipe_fds[1]); // 一定要关闭，因为已经dup过了,否则read的时候不会知道是否已经读完
        execlp("grep","grep","96",(char*)0);
    }
    else if(pid_p2 < 0)
    {
        exit(1);// 生成进程失败
    }

    if((pid_p1 = fork()) == 0) // 子进程2
    {
        dup2(pipe_fds[1],STDOUT_FILENO);//将标准输出重定向到管道写入端 
        close(pipe_fds[0]);
        close(pipe_fds[1]); // 一定要关闭，因为已经dup过了,否则read的时候不会知道是否已经读完
        execlp("cat","cat","test.txt",(char*)0); // exec "cat test.txt"
    }
    else if(pid_p1 < 0)
    {
        exit(1);// 生成进程失败
    }

    // 主进程
    close(pipe_fds[0]);
    close(pipe_fds[1]); // 一定要关闭，主进程不需要管道
    while(wait(NULL)>0); // wait for all processes.
    return 0;
}