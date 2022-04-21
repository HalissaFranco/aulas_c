#include <stdio.h>

int main(void){

    /*Declarando uma matriz*/
    int matriz[3][3];
    int i, j, num;

    /*Definindo valores para a matriz*/
    num = 1;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            matriz[i][j] = num;
            num++;
        }
    }

    /*Imprimindo os valores da matriz*/
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("matriz[%d][%d] = %d\n",i, j, matriz[i][j]);
        }
    }

    return 0;
}