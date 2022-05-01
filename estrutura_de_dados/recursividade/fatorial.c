#include <stdio.h>
#include <stdlib.h>

int fatorial(int n)
{
    if(n <= 1)
    {
        return n;
    } else
    {
        return n * fatorial(n-1);
    }
}

int main(void)
{
    int num;
    printf("\nDigite um numero inteiro maior que 0\n");
    scanf("%d", &num);

    printf("\nO fatorial de %d é %d\n", num, fatorial(num));

    return 0;
}