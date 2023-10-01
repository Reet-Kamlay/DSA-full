#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Node *top){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node * push(struct Node *top,int x){
    if(isFull(top)){
        printf("stack overflow\n");
    }
    else{
        struct Node *n=(struct Node *)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("stack Underflow\n");
    }
    else{
        struct Node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int main(){
    struct Node *top=NULL;
    top=push(top,78);
    top=push(top,7);
    top=push(top,8);
    int value=pop(&top);
    printf("Te popped element is: %d",value);
    return 0;
}