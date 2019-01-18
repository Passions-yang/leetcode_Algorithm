#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define LOOP    1000

int count;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

void * do_it(void * arg)
{
    int i = 0;
    for(i = 0;i < LOOP;i ++){
        pthread_mutex_lock(&count_mutex);
        count++;
        printf("%x:%d\n",(unsigned int)pthread_self(),count);
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}


int main(int argc,char * argv[])
{
    pthread_t tid_a,tid_b;

    pthread_create(&tid_a,NULL,do_it,NULL);
    pthread_create(&tid_b,NULL,do_it,NULL);
    
    pthread_join(tid_a,NULL);
    pthread_join(tid_b,NULL);
    return 0;
}


