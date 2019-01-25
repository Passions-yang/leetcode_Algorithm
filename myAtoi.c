#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ×Ö·û´®×ª»»ÕûÊý (atoi) */
int myAtoi(char* str) {
  char * p = str;
  int flag = 1,val = 0,retval = 0;
  while(*p == ' ' || *p == '\t') ++p;
  if(!p) return 0;
  if(*p == '-') {
    flag = -1;
    ++p;
  }else if(*p == '+'){
    flag = 1;
    ++p;
  }
  while(*p != '\0'){
        if(*p < '0' || *p > '9') break;
        val = *p++ - '0';
        if(flag== -1) val = -val;
        if(retval > 214748364 || (retval == 214748364 && val > 7)) return 0x7FFFFFFF; 
        if(retval < -214748364 || (retval == -214748364 && val <-8)) return 0x80000000;        
        retval = retval * 10 + val;
  }
  return retval;
}


int main(int argc,char *argv[])
{

   int val = myAtoi("a");
    printf("a: %d\n",val);
    val = myAtoi("91283472332");
    printf("a: %d\n",val);
    val = myAtoi("-91283472332");
    printf("a: %d\n",val);
    val = myAtoi("321");
    printf("a: %d\n",val);
    val = myAtoi("-");
    printf("a: %d\n",val);
    val = myAtoi("0");
    printf("a: %d\n",val);
    val = myAtoi("2147483648");
    printf("a: %d\n",val);

        val = atoi(" skds  -42");
    printf("a:----- %d\n",val);
        val = atoi("-42 jdsjdfjs");
    printf("a:+++ %d\n",val);
        val = myAtoi("-2147483648");
    printf("a:fdfdfg %d\n",val);
            val = myAtoi("2147483800");
    printf("a: %d\n",val);
    return 0;
}



