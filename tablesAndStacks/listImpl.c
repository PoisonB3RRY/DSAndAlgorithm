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
    return L->next == Null;
}

/* Return true if P is the last position in List L */
/* Parameter L is unused in this implement */

int isLast(Position p, List l)
{
    return P->next == null;
}