#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverseString(char* s, int sSize) {
    char ch;
    int i = 0;
    if(!s) return;
    while(i < (sSize>>1) && '\0' != *s){
        ch = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = ch;
        ++i;
    }
}


int main(int argc,char * argv[])
{
    int n = 0;
    char buff[23] = "hellod";
 //   printf("%s\n%n",buff,&n);
    reverseString(buff,strlen(buff));
    printf("%s\n%n",buff,&n);
    return 0;
}
