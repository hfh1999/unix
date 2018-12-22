#include "solve.h"
int solve(char * Stodeal,char * Stostore)//解析路径名
{
      static int bit=0;
      int hello=bit;

      while (Stodeal[bit] != '\0')
      {
          if (Stodeal[bit] == '/')
          {
              strncpy(Stostore,Stodeal+hello,bit+1-hello);//过于绕,简化？
              Stostore[bit+1-hello] = '\0';
              bit++;
              return 1;
          }
          bit++;
      }
      strncpy(Stostore,Stodeal+hello,bit+1-hello);

      static int flag = 0;//第一次遇到‘\0’判断后返回，第二次就返回0
      if (flag)
              return 0;
      else
      {
          if (Stostore[0] == '\0')//若最后为空字符串就返回0，否则返回1
              return 0;
          else
          {
            flag = 1;
            return 1;
          }
      }
}
