#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle){
    char * p = NULL, *q = NULL;
    char *start = haystack;
    if(!haystack || !needle) return 0;
    if(!*needle) return 0;
    while(*haystack){
        q = needle,p = haystack;
        while(*p == *q && *q) ++p,++q;
        if(*q == '\0') return haystack - start;
        ++haystack;
    }
    return -1;
}

int main(int argc,char *argv[])
{
    int index = strStr("hello","ll");
    printf("index:[%d]\n",index);
    index = strStr("","");
    printf("index:[%d]\n",index);
    index = strStr("mississippi","issip");
    printf("index:[%d]\n",index);
    index = strStr("aaaaa","bba");
    printf("index:[%d]\n",index);
    index = strStr("a","bb");
    printf("index:[%d]\n",index);
    index = strStr("mississippi","issi");
    printf("index:[%d]\n",index);
    index = strStr("a","a");
    printf("index:[%d]\n",index);
    return 0;
}

