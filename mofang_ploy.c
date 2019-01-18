#include <stdio.h>
#include <stdlib.h>


struct base_vtbl
{
    void (*dance)(void *);
    void (*jump)(void *);
};
/* 基类 */
 struct base
{
    struct base_vtbl *vptr;
};

void base_dance(void *this)
{

    printf("base dance\n");
}

void base_jump(void *this)
{
    printf("base jump\n");

}

struct base_vtbl base_table = {
    base_dance,
    base_jump
};

struct base * new_base(void)
{
    struct base * temp = (struct base *)malloc(sizeof(struct base));
    temp->vptr = &base_table;
    return temp;
}

struct derived
{
    struct base super;
    int high;
};

void derived_dance(void * this)
{
    printf("derice dance\n");

}
void derived_jump(void * this)
{
    struct derived *temp = (struct derived *)this;
    printf("derived jump : %d\n",temp->high);
}

struct base_vtbl derived_table=
{
    derived_dance,
    derived_jump
};

struct derived * new_derived(int h)
{
    struct derived * temp = (struct derived *)malloc(sizeof(struct derived));
    temp->super.vptr = &derived_table;
    temp->high = h;
    return temp;
}


int main(int argc,char *argv[])
{

    struct base * bas = new_base();
    bas->vptr->dance((void *)bas);
    bas->vptr->jump((void *)bas);

 //   struct derived * child = new_derived(10);
    bas = (struct base *)new_derived(10);

    bas->vptr->dance((void *)bas);
    bas->vptr->jump((void *)bas);

    
}

