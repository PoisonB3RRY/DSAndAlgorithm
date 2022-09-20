#include <stdio.h>

int findMid(const int ElementArray[], int target, int N);

void main()
{
    int array[] = {1,
                   2,
                   3,
                   4,
                   5,
                   6};
    int target = 7;
    int N = sizeof(array) / sizeof(int);
    printf("array size: %d\n", N);
    int result = findMid(array, target, N);
    printf("result is %d\n", result);
}

int findMid(const int ElementArray[], int X, int N)
{
    int Low, Mid, High;

    High = N - 1;
    Low = 0;
    Mid = (High - Low) / 2;
    while (Low <= High)
    {
        if (ElementArray[Mid] > X)
        {
            High = Mid - 1;
            printf("High = %d\n", High);
            Mid = (High - Low) / 2;
        }
        else if (ElementArray[Mid] < X)
        {
            Low = Mid + 1;
            printf("Low = %d\n", Low);
            Mid = Low + (High - Low) / 2;
        }
        else
        {
            return Mid;
        }
    }
    return -1;
}