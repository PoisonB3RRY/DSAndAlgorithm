#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef int ElementType;

struct Node
{
    ElementType element;
    Position next;
};

/* Return true if list is empty */
int isEmpty(List l)
{
    return L->next == NULL;
}

/* Return true if P is the last position in List L */
/* Parameter L is unused in this implement */

int isLast(Position p, List l)
{
    return P->next == NULL;
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