#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode1 {
    char ch;
    struct ListNode1 *next;
};
/*如果没有找到，则返回0,否则找到了并返回地址*/
int is_all_unique(struct ListNode1* head,char ch){
    if(!head) return 0;
    struct ListNode1 * p = head;
    while(p){
        if(p->ch == ch){
            return 1;
        }
        p = p->next;
    }
    return 0;
}
struct ListNode1 * remove_list_node(struct ListNode1* head,struct ListNode1** tail){
        if(!head) return NULL;
        struct ListNode1 *p = NULL;
        if(NULL == head->next){
            *tail = NULL;
        }else{
            p = head->next;
            free(head);
            head = p;
        }
        return p;
}
/* return tail node*/
struct ListNode1 * 
insert(struct ListNode1 **head,struct ListNode1 * tail,struct ListNode1 *value){
    if(NULL == *head){
        value->next = *head;
        *head = value;
    }else{
        value->next = tail->next;
        tail->next = value;
    }
    return value;
}
void 
free_ListNode1(struct ListNode1 *head){
    struct ListNode1 * p = head;
    struct ListNode1 * q = NULL;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
}
/********************* method 1 ***********/
/*穷举，暴力破解，将每一个值插入到链表中*/
int lengthOfLongestSubstring1(char* s) {
    char *p = s;
    int i = 0,j = 0;
    int slen = 0;
    int maxlen = 0;
    struct ListNode1 * head = NULL;
    struct ListNode1 * tail = NULL,*node = NULL;
    if(NULL == s || 0 == strlen(s)) return 0;
    slen = strlen(s);
    for(i = 0;i = j -1 ,i < slen; ++i){
        for(j = i;j < slen;++j){
            if(!is_all_unique(head,p[j])){
                node = (struct ListNode1 *)malloc(sizeof(struct ListNode1));
                memset(node,0x00,sizeof(node));
                node->ch = p[j];
                tail = insert(&head,tail,node);
            }else break;
        }
        maxlen = (j-i) > maxlen ? j - i : maxlen;
        free_ListNode1(head);
        head = NULL;
    }
    return maxlen;
}
/*使用 单项链表，滑动窗口解决此问题*/
 int lengthOfLongestSubstring11(char* s) {
    char *p = s;
    int i = 0,j = 0;
    int slen = 0;
    int maxlen = 0,count = 0;;
    struct ListNode1 * head = NULL;
    struct ListNode1 * tail = NULL,*node = NULL;
    if(NULL == s || 0 == strlen(s)) return 0;
    slen = strlen(s);
    while(i < slen && j < slen){
        if(!is_all_unique(head,p[j])){
            node = (struct ListNode1 *)malloc(sizeof(struct ListNode1));
            memset(node,0x00,sizeof(node));
            node->ch = p[j];
            tail = insert(&head,tail,node);
            ++count,++j;
        }else{
            maxlen = j-i > maxlen ? j - i : maxlen;
            head = remove_list_node(head,&tail);
            --count,++i;
        }
    }
    return maxlen > count ? maxlen : count;
 }

 /********************* method 2 ***********/
/*使用数组，滑动窗口的思想 */
int is_all_unique2(char *str,char ch){
    if(NULL == str) return 0;
    while(*str != '\0'){
        if(*str != ch){
            ++str;
        }else
            return 1;
    }
    return 0;
}
void remove_elment(char **str,int index){
    int count = 0,slen = 0;
    slen = strlen(*str);
    count = strlen(*str) - index -1;
    while(count > 0){
        (*str)[index] = (*str)[index+1];
        ++index;
        --count;
    }
    (*str)[slen-1] = 0;
}
int lengthOfLongestSubstring2(char* s) {
    char *p = s;
    int i = 0,j = 0,itmp = 0,count = 0;
    int slen = 0;
    int maxlen = 0;
    char *str = NULL;
    if(NULL == s || 0 == strlen(s)) return 0;
    slen = strlen(s);
    str = (char *)malloc(slen*sizeof(char)+1);
    memset(str,0x00,slen+1);
    while(i < slen && j < slen){
        if(!is_all_unique2(str,p[j])){
                str[j-i] = p[j];
                ++j;
       }else{
            maxlen = j-i > maxlen ? j - i : maxlen;
            remove_elment(&str,0);
            ++i;
       }
    }
    return maxlen > strlen(str) ? maxlen : strlen(str);
}
int lengthOfLongestSubstring21(char* s) {
    char *p = s;
    int i = 0,j = 0,itmp = 0,count = 0;
    int slen = 0;
    int maxlen = 0;
    char *str = NULL;
    if(NULL == s || 0 == strlen(s)) return 0;
    slen = strlen(s);
    str = (char *)malloc(slen*sizeof(char)+1);
    memset(str,0x00,slen+1);
    while(i < slen && j < slen){
        if(is_all_unique2(str,p[j])){
            i = j;
       }
        maxlen = j-i+1 > maxlen ? j - i+1 : maxlen;
        str[j-i] = p[j];
        ++j;
    }
    return maxlen;
}

/********************* method 2 ***********/

int main(int argc,char *argv[])
{
    char * s = "dvdf";
    int len = lengthOfLongestSubstring21(s); 
    printf("maxlen : %d\n",len);


    return 0;
}

/*print list*/
void print_list(struct ListNode1 * head){
    struct ListNode1 * p = head;
    while(p){
        printf("%d->",p->ch);
        p = p->next;
    }
    printf("\n");
}



