/*测试利用select来读取两路输入*/
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
#include <stdio.h>
int main(void)
{
	int txt_fd = open("test.txt",O_RDONLY);// 文件流输入
	if (txt_fd < 0) //failed
	{
		exit(1);
	}
	int stdin_fd = STDIN_FILENO; // 标准输入
	fd_set read_set;
	int max_fd = txt_fd + 1;
	FD_ZERO(&read_set);// 清零所有位
	int count;
	char buf1[10];
	char buf2[100];
	bool flag = false;
	while(true)
	{
		FD_SET(txt_fd,&read_set);
		FD_SET(stdin_fd,&read_set);
		select(max_fd,&read_set,NULL,NULL,NULL);// 有输入才返回
		if(FD_ISSET(stdin_fd,&read_set))
		{
			read(stdin_fd,buf1,10);
			printf("read 10 b from std_in.\n");
			for(int count = 0;count < 10;count++)
			{
				if(buf1[count] == '*')
				{
					printf("%c",buf1[count]);
					printf("Meet * and Exit.\n");
					exit(0);
				}
			}
		}
		if(flag == false && FD_ISSET(txt_fd,&read_set))
		{
			if (read(txt_fd,buf2,100) == 0)
			{
				flag = true;// 文件已经读完
				printf("!!! read  TXT finished.\n");
			}
			else{
				printf("!!! read 100 b from TXT.\n");
			}
		}
	}
	return 0;
}
