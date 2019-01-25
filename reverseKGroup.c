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
/*
*   �˺������Ǳ���õ�����ֵ��
*   1.���ص���ת���ͷ��㣬return����
*   2.��ȡ��ת�����һ���ڵ㡣
*/
static inline  struct ListNode * 
head_insert_method(struct ListNode *head,int k,struct ListNode **tail){
    struct ListNode q,*p = &q,*tmp = NULL;
    memset(&q,0x00,sizeof(struct ListNode));
    *tail = p->next = head;
    while(k-- > 0){
        tmp = head->next;
        head->next = p->next;
        p->next = head;
        head = tmp;
    }
    return p->next;
}
/*
*   ��ȡ������ת�����һ���ڵ�
*/
static inline struct ListNode *
is_reverse(struct ListNode *head,int k){
   while(head && k > 0){
        head = head->next;
        --k;
   } 
   return head;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode * pre = head,*tail = NULL,*last_tail = NULL;
    struct ListNode *tmp = NULL,*next = NULL;
    struct ListNode p;
    pre = last_tail = &p;
    //��ȡ������ת����ת��Ա�����һ������
    while(tail = is_reverse(head,k-1)){
        next = tail->next;//��¼��ת��һ���ڵ�
        /*������ת,headΪ��ת���ͷ��tmpλ��ת���β */
        head = head_insert_method(head,k,&tmp);
        tmp->next = next;
        last_tail->next = head;//ʹ��last_tail��¼��һ�δ�������β���ֵ
        last_tail = tmp;//�ƶ�last_tail��ֵ
        head = next;//����������Ҫ��ת��ֵ��
    }
    //��������û�н���ѭ��������k = 1��
    if(NULL == last_tail->next && NULL == pre->next) pre->next = head;
    return pre->next;
}

int main(int argc,char *argv[])
{
    struct ListNode * l1 = NULL, * l2 = NULL,*l3 = NULL;
    struct ListNode * tail = NULL;
    tail = create_list(&l1,8542100);
    print_list(l1);
    tail = create_list(&l2,1);
    print_list(l2);
    l3 = reverseKGroup(l1,1);
    print_list(l3);
    return 0;
}


