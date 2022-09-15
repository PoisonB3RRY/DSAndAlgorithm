#include <stdio.h>
#include <stdlib.h>

void PrintDigit(int);
void PrintOut(unsigned int);

void main()
{
    PrintDigit(-32454);
}

void PrintDigit(int N)
{
    if(N<0)
    {
        N=N*-1;
        printf("-");
        PrintOut(N);
    }
    else
    {
        PrintOut(N);
    }
    printf("\n");
}

void PrintOut(unsigned int input)
{
    if(input >= 10)
    {
        PrintOut(input / 10);
    }
    printf("%d", input % 10);
}
