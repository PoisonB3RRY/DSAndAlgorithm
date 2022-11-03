#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#include "queueArray.h"

int IsEmpty(Queue q)
{
    return q->Size == 0;
}

void MakeEmpty(Queue q)
{
    q->Size = 0;
    q->Front = 1;
    q->Rear = 0;
}

int IsFull(Queue q)
{
    return q->Size == q->Capacity;
}

static int Succ(int Value, Queue q) //增加尾节点，队列满时将尾节点分配到数组头部
{
    if (++Value == q->Capacity)
    {
        Value = 0;
    }
    return Value;
}

void Enqueue(ElementType element, Queue q)
{
    if (IsFull(q))
    {
        printf("Queue is Full \n");
        exit(0);
    }
    q->Size++;
    q->Rear = Succ(q->Rear, q);
    q->Array[q->Rear] = element;
}

Queue CreateQueue(int MaxElements)
{
    Queue q;
    q = (Queue)malloc(sizeof(struct QueueRecord));

    q->Capacity = MaxElements;
    MakeEmpty(q);
    return q;
}

void DisposeQueue(Queue q)
{
    if (q == NULL)
    {
        printf("Queue is not exist\n");
        exit(0);
    }

    free(q->Array);
    free(q);
}

void Dequeue(Queue q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty\n");
        exit(0);
    }

    q->Size--;
    q->Front++;
}

ElementType Front(Queue q)
{
    if (q == NULL)
    {
        printf("Queue is Empty\n");
        exit(0);
    }

    return q->Array[Front];
    
}

ElementType FrontAndDequeue(Queue q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty\n");
        exit(0);
    }

    ElementType result;
    q->Size--;
    result = q->Array[Front];
    q->Front++;
    return result;
}