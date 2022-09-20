// Calculate 2 numbers greatest common divisor
#include <stdio.h>

int gcd(int m, int n);

int main(int argc, char const *argv[])
{
    int m = 1989;
    int n = 1590;
    int result = gcd(n, m);
    printf("Greast common divisor of %d and %d is %d\n", m, n, result);

    return 0;
}

int gcd(int m, int n)
{
    int rem; //余数
    if (m < n)
    {
        int temp = m;
        m = n;
        n = temp;
    }

    rem = m % n;

    while (rem != 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }

    return m;
}
