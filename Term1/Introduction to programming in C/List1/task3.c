#include <stdio.h>

unsigned int n;

int fib(unsigned int a, unsigned int b)
{
    if (a == n)
    {
        printf("1");
        n -= a;
        return 0;
    }
    if (a > n)
    {
        return 0;
    }
    fib(a + b, a);
    if (a <= n)
    {
        printf("1");
        n -= a;
        return 0;
    }
    if (a > n)
    {
        printf("0");
        return 0;
    }
    return 0;
}

int main(void)
{
    scanf("%d", &n);
    fib(1, 1);
    return 0;
}