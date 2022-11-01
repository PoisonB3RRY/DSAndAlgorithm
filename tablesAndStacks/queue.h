#ifndef _Queue_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(void);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType e, Queue q); // push element in the rear of the queue
void Dequeue(Queue q);                // pop element from the front of the queue
ElementType Front(Queue q);
ElementType FrontAndDequeue(Queue q);

#endif

struct Node
{
    ElementType element;
    PtrToNode next;
};

struct Queue
{
    PtrToNode front;
    PtrToNode rear;
};
