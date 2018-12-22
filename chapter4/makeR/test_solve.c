#include <stdio.h>
#include <string.h>
#include "solve.h"
int main (void)
{
   char string[256] ;
   printf("Please inputs:\n");
   gets(string);
   
   char output[256];
   while(solve(string,output))
   {
       puts(output);
   }
   return 0;
}
