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
/*print list*/
void print_list(struct ListNode * head){
    struct ListNode * p = head;
    while(p){
        printf("%d->",p->val);
        p = p->next;
    }
    printf("\n");
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* 
mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL,*tmp = NULL;
    struct ListNode *p = l1,*q = l2;
    if(!(l1 || l2)) return NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    /*如果两个都存在，谁小谁是头，如果两个相等，则取l1*/
    tmp = head = l1->val < l2->val ? l1:l2;
    if(head == l1){
        p = p->next;
    }else{
        q = q->next;
    }
    while(p && q){
        if(p->val < q->val){
            tmp->next = p;
            p = p->next;
            tmp = tmp->next;
        }else{
            tmp->next = q;
            q = q->next;
            tmp = tmp->next;
        }
    }
    if(NULL == p) tmp->next = q;
    if(NULL == q) tmp->next = p;
    return head;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *head = NULL;
    int i = 0;
    for(i = 0;i < listsSize;++i){
        head = mergeTwoLists(lists[i],head);
    }
    return head;
}


int main(int argc,char *argv[])
{
    struct ListNode * l1 = NULL, * l2 = NULL,*l3 = NULL;
    struct ListNode * l4[3];
    struct ListNode * tail = NULL;
    int a = atoi("a");
    printf("a: %d\n",a);
    tail = create_list(&l1,8521);
    print_list(l1);
    tail = create_list(&l2,621);
    print_list(l2);
    tail = create_list(&l3,954);
    print_list(l3);
//    l3 = mergeTwoLists(l1,l2);
//    print_list(l3);
    l4[0] = l1;
    l4[1] = l2;
    l4[2] = l3;
//    tail = mergeKLists(l4,3);
//    print_list(tail);
    return 0;
}


