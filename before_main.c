#include <stdio.h>
#include <stdlib.h>


void init(void)__attribute__((constructor));

void init(void){
    printf("before enter main!\n");
}
void exit_func(void){
    printf("leave main\n");
}

int main(int argc,char *argv[]){
    int *m = (int *)malloc(sizeof(int));
    atexit(exit_func);
    printf("hello world\n");
}


