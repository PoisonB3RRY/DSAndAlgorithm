#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S); //释放栈
void MakeEmpty(Stack S);
void Enqueue(ElementType X, Stack S);
ElementType Dequeue(Stack S);

#endif /* _Stack_h */

/* Place in implementation file */
/* Stack implementation is a linked list with a header */
struct Node
{
    ElementType Element;
    PtrToNode next;
};
