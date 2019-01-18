#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*父类*/
typedef struct _parent
{
    int data_parent;
    char * name;
    void (*get_data)(void *);
    void (*_delete)(void *);
}Parent;

/*子类*/
typedef struct _child
{
    struct _parent parent;/*必须将此结构体声明在子类最前面*/
    int data_child;
    char * name;
    int age;
}Child;

/*获取父类数据*/
void get_data_Parent (void *this)
{
    struct _parent * temp = (struct _parent *)this;
    temp->name = (char *)malloc(32);
    memset(temp->name,0x00,32);
    memcpy(temp->name,"hello world",strlen("hello world"));
    printf(" parent : %d\n",temp->data_parent);
    printf(" parent : %s\n",temp->name);
}
/*获取子类数据*/
void get_data_Child(void *this)
{
    struct _child * temp = (struct _child *)this;
    temp->name = (char *)malloc(32);
    memset(temp->name,0x00,32);
    memcpy(temp->name,"pengsheng",strlen("pengsheng"));
    temp->data_child = 30;
    temp->age = 27;
    printf("child : %d age : %d\n",temp->data_child,temp->age);
    printf("child : %s\n",temp->name);
}

/*父类析构函数*/
void delete_parent(void * this)
{
    struct _parent * temp = (struct _parent *)this;
    free(temp->name);
    free(temp);
    temp = NULL;
    printf("父类析构函数\n");
}
/*子类析构函数*/
void delete_child(void * this)
{
    struct _child * temp = (struct _child *)this;
    free(temp->name);
    free(temp);
    printf("子类析构函数\n");
    temp = NULL;
}
/*父类构造函数*/
struct _parent * new_Parent(int data)
{
    struct _parent * temp = (struct _parent *)malloc(sizeof(struct _parent));
    temp->data_parent = data;
    temp->get_data = (void (*)(void *))get_data_Parent;
    temp->_delete = (void (*)(void *))delete_parent;
    printf("父类构造函数\n");
    return temp;
}
/*子类构造函数*/
struct _child * new_child(int data)
{
    struct _child * temp = (struct _child *)malloc(sizeof(struct _child));
    temp->data_child = data;
    temp->parent.get_data = (void (*)(void *))get_data_Child;
    temp->parent._delete = (void (*)(void *))delete_child;
    printf("子类构造函数 child : %d\n",temp->data_child);
    return temp;
}

/*测试多态实例*/
int main(int argc,char *argv[])
{
    struct _parent * base = new_Parent(100);
    base->get_data((void *)base);
    base->_delete((void *)base);

    base = (struct _parent *)new_child(80);
    base->get_data((void *)base);
    base->_delete((void *)base);

    return 0;
}

