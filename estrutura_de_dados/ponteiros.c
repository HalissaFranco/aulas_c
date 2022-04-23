#include <stdio.h>

void calcula(int a, int b, int *p)
{
    /*Função que recebe doi numeros, soma ambos e armazena o 
    resultado no endereço do ponteiro "p" */
    int resultado;
    resultado = a + b;
    /* "*p" é um ponteiro*/
    *p = resultado;
}

int main(void)
{
    /*Variáveis*/
    int a=6, b=2;
    int resultado;

    /*Executamos a função passado dois numeros, e o endereço da 
    variavel "resultado".
    A função é executada e altera o valor registrado no endereço da 
    variavel "resultado" com o valor da soma dos dois números*/
    calcula(a, b, &resultado);
    printf("Soma: %d\n", resultado);

    return 0;
}