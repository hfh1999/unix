#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#define STRLEN 61
#define DTYPE 0
#define RTYPE 1
struct fileinfo
{
    char name[STRLEN];
    int type;
};
DIR * openDIR(char * path);
struct fileinfo * search(void);
void storetoB(DIR * dirfile,struct fileinfo * infobase);
