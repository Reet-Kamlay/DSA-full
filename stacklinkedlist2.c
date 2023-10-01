#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int isFull(struct Node *top){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node *push(struct Node *top,int data){
    if(isFull(top)){
        printf("Stack Overflow");
    }
    else{
        struct Node *n=(struct Node *)malloc(sizeof(struct Node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("Stack Underflow");
    }
    else{
        struct Node *n=*top;
        int x=(*top)->data;
        *top=(*top)->next;
        free(n);
        return x;
    }
}
int peek(int pos){
    struct Node *ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int main(){
    struct Node *top=NULL;
    top=push(top,78);
    top=push(top,85);
    top=push(top,82);
    int value=pop(&top);
    printf("The value of the popped element: %d",value);
    return 0;
}