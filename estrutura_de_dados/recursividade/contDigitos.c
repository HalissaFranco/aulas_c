#include <stdio.h>
#include <stdlib.h>

/*Crie um programa em Linguagem C que conte os dígitos de um determinado número usando recursão.*/

int contDigitos(int n, int somacasaDecimal)
{

    if(n <= 9){
        return somacasaDecimal+1;
    }
    else{
        somacasaDecimal += 1;

        return contDigitos((n/10), somacasaDecimal);
    }
    
}

int main(void)
{
    int num, total=0;

    printf("Digite um numero inteiro ");
    scanf("%d", &num);

    printf("O numero %d possui %d digito(s)\n", num, contDigitos(num, total));

    return 0;
}