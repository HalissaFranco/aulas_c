#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    char valor[10];

    printf("FGETS: Informe um número: ");
    fgets(valor, 9, stdin);
    printf("\nFoi digitado o valor: %s\n", valor);

    printf("%d",atoi(valor)+1);

    printf("Informe um número inteiro: ");
    scanf("%d", &num);
    printf("\nO número informado foi: %d\n", num);
    fflush(stdin);

    return 0;
}