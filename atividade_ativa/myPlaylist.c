#include <stdio.h>
#include <stdlib.h>

/*OK - Função que recebe nome, autor e duração e registra os dados na arvore binaria*/

/*Função excluir música (Se der tempo)*/

/*OK - Função que pesquisa os dados na arvore binária*/

/*Implementar forma de não serem inseridos valores
  duplicados na arvore de busca*/

/*OK - Função menu*/

/*------------------------------------------------------------------------------------*/

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
    printf("Nome da Musica: ");
    fgets(m.nome, 49, stdin);
    printf("Autor: ");
    fgets(m.autor, 49, stdin);
    printf("Duracao: ");
    scanf("%d", &m.duracao);
    scanf("%c");
    scanf("%c");

    return m;
}

/*Imprimi informações de uma musica*/
void imprimirMusica(Musica m)
{
    printf("\n===============================");
    printf("\nNome da Musica: %s", m.nome);
    printf("\nAutor: %s", m.autor);
    printf("\nDuracao: %d", m.duracao);
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
    } else
    {
        inserirMusica(&((*raiz) -> dir), m);
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
        } else {
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
    char opString[20];
    int op, duracao;


    /*Menu*/
    do
    {
        printf("\n==== PlayList ====");
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
            scanf("%d", &duracao);
            scanf("%c");
            scanf("%c");
            busca = pesquisarMusica(raiz, duracao);
            if(busca)
            {
                imprimirMusica(busca -> musica);
            } else 
            {
                printf("\n======================");
                printf("\nMusica não encontrada!");
            }      
            break;

        case 3:
            exibirMusicas(raiz);
            break;

        case 4:
            printf("\nAte mais.");
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