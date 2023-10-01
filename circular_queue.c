#include<stdio.h>
#include<stdlib.h>
struct cqueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct cqueue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct cqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct cqueue *q,int val){
    if(isFull(q)){
        printf("queue Overflow");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}
int dequeue(struct cqueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("queue Underflow");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct cqueue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,13);
    printf("Dequeing elements %d\n",dequeue(&q));    
    printf("Dequeing elements %d\n",dequeue(&q));        
    printf("Dequeing elements %d\n",dequeue(&q));
    enqueue(&q,45);    
    enqueue(&q,45);
    enqueue(&q,45);
    if(isFull(&q)){
        printf("Queue is full");
    }
    if(isEmpty(&q)){
        printf("Queue is empty");
    }
    return 0;


}