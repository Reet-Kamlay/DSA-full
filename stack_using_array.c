#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int value)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return value;
    }
}
int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 80;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Before pushing, Full: %d\n",isFull(sp));
    printf("Before pushing, Empty: %d\n",isEmpty(sp));
    push(sp,1);
    push(sp,23);
    push(sp,99);
    push(sp,75);
    push(sp,3);
    push(sp,64);
    push(sp,57);
    push(sp,46);
    push(sp,89);
    push(sp,6);
    printf("After pushing, Full: %d\n",isFull(sp));
    printf("After pushing, Empty: %d\n",isEmpty(sp));
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    printf("popped %d from the stack\n",pop(sp));
    for (int j = 0; j <= sp->top + 1; j++)
    {
        printf("The value at index %d is %d\n", j, peek(sp, j));
    }
    return 0;
}