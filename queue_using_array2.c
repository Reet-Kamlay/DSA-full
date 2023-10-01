#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue is full.");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is empty.");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,1);
    printf("Dequeuing elements %d\n",dequeue(&q));
    printf("Dequeuing elements %d\n",dequeue(&q));
    printf("Dequeuing elements %d\n",dequeue(&q));
    enqueue(&q,45);
    enqueue(&q,45);
    enqueue(&q,45);
    if(isFull(&q)){
        printf("Queue is Full");
    }
    if(isEmpty(&q)){
        printf("Queue is empty");
    }
    return 0;
}