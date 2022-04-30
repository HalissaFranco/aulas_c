#include <stdio.h>
#include <stdlib.h>


/*Estrutura que armazena uma musica*/
typedef struct
{
    char nome[50];
    char autor[50];
    int duracao;
}Musica;

/*No da arvore*/
typedef struct no
{
    Musica musica;
    struct no *dir, *esq;
}NoDaArvore;

/*Recebe os dados de uma musica*/
Musica lerMusica()
{
    Musica m;
    char auxDuracao[20];

    printf("Duracao: ");
    fgets(auxDuracao, 19, stdin);

    if(atoi(auxDuracao) > 0)
    {   
        m.duracao = atoi(auxDuracao);
        printf("Nome da Musica: ");
        fgets(m.nome, 49, stdin);
        printf("Autor: ");
        fgets(m.autor, 49, stdin);
        return m;
    } else
    {
        printf("Duracao invalida ...\n");
        return lerMusica();
    }
}

/*Imprimi informações de uma musica*/
void imprimirMusica(Musica m)
{
    printf("\n===============================");
    printf("\nNome da Musica: %s", m.nome);
    printf("Autor: %s", m.autor);
    printf("Duracao: %d", m.duracao);
}

/*Inserir os dados das musicas na arvore*/
void inserirMusica(NoDaArvore **raiz, Musica m)
{
    if(*raiz == NULL)
    {
        *raiz = malloc(sizeof(NoDaArvore));
        (*raiz) -> musica = m;
        (*raiz) -> esq = NULL;
        (*raiz) -> dir = NULL;
    } else if (m.duracao < (*raiz) -> musica.duracao)
    {
        inserirMusica(&((*raiz) -> esq), m);
    } else if (m.duracao > (*raiz) -> musica.duracao)
    {
        inserirMusica(&((*raiz) -> dir), m);
    } else
    {
        printf("\nJa foi inserida uma musica com esta duracao ...");
        printf("\nTente novamente ...");
    }
}

/*Buscar uma musica na arvore*/
NoDaArvore* pesquisarMusica(NoDaArvore *raiz, int duracao)
{
    if(raiz)
    {
        if(duracao == raiz -> musica.duracao)
        {
            return raiz;
        } else if (duracao < raiz -> musica.duracao)
        {
            return pesquisarMusica(raiz -> esq, duracao);
        } else
        {
            return pesquisarMusica(raiz -> dir, duracao);
        }
    }
    return NULL;
}

/*Imprimi a lista de músicas cadastrar no sistema*/
void exibirMusicas(NoDaArvore *raiz)
{
    if(raiz)
    {
        exibirMusicas(raiz -> esq);
        imprimirMusica(raiz -> musica);
        exibirMusicas(raiz -> dir);
    }
}

/*Main*/
int main(void)
{   
    NoDaArvore *busca, *raiz = NULL;
    char opString[20], auxDuracao[20];
    int op, duracao;

    /*Menu*/
    do
    {
        printf("\n===== PlayList =====");
        printf("\n1) Cadastrar nova musica");
        printf("\n2) Pesquisar uma musica");
        printf("\n3) Exibir todas as musicas");
        printf("\n4) Sair\n");
        fgets(opString, 19, stdin);

        op = atoi(opString);

        switch (op)
        {
        case 1:
            inserirMusica(&raiz, lerMusica());
            break;

        case 2:
            printf("\nDigite a duracao da musica: ");
            fgets(auxDuracao, 19, stdin);

            if(atoi(auxDuracao) > 0)
            {   
                duracao = atoi(auxDuracao);

                busca = pesquisarMusica(raiz, duracao);
                if(busca)
                {
                    imprimirMusica(busca -> musica);
                } else 
                {
                    printf("\n======================");
                    printf("\nMusica nao encontrada!");
                }   
            } else
            {
                printf("Duracao invalida ...\n");
            }   
            break;

        case 3:
            exibirMusicas(raiz);
            break;

        case 4:
            printf("\nAte mais.\n\n");
            break;

        default:
            printf("\n======================");
            printf("\nOpcao invalida!\n\n");
            break;
        }
    } 
    while (op != 4);
    
    return 0;
}