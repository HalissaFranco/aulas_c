#include <stdio.h>

/*Função que recebe nome, autor e duração e registra os dados na arvore binaria*/

/*Função que pesquisa os dados na arvore binária*/

/*Função menu*/

/*Função voltar*/


int main(void)
{   
    /*Estrutura que armazena uma música*/
    struct musica{
        char nome[20];
        char autor[20];
        int duracao;
    };

    int op;


    /*Menu*/
    do
    {
        printf("==== PlayList ====\n");
        printf("1) Cadastrar nova música\n");
        printf("2) Pesquisar uma música\n");
        printf("3) Exibir todas as músicas\n");
        printf("0) Sair\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("IMPLEMENTAR CADASTRAR NOVA MÚSICA\n\n");
            break;
        case 2:
            printf("IMPLEMENTAR PESQUISAR UMA MÚSICA\n\n");
            break;
        case 3:
            printf("IMPLEMENTAR EXIBIR LISTA COMPLETA DE MÚSICAS\n\n");
            break;
        case 0:
            printf("Até mais.\n");
            break;
                        
        default:
            printf("Opção inválida\n\n");
            break;
        }
    } 
    while (op != 0);
    

    return 0;
}