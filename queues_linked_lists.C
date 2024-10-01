#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct
{
    Node* front;
    Node* rear;
} Queue;

//Function to create an empty queue

Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

//add elements to the queue

void enqueue(Queue* q, int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("Inserted %d\n", value);
}

//Remove elements fron the queue

int dequeue(Queue* q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return item;
}

//Display elements of the queue

void display(Queue* q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue contains: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    return 0;
}