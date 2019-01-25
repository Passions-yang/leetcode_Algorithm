#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode * 
insert(struct ListNode **head,struct ListNode * tail,struct ListNode *value);
/* return tail node*/
struct ListNode * 
insert(struct ListNode **head,struct ListNode * tail,struct ListNode *value){
    if(NULL == *head){
        value->next = *head;
        *head = value;
    }else{
        value->next = tail->next;
        tail->next = value;
    }
    return value;
}
/*create single list*/ 
struct ListNode *
create_list(struct ListNode ** head,int num){
    int remainder = 0,consult = 0;
    struct ListNode * tail = NULL;
    struct ListNode * node = NULL;
    do{
        remainder = num % 10;
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = remainder;
        tail = insert(head,tail,node);

    }while(num = num/10);
    
}
static inline struct ListNode * 
head_insert(struct ListNode* head,struct ListNode* node){
    struct ListNode tmp;
    memset(&tmp,0x00,sizeof(tmp));
    struct ListNode *p = &tmp,*q;
    p->next = head;
    q = p;
    while(p->next){
        if(p->next->val > node->val){
            node->next = p->next;
            p->next = node;
            break;
        }
        p = p->next;
    }
    if(!p->next){
        node->next = p->next;
        p->next = node;
    }
    return q->next;
}
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode * p = head,*q = NULL;
    struct ListNode * really_head = NULL;
    if(!head || !head->next) head;
    while(p){
        q = p->next;
        really_head = head_insert(really_head,p);
        p = q;
    }
    return really_head;
}

/*print list*/
void print_list(struct ListNode * head){
    struct ListNode * p = head;
    while(p){
        printf("%d->",p->val);
        p = p->next;
    }
    printf("\n");
}
int main(int argc,char *argv[])
{
    struct ListNode * l1 = NULL, * l2 = NULL,*l3 = NULL;
    struct ListNode * tail = NULL;
    tail = create_list(&l1,468521);
    print_list(l1);
    l2 = insertionSortList(NULL);
    print_list(l2);
    return 0;
}


