#include <stdio.h>
int main (void)
{
    int c,n;
    n=0;
    while((c=getchar()) != 'Q')
        printf("char %3d is %c code %d\n",n++,c,c);
    return 0;
}
//回显是内核所为么？
