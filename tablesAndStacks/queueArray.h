#ifndef _QueueArray_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType element, Queue q);
ElementType Front(Queue q);
void Dequeue(Queue q);
ElementType FrontAndDequeue(Queue q);

#endif

#define MAX_QUEUE_SIZE 5

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};
