#include <stdio.h>

int main(void)
{
    /*Declarando um vetor*/
    int vetor[10];
    int i;

    /*Definindo valores para o vetor*/
    for(i=0; i<10; i++)
    {
        vetor[i]=i+1;
    }

    /*Imprimindo os valores do vetor */
    for(i=0; i<10; i++)
    {
        printf("veto[%d]=[%d]\n", i, vetor[i]);
    }

    return 0;
}