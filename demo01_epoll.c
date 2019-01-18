#include <stdio.h>
#include <sys/epoll.h>

int main(int argc,char *argv[])
{
    int epfd,nfds;
    struct epoll_event ev,events[5];
    epfd = epoll_create(1);
    ev.data.fd = 1;
    ev.events = EPOLLIN;
    epoll_ctl(epfd,EPOLL_CTL_ADD,1,&ev);
    for(;;){
        int i = 0;
        nfds = epoll_wait(epfd,events,5,-1);
        for(i = 0;i < nfds;i++){
            if(events[i].data.fd == 1){
                printf("welcome to epoll's world\n");
            }
        }
    }
    return 0;
}

