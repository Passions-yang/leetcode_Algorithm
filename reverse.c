#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int x) {
    int retval = 0,remainder = 0;
	int max = 1<<31,min = -1<< 31;
    int _max_cmp = (--max/10),_min_cmp = min/10;
    do{
        remainder = x % 10;
        if(retval > _max_cmp || (retval == _max_cmp && remainder > 7)) return 0;
        if(retval < _min_cmp || (retval == _min_cmp && remainder < -8)) return 0;
        retval = retval * 10 + remainder;
    }while(x = x / 10);
    return retval;
}



int main(int argc,char * argv[])
{
    int val = reverse(1563847412);
    printf("val : %d\n",val);
    return 0;
}


