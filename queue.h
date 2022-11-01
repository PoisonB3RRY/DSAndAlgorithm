#ifndef _Queue_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;

int IsEmpty(Queue q);
Queue CreateQueue(void);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Push(ElementType e, Queue q);  //push element in the rear of the queue
void Pop(Queue q);  //pop element from the front of the queue

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

