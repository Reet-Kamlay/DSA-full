#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(struct Node *f, struct Node *r, int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(n))
    {
        printf("Queue overflow");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = NULL;
            r = n;
        }
    }
}
int dequeue(struct Node *f)
{
    int val = -1;
    struct Node *ptr = f;
    if (isEmpty(f))
    {
        printf("queue underflow");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    struct Node *f = NULL;
    struct Node *r = NULL;
    return 0;
}