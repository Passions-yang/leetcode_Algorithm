#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ×Ö·û´®×ª»»ÕûÊý (atoi) */
int myAtoi(char* str) {
  char * p = str;
  int flag = 1,val = 0,retval = 0;
  int max = 1<<31,min = -1<< 31;
  int _max_cmp = (--max/10),_min_cmp = min/10;
  if(!p) return 0;
  if(*p == '-') {
    flag = -1;
    ++p;
  }else if(*p == '-'){
    flag = 1;
    ++p;
  }
  while(*p != '\0'){
        if(*p < '0' ||
            *p > '9')
            return 0;
        val = *p - '0';
         if(retval > _max_cmp &&
            *(p+1) != '\0' &&
            -1 == flag || 
            (retval == _max_cmp &&
              val > 8 )){
                return 0x80000000; 
         }
        if((retval > _max_cmp &&
            *(p+1) != '\0' &&
            1 == flag )|| 
            (retval == _max_cmp &&
            val > 7)){
            return 0x7FFFFFFF;
         }        
        retval = retval * 10 + val;
        ++p;
  }
  return flag == -1 ? -retval:retval;
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
    val = myAtoi("-42");
    printf("a: %d\n",val);
    return 0;
}



