#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
int main (int argc,char * argv[])
{
    char lists[21];
    const int src=atoi(argv[1]);
    int dsrc=htons(src);
    if (argc != 2)
    {
        printf("Please make sure your enter:\n");
        exit(1);
    }
    if (( inet_ntop(AF_INET,&dsrc,lists,20)) == NULL)
    {
        perror("inet_ntop");
        exit(1);
    }
    puts(lists);
    return 0;
}
