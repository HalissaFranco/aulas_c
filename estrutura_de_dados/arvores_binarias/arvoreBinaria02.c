#include <stdio.h>
#include <stdlib.h>

/*Nó da arvore*/
typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoDaArvore;

/*inserir os números na árvore, como otimização, não 
  retornamos mais a raiz, passamos os valores diretamente 
  ao ponteiro "**raiz" informado como parametro*/
void inserir_versao_2(NoDaArvore **raiz, int num){
    /*Se a raiz for nula, é o primeiro nó que estamos
      inserindo na árvore*/
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoDaArvore));
        (*raiz) -> valor = num;
        (*raiz) -> esquerda = NULL;
        (*raiz) -> direita = NULL;
    /*se o número é menor que a raiz*/
    } else if(num < (*raiz) -> valor){
        /*inserir o número a esquerda*/
        inserir_versao_2(&((*raiz)->esquerda), num);
    } else {
        /*inserir o número a direita*/
        inserir_versao_2(&((*raiz)->direita), num);
    }
}


/*Função que imprime nossa arvore*/
void imprimir_versao_1(NoDaArvore *raiz){
    /*Verificar se o nó raiz não é nulo*/
    if(raiz){
        /*Imprimir o nó raiz*/
        printf("\t%d ", raiz -> valor);
        /*Imprimir a filha da esquerda*/
        imprimir_versao_1(raiz -> esquerda);
        /*Imprimir a filha da direita*/
        imprimir_versao_1(raiz -> direita);
    }
}


/*Função que imprime a arvore do menor para o maior valor*/
void imprimir_versao_2(NoDaArvore *raiz){
    /*Verificar se o nó raiz não é nulo*/
    if(raiz){
        /*Imprimi a filha da esquerda*/
        imprimir_versao_2(raiz -> esquerda);
        /*Imprime o nó da raiz*/
        printf("\t%d ", raiz -> valor);
        /*Imprime a filha da direita*/
        imprimir_versao_2(raiz -> direita);
    }
}


int main(void){
    /*Ponteiro raiz da arvore*/
    NoDaArvore * raiz = NULL;

    int op, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            inserir_versao_2(&raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        default:
            if(op != 0){
                printf("\n\tOpcao invalida!!\n");
            }
        }

    }while(op =! 0);


    return 0;
}