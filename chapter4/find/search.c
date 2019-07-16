#include "search.h"
#define INFO_N 30
int main (int argc,char * argv[])
{
    dealpram();          //deal the command
    fFind(places,Fname); //try to find the file

    return 0;
}
void fFind(char place[],char tofind[])
{
    chpath(place);      //change path to the right place

}
