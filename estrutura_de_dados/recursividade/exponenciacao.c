#include <stdio.h>
#include <stdlib.h>

/*Escrever uma função recursiva que calcule o valor de a elevado a b.*/


int exponenciacao(int a, int b, int tot)
{

    if(b <= 1)
    {
        return tot;
    } else
    {
        return exponenciacao(a, b-1, tot*=a);
    }
}



int main(void)
{
    int a, b, tot;

    printf("====== Exponenciação ======\n");
    printf("Digite a base: ");
    scanf("%d", &a);
    tot = a;
    printf("Digite o expoente: ");
    scanf("%d", &b);

    printf("* O número %d elevado a %d é %d\n", a, b, exponenciacao(a, b, tot));


    return 0;
}