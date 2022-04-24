#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/*Função que recebe nome, autor e duração e registra os dados na arvore binaria*/

/*Função que pesquisa os dados na arvore binária*/

/*Função menu*/

/*Função voltar*/

/*Estrutura que armazena uma música*/
struct musica{
    char nome[20];
    char autor[20];
    int duracao;
};


/*Main*/
int main(void)
{   

    char opString;
    int op;


    /*Menu*/
    do
    {
        printf("==== PlayList ====\n");
        printf("1) Cadastrar nova musica\n");
        printf("2) Pesquisar uma musica\n");
        printf("3) Exibir todas as musicas\n");
        printf("0) Sair\n");

        opString = getch();//capturar o caractere digitado pelo user
        if(isdigit(opString)!= 0)
        {
            op = atoi(opString);
        }
        else
        {
            op = 4;
        }

        switch (op)
        {
        case 1:
            printf("IMPLEMENTAR CADASTRAR NOVA MUSICA\n\n");
            break;
        case 2:
            printf("IMPLEMENTAR PESQUISAR UMA MUSICA\n\n");
            break;
        case 3:
            printf("IMPLEMENTAR EXIBIR LISTA COMPLETA DE MUSICAS\n\n");
            break;
        case 0:
            printf("Ate mais.\n");
            break;
                        
        default:
            printf("Opcao invalida\n\n");
            break;
        }
    } 
    while (op != 0);
    

    return 0;
}