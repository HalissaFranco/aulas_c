#include <stdio.h>
#include <stdlib.h>

/*Estrutura Pessoa*/
typedef struct{
    char nome[50];
    int cpf;
}Pessoa;


/*Nó da arvore*/
typedef struct no{
    Pessoa pessoa;
    struct no *direita, *esquerda;
}NoDaArvore;

/*Preencher os dados da pessoa e retornar essa pessoa*/
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\tNome: ");
    fgets(p.nome, 49, stdin);
    printf("\tCPF: ");
    scanf("%d", &p.cpf);
    return p;
}

/*Imprimir informações de uma pessoa*/
void imprimir_pessoa(Pessoa p){
    printf("\n\tNome: %s", p.nome);
    printf("\n\tCPF: %d", p.cpf);
}

/*inserir as pessoas na árvore, como otimização, não 
  retornamos mais a raiz, passamos os valores diretamente 
  ao ponteiro "**raiz" informado como parametro*/
void inserir_versao_2(NoDaArvore **raiz, Pessoa p){
    /*Se a raiz for nula, é o primeiro nó que estamos
      inserindo na árvore*/
    if(*raiz == NULL){
        *raiz = malloc(sizeof(NoDaArvore));
        (*raiz) -> pessoa = p;
        (*raiz) -> esquerda = NULL;
        (*raiz) -> direita = NULL;
    /*se o cpf é menor que a raiz*/
    } else if(p.cpf < (*raiz) -> pessoa.cpf){
        /*inserir o número a esquerda*/
        inserir_versao_2(&((*raiz)-> esquerda), p);
    } else {
        /*inserir o número a direita*/
        inserir_versao_2(&((*raiz)-> direita), p);
    }
}

/*Buscar um valor na arvore*/
NoDaArvore* buscar_versao_1(NoDaArvore *raiz, int cpf){
    /*Verifica se a arvore é nula*/
    if(raiz){
        /*Verificar se o cpf procurado é a raiz*/
        if(cpf == raiz -> pessoa.cpf){
            return raiz;
        /*Verificar se o cpf procurado é menor que a raiz*/
        } else if (cpf < raiz -> pessoa.cpf){
            return buscar_versao_1(raiz -> esquerda, cpf);
        } else {
            return buscar_versao_1(raiz -> direita, cpf);
        }
    }
    return NULL;
}


/*Função que imprime nossa arvore*/
void imprimir_versao_1(NoDaArvore *raiz){
    /*Verificar se o nó raiz não é nulo*/
    if(raiz){
        /*Imprimir o nó raiz*/
        imprimir_pessoa(raiz -> pessoa);
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
        imprimir_pessoa(raiz -> pessoa);
        /*Imprime a filha da direita*/
        imprimir_versao_2(raiz -> direita);
    }
}


int main(void){
    /*Ponteiro raiz da arvore*/
    NoDaArvore *busca, *raiz = NULL;

    int op, cpf;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        printf("\t3 - Buscar\n");
        scanf("%d", &op);
        /*Para evitar que o Enter fique preso em op
          e não permita a leitura do nome da pessoa*/
        scanf("%c");
        scanf("%c");

    

        switch(op){
        case 1:
            inserir_versao_2(&raiz, ler_pessoa());
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o cpf a ser procurado: ");
            scanf("%d", &cpf);
            busca = buscar_versao_1(raiz, cpf);
            if(busca){
                printf("\n\tCPF encontrado: \n");
                imprimir_pessoa(busca -> pessoa);
            } else {
                printf("\n\tCPF nao encontrado!");
            }
            break;
        default:
            if(op != 0){
                printf("\n\tOpcao invalida!!\n");
            }
        }

    }while(op != 0);

    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        