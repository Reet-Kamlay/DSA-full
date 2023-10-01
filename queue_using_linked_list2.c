#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
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
void enqueue(int data){
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
int dequeue(struct Node *f){
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

int main(){
    LinkedListTraversal(f);
    enqueue(12);
    enqueue(14);
    enqueue(16);
    LinkedListTraversal(f);
    return 0;
}