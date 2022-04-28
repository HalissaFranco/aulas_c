#include <stdio.h>
#include <stdlib.h>

/*Nó da arvore*/
typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoDaArvore;

/*Função que retorna o nó para preencher a árvore
  recebe como parametros o nó da árvore, a raiz, e 
  o número que será inserido na árvore*/
NoDaArvore* inserir_versao_1(NoDaArvore *raiz, int num){
    /*Se a raiz for nula, é o primeiro nó que estamos
      inserindo na árvore*/
    if(raiz == NULL){
        /*Criando o primeiro nó e alocando a memória*/
        NoDaArvore *aux = malloc(sizeof(NoDaArvore));
        /*Preenchendo o nó com o valor de num*/
        aux -> valor = num;
        /*Informando ponteiro a esquerda é nulo*/
        aux -> esquerda = NULL;
        /*Informando ponteiro a direita é nulo*/
        aux -> direita = NULL;
        /*Retornando o endereço no nó*/
        return aux;
    } else{
        /*Se a raiz não for nula, temos que verificar
          se o número é menor que a raiz*/
        if(num < raiz -> valor){
            /*Inserindo o número a esquerda*/
            raiz -> esquerda = inserir_versao_1(raiz -> esquerda, num);
        } else {
            /*Inserindo o número a direita*/
            raiz -> direita = inserir_versao_1(raiz -> direita, num);
        }
        return raiz;
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
            raiz = inserir_versao_1(raiz, valor);
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