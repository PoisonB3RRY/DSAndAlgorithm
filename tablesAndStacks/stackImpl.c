#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef char ElementType;

int IsEmpty(Stack S)
{
    return S->next == NULL;
}

void Push(ElementType element, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = (struct Node *)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        FatalError("Out Of Memory");
    }
    TmpCell->Element = element;
    TmpCell->next = S->next;
    S->next = TmpCell;
}

ElementType Pop(Stack S)
{
    ElementType result;
    PtrToNode firstCell;

    if (S->next == NULL)
    {
        printf("Stack is Empty");
        return 0;
    }

    firstCell = S->next;
    result = firstCell->Element;
    S->next = S->next->next;
    free(firstCell);

    return result;
}

void MakeEmpty(Stack S)
{
    if (S->next == NULL)
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        while (S->next != NULL)
        {
            Pop(S);
        }
    }
}
