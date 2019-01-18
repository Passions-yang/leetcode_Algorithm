#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode * 
insert(struct ListNode **head,struct ListNode * tail,struct ListNode *value);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(!(l1 && l2)) return NULL;
    int val = 0;
    int remainder = 0,consult = 0;
    struct ListNode * tail = NULL,*temp = NULL;
    struct ListNode * head = NULL,*node = NULL;
    struct ListNode * p = l1,*q = l2;
    while(l1 && l2){
        val = l1->val + l2->val + consult;
        consult = val/10;//取商
        remainder = val % 10;//取余数
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = remainder;
        tail = insert(&head,tail,node);
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        val = l1->val + consult;
        consult = val/10;//取商
        remainder = val % 10;//取余数
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = remainder;
        tail = insert(&head,tail,node);
        l1 = l1->next;
    }
    while(l2){
        val = l2->val + consult;
        consult = val/10;//取商
        remainder = val % 10;//取余数
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = remainder;
        tail = insert(&head,tail,node);
        l2 = l2->next;
    }
    if(consult){
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = 1;
        tail = insert(&head,tail,node);
    }
    return head;
}
/* 改进算 法后 */
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
    if(!(l1 && l2)) return NULL;
    int val = 0,x = 0,y = 0;
    int remainder = 0,consult = 0;
    struct ListNode * tail = NULL,*temp = NULL;
    struct ListNode * head = NULL,*node = NULL;
    struct ListNode * p = l1,*q = l2;
    while(l1 || l2){
        x = (NULL != l1) ? l1->val:0;
        y = (NULL != l2) ? l2->val:0;
        val = x + y + consult;
        consult = val/10;//取商
        remainder = val % 10;//取余数
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = remainder;
        tail = insert(&head,tail,node);
        if(NULL != l1) l1 = l1->next;
        if(NULL != l2) l2 = l2->next;
    }
    if(consult){
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(node,0x00,sizeof(node));
        node->val = 1;
        tail = insert(&head,tail,node);
    }
    return head;
}


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
    tail = create_list(&l1,18);
    print_list(l1);
    tail = create_list(&l2,0);
    print_list(l2);
    l3 = addTwoNumbers2(l1,l2);
    print_list(l3);
    return 0;
}

