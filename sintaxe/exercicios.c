#include <stdio.h>

#include <stdlib.h>

/*
Escreva em linguagem C um programa que pede ao utilizador uma sequência de
valores inteiros. O programa começa por pedir ao utilizador para definir o
tamanho da sequência a introduzir. Supondo que n é o tamanho da sequência,
o programa deverá ler do standard input n inteiros. No final, mostra todos
os inteiros positivos que compõem a sequência.    
*/

int main(void)
{
    int *vetor;
    int n, i;

    printf("\nDigite o tamanho da sequencia ");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int)); 



    for(i=0; i<n; i++)
    {
        printf("Digite um numero: ");
        scanf("%d",&vetor[i]);
    }


    for(i=0; i<n; i++)
    {
        if(vetor[i]>=0){
            printf("%d ",vetor[i]);
        }
    }
    printf("\n");
    return 0;
}