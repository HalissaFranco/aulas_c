/*
    Crie um programa em C que pergunta o nome e a renda,
    calculando o imposto e apresentando o resultado para 
    o usuário alicota 27%
*/
#include <stdio.h>

int main(void)
{
    struct cadastro
    {
        char nome[50];
        float renda;
    };
    struct cadastro cad;

    printf("Nome: ");
    scanf("%s", cad.nome);
    printf("Renda: ");
    scanf("%f", &cad.renda);

    printf("{Nome: %s, Renda: %.2f}\n",
        cad.nome, cad.renda);

    float imposto = cad.renda * 0.275;

    printf("Imposto a ser pago: %.2f\n", imposto);

    return 0;
    
}
