#include <stdio.h>

int main(void)
{
    int i, j;
    /*Declaração de vetor direta*/
    int vetor[3] = {1, 2, 3};

    /*Declaração matriz direta*/
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    /*Imprimindo os valores do Vetor*/
    printf("Vetor\n");
    for(i=0; i<3; i++)
    {
        printf("[%d] = %d\n", i, vetor[i]);
    }

    /*Imprimindo os valores da matriz*/
    printf("\n\nMatriz\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("[%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }
    
    return 0;
}