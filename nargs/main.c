// need to record oneline in a mem pool
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#define STDIN 0
#define MAX 100
#define TURNON 0
int main(int argc, char * argv[])
{

    if (argc != 3)
    {
        printf("nargs: need 2 args!\n");
        return 1;
    }
    int linec = 0; // line counter
    //char * execfile = argv[2];
    char * tmp = argv[1];

    int j=0,k=0;
    while(tmp[j] != '\0') j++;
    int sum=0;
    for(k = 0;j > 0;j--,k++)
        sum += (tmp[k] - '0')*pow(10,j-1);


    char pool[MAX+1];
    char oneline[MAX+1];
    char * ch;
    int numin;
    int flag = 1; // a line-num must before the first char of every line
    int counter = 0;
    while(numin = read(STDIN,&pool,MAX))
    {
        pool[numin] = '\0';
        ch = pool;
        while(*ch != '\0')
        {
            if(flag == 1 && TURNON) // when the last char is '\n' ,then print line num
            {
                printf("%d ",linec);
                flag = 0;
            }
            //putchar(*ch);
            if(*ch == '\n')
            {
                oneline[counter] = '\0';
                if(++linec == sum) //search for the wanted line
                {
                    //puts(oneline);
                    execlp(argv[2],argv[2],oneline,NULL); //exec a process
                }
                counter = 0; //reset,record the newest line
                flag = 1;
            }
            else
            {
                oneline[counter] = *ch;
                counter++;
            }
            ch++;
        }

    }
    return 0;
}
