#include <stdio.h>
#include <stdlib.h>

/*Faça uma rotina recursiva para calcular a somatória de todos os número de 1 a N*/

int somatorio(int n)
{
    int soma;

    if(n <= 1)
    {
        return 1;
    } else
    {
        soma = n + somatorio(n-1);
    }
    return soma;
}


int main()
{
    int num;

    printf("Digite um número ");
    scanf("%d", &num);

    printf("\nA soma de 1 até %d é %d\n", num, somatorio(num));

}