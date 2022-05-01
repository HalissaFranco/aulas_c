#include <stdio.h>
#include <stdlib.h>


/*
    Operações 
    Empilhar: push
    Desempilhar: pop
    Remoção e inserção somente do elemento que está no topo
    
    Tipos:
    1 - LIFO: Last-in-First-out: Ultimo a entrar, primeiro a sair
*/

typedef struct
{
    int dia, mes, ano;
}Data;

typedef struct
{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;    
}No;

Pessoa ler_pessoa()
{
    Pessoa p;

    printf("\nNome:");
    scanf("%s", p.nome);
    printf("\nData de nascimento\nDia: ");
    scanf("%d", &p.data.dia);
    printf("Mes: ");
    scanf("%d", &p.data.mes);
    printf("Ano: ");
    scanf("%d", &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p)
{
    printf("\nNome: %s", p.nome);
    printf("\nData: %2d/%2d/%2d", 
        p.data.dia, p.data.mes, p.data.ano);
}


No* empilhar(No *topo)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo -> p = ler_pessoa();
        novo -> proximo = topo;
        return novo;
    } else
    {
        printf("\nErro ao alocar memória\n");
    }
    return NULL;
}


No* desempilhar(No **topo)
{
    if(*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover -> proximo;
        return remover;
    }else
    {
        printf("\nPilha vazia\n");
        return NULL;
    }
}


void imprimir_pilha(No *topo)
{
    printf("\n======= Inicio Pilha =======\n");
    while(topo)
    {
        imprimir_pessoa(topo -> p);
        topo = topo -> proximo;
    }
    printf("\n======== Fim Pilha  ========\n");

}


int main(void)
{
    No *remover, *topo = NULL;
    int opcao;

    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover)
            {
                printf("\nRemovido com sucesso\n");
                imprimir_pessoa(remover -> p);

            } else
            {
                printf("\nSem no a remover.\n");
            }
            break;
        case 3:
            imprimir_pilha(topo);
            break;
                        
        default:
            if(opcao != 0)
            {
                printf("\nOpcao invalida!!!\n");
            }
            break;
        }

    } while (opcao != 0);

}