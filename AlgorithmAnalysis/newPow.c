#include <stdio.h>
#include <stdbool.h>
long int Pow(int, int);
bool IsEven(int);

void main()
{
    long int result = Pow(2, 10);
    printf("%ld\n", result);
}

long int Pow(int X, int N)
{
    //本算法使用递归处理，基准情况(1)N=0,result=1,(2)N=1,result=X
    //其他情况将分为偶数次幂与奇数次幂
    //(1)偶数：X^N=X^(N/2)*X^(N/2)
    //(2)奇数：X^N=X^((N-1)/2)*X^((N-1)/2)*X

    if (N == 0)
    {
        return 1;
    }
    else if (N == 1)
    {
        return X;
    }
    else if (IsEven(X))
    {
        return Pow(X, N / 2) * Pow(X, N / 2);
    }
    else
    {
        return Pow(X, (N - 1) / 2) * Pow(X, (N - 1) / 2) * X;
    }
}

bool IsEven(int x)
{
    bool evenflag;

    if (x % 2 == 0)
    {
        evenflag = true;
    }
    else
    {
        evenflag = false;
    }
    return evenflag;
}
