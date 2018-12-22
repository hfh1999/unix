#include "search.h"
#define INFO_N 30
struct  fileinfo * search(void)
{
    DIR * dirnow;
    struct fileinfo * infobase;
    infobase=malloc(sizeof(struct fileinfo)*INFO_N);

    dirnow=openDIR(".");
    storetoB(dirnow,infobase);//把目录信息暂存

    
}
DIR * openDIR(char * path)
{
    DIR * retdir;
    if((retdir=opendir(path) )!= NULL)
        return retdir;
    else
    {
        perror("open dir");
        exit(1);
    }
}
