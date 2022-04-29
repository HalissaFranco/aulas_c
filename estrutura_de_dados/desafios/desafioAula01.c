#include <stdio.h>

int main(void)
{
    int i;
    float resultados[3];
    float tabelaPrecos[2][3] = {{15, 13, 100}, {12.5, 7.5, 97}};

    for(i=0; i<3; i++)
    {
        float preco1 = tabelaPrecos[0][i];
        float preco2 = tabelaPrecos[1][i];

        resultados[i] = (preco1 + preco2)/2;
    }

    for(i=0; i<3; i++)
    {
        printf("%.2f ", resultados[i]);
    }

    printf("\n");

    return 0;
}