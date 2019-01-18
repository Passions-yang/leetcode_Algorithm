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
/*返回交换过的头结点地址，带出来两个交换元素后一个地址*/
static inline struct ListNode *
swap_two_node(struct ListNode * left,struct ListNode *right,struct ListNode **end){
    if(!left) return NULL;
    if(!right){
        *end = NULL;
        return left;
    }
/*交换动作*/
    *end = right->next;
    right->next = left;
    left->next = *end;
/*返回头*/
    return right;
}
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode * end = NULL;
    struct ListNode *really_head = NULL,*fake_head = NULL,*temp_head= NULL;
    if(!head) return NULL;
 /*获取头，并等待下一次交换*/
   temp_head = really_head = swap_two_node(head,head->next,&end);
/*还有元素*/
    while(end){
        fake_head = swap_two_node(end,end->next,&end);
/*将交换过的头和上一次进行拼接*/
        temp_head->next->next = fake_head;
        temp_head = fake_head;
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
    tail = create_list(&l1,18256);
    print_list(l1);
    l2 = swapPairs(l1);
    print_list(l2);
    return 0;
}


