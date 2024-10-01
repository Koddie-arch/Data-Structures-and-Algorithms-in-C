#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue
{
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create empty queue
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if queue is full
int isFull(Queue* q)
{
    if(q->rear == MAX - 1) return 1;
    return 0;
}

//Check if queue is empty
int isEmpty(Queue* q)
{
    if(q->front == -1) return 1;
    return 0;
}

//Add elements to the queue
void enqueue(Queue* q, int value)
{
    if(isFull(q))
    {
        printf("Queue is full \n");
    }
    else 
    {
        if(q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

//Remove elements from the queue
int dequeue(Queue* q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        return item;
    }
}

//Display elements of the queue
void display(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue contains: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}