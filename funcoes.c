#include <stdio.h>

float soma(float num1, float num2)
{
    return num1 + num2;
}

float subtracao(float num1, float num2)
{
    return num1 - num2;
}

float multiplicacao(float num1, float num2)
{
    return num1 * num2;
}

float divisao(float num1, float num2)
{
    return num1 / num2;
}

int main(void)
{

    float n1 = 10;
    float n2 = 5;

    printf("%.2f + %.2f = %.2f\n", n1, n2, soma(n1, n2));
    printf("%.2f - %.2f = %.2f\n", n1, n2, subtracao(n1, n2));
    printf("%.2f * %.2f = %.2f\n", n1, n2, multiplicacao(n1, n2));
    printf("%.2f / %.2f = %.2f\n", n1, n2, divisao(n1, n2));

    return 0;
}