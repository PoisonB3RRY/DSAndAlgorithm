#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;

struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};

typedef PtrToNode Polynomial;

Polynomial polynomialPlus(Polynomial p1, Polynomial p2)
{

    return NULL;
}