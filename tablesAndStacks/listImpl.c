#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

#include "list.h"

struct Node
{
    ElementType element;
    Position next;
};

void main(int argc, char **argv)
{
    char string[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int lenString = sizeof(string) / sizeof(string[0]);

    struct Node *head, *tail, *node;

    head = malloc(sizeof(struct Node));
    head->element = 'h';
    head->next = NULL;

    tail = NULL;

    node = malloc(sizeof(struct Node));
    head->next = node;

    for (int i = 0; i < lenString; ++i)
    {
        struct Node *tempNode;
        node->element = string[i];
        tempNode = malloc(sizeof(struct Node));
        node -> next = tempNode;
        node = tempNode;
        node->next = tail;
    }

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%c\n", p->element);
    }

    free(head);
    free(node);
}

/* Return true if list is empty */
int isEmpty(List l)
{
    return l->next == NULL;
}

/* Return true if P is the last position in List L */
/* Parameter L is unused in this implement */

int isLast(Position p, List l)
{
    return p->next == NULL;
}

/* Return Position of X in List L; Null if not found */

Position Find(ElementType X, List l)
{
    Position p;

    p = l->next;
    while (p != NULL && p->element != X)
    {
        p = p->next;
    }

    return p;
}

Position FindPrevious(ElementType X, List l)
{
    Position p;

    p = l->next;
    while (p != NULL && p->element != X)
    {
        p = p -> next;
    }

    return --p;
}

void Delete(ElementType X, List l)
{
    Position P, TmpCell;

    P = FindPrevious(X, l);

    if (!isLast(P, l))
    {
        TmpCell = P->next;
        P->next = TmpCell -> next;
        free(TmpCell);
    }
}

/* Insert after legal position P */
/* Header implement assumed */
/* Parameter is unused in this implement */

void Insert(ElementType X, Position P, List L)
{
    Position tempCell;

    tempCell = malloc(sizeof(struct Node));

    if (tempCell == NULL)
    {
        printf("ERROR\n");
        exit(1);
    }

    tempCell->element = X;
    tempCell->next = P->next;
    P->next = tempCell;
}
