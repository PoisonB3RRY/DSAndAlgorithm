/* 栈的数组实现方法 */

#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S); //释放栈
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif /* _Stack_h */

/* Place in implementation file */
/* Stack implementation is a linked list with a header */

#define EmptyEOS -1
#define MinStackSize 5
struct Node
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};
