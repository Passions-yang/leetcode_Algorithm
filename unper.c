#include <stdio.h>

int main()
{
	char a[] = "BaSic";
	char b[] = "MinIX";
	int i = 0;
	do{
		a[i] &= 0xDF;
		b[i] |= 0x20;
		++i;
	}while(i < 5);
	printf("%s,%s\n",a,b);
}
