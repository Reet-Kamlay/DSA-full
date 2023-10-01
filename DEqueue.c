#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *f=NULL;
struct Node *r=NULL;
int isFull(struct Node *r){
    if(r==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct Node *f){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueueF(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(isEmpty(n)){
        printf("queue overflow");
    }
    else{

        if(f==NULL){
            f=r=n;
        }
        else{
            n->data=data;
            n->next=f;
            f->prev=n;
            f=n;

        }
    }
}
void enqueueR(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(isFull(n)){
        printf("queue overflow");
    }
    else{
        n->data=data;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}
int dequeueF(){
    int val=-1;
    struct Node *ptr=f;
    if(isEmpty(f)){
        printf("queue underflow");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int dequeueR(){
    int val=-1;
    struct Node *ptr=r;
    if(isFull(r)){
        printf("queue underflow");
    }
    else{
        r=r->prev;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    enqueueR(12);
    enqueueR(13);
    enqueueR(14);
    LinkedListTraversal(f);
    printf("Dequeing elements:%d\n",dequeueF());
    printf("Dequeing elements:%d\n",dequeueR());
    enqueueF(15);
    enqueueR(16);
    LinkedListTraversal(f);
    return 0;

    
}