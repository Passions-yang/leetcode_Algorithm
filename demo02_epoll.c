#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <libgen.h>
#include <assert.h>
#include <string.h>


typedef char bool;
#ifndef false 
#define false 0
#endif /*false*/
#ifndef true
#define true 1
#endif /*true*/

int setnonblocking(int fd)
{
    int new_option = -1;
    int old_option = fcntl(fd,F_GETFL);
    new_option=  old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

void add_fd(int epollfd,int fd,bool enable_et)
{

    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if(enable_et){
        event.events |= EPOLLET;
    }
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setnonblocking(fd);
}

void lt(struct epoll_event * events,int number,int epollfd,int listenfd)
{
    int i = 0;
    char buff[1024] = {0};
    for(i = 0 ; i < number; i ++){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(struct sockaddr_in);
            int connfd = accept(listenfd,(struct sockaddr *)&client_addr,&client_len);
            if(connfd < 0){
                printf("accept err line : %d\n",__LINE__);
                continue;
            }
            add_fd(epollfd, connfd,false);
        }else if(events[i].events & EPOLLIN){
            printf("event trigger once\n");
            memset(buff,0x00,sizeof(buff));
            int ret = recv(sockfd,buff,sizeof(buff)-1,0);
            if(ret < 0){
                if(errno == EINVAL){
                    continue;
                }
                close(sockfd);
                continue;
            }
            printf("get buff : %s,ret : %d\n",buff, ret);

        }else{
            printf("something else happened\n");
        }

    }
}
void et(struct epoll_event * events,int number,int epollfd,int listenfd)
{
    int i = 0;
    char buff[1024];
    for(i < 0;i < number; i++){
        int sockfd = events[i].data.fd;
        if(sockfd == listenfd){
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(struct sockaddr_in);
            int connfd = accept(listenfd,(struct sockaddr *)&client_addr,&client_len);
            if(connfd < 0){
                printf("accept err\n");
                continue;
            }
            add_fd(epollfd,sockfd,true);

        }else if(events[i].events == EPOLLIN){
            printf("event trigger once\n");
            while(1){
                memset(buff,0x00,sizeof(buff));
                int ret = recv(sockfd,buff,sizeof(buff)-1,0);
                if(ret < 0){
                    if(errno == EAGAIN || errno == EWOULDBLOCK){
                        printf("read later\n");
                        break;
                    }
                    close(sockfd);
                    break;
                }else if(ret == 0){
                    close(sockfd);
                }else{
                    printf("get buff : %s,ret : %d\n",buff,ret);
                }
            }
        }else{
                printf("something else happened\n");
        }
    }
}

int main(int argc,char * argv[])
{
    int port = 0;
    if(argc <= 2){
        printf("uage : %s ip_address port_number\n",
            basename(argv[0]));
        return -1;
    }
    const char * ip = argv[1];
    port = atoi(argv[2]);
    int ret = 0;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr);
    address.sin_port = htons(port);

    int listenfd = socket(PF_INET,SOCK_STREAM,0);
    assert(ret != -1);

    ret = listen(listenfd,5);
    assert(ret != -1);

    struct epoll_event events[1024];
    int epollfd = epoll_create(5);

    assert(epollfd != -1);

    add_fd(epollfd,listenfd, true);

    while(1){

        int ret = epoll_wait(epollfd,events,1024,-1);
        if(ret < 0){
            printf("epoll failure\n");
            break;

        }
        lt(events,ret,epollfd,listenfd);
      //  et(events,ret,epollfd,listenfd);
    }
    close(listenfd);
    return 0;
}

