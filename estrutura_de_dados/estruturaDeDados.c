#include <stdio.h>

int main(void)
{
    struct cadastro
    {
        char nome[50];
        int idade, telefone;
    };
    struct cadastro cad;

    printf("Nome: ");
    scanf("%s", cad.nome);
    printf("Idade: ");
    scanf("%d", &cad.idade);
    printf("Telefone: ");
    scanf("%d", &cad.telefone);

    printf("{Nome: %s, Idade: %d, Telefone: %d}\n",
        cad.nome, cad.idade, cad.telefone);

    return 0;
}