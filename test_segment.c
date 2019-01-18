#include <stdio.h>


int main(int argc,char * argv[])
{
    extern char ** environ;
    char buff[64] = {0};
    char *p = NULL;
    int a = 1;
    printf("buff[0] : [ %p]\n",&buff[0]);
    printf("buff[1] : [ %p]\n",&buff[1]);
    printf("buff[1] : [ %p]\n",&buff[2]);
    printf("p : [ %p]\n",&p);
    
    printf("a : [ %p]\n",&a);
    printf("environ : [%p]\n",&environ);
    printf("environ : [%p],environ[1] : %s\n",&environ[1],environ[1]);
    while(a){
        printf("%s [%p]",*environ++,environ++);
        a = 0;
    }
    printf("environ : [%p]",&environ);

    return 0;
}



