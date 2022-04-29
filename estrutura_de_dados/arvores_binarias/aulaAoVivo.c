#include <stdio.h>
#include <stdlib.h>


/* Os nós de uma arvore possuem 3 informações, um numero (num), um ponteiro para a subarvore a esquerda (esq) e um outro ponteiro para subarvore a direita (dir) */

typedef struct arvore
{
  int num;
  struct arvore* esq;
  struct arvore* dir;

}Arv;

/* Criando uma arvore vazia */

Arv* criarArvore()
{

  //Cria uma arvore sem nenhum elemento, retornando um valor nulo
  return NULL;
}

Arv* arvoreVazia(Arv* a)
{
 //Faz o teste e retorna 0 se vazia e 1 se falso
  return a == NULL;
  
}

void mostraArvore(Arv* a)
//mostra os elementos da arvore usando recursao
{
  if(!arvoreVazia(a))//Se arvore não vazia
  {
    printf("%d -",a->num);
    mostraArvore(a->esq);//Mostra arvore a esquerda
    mostraArvore(a->dir);//Mostra arvore a direita
        
  }
  printf("-");
}

void insereDados(Arv** a,int num)
{
  //insere os elementos de forma recursiva
  if(*a == NULL)
  {
    *a = (Arv*)malloc(sizeof(Arv)); //Aloca memoria dinamicamente para a estrutura
    (*a) -> esq = NULL; //subarvore a esq nula
    (*a) -> dir = NULL; //subarvore a dir nula
    (*a) -> num = num; //Armazena o numero
  }else {
    if(num <(*a)->num) //Se o numero for menor irá para esquerda
    {
      insereDados(&(*a)->esq,num);
    }
    if(num > (*a)->num) //Se o numero for maior irá para direita
    {
      /* Percorre pela subárvore à direita */
      insereDados(&(*a)->dir, num);
    }
  }
}

//Função para verificar se o elemento pertence a arvore

int taNaArvore(Arv* a,int num)
{
  if(arvoreVazia(a))
  {
    return 0; //Se a arvore estiver vazia retorna 0
  }
  return a->num == num || taNaArvore(a->esq,num) || taNaArvore(a->dir,num);
}

int main ()
{

  Arv* a = criarArvore(); //Cria uma arvore
  insereDados(&a,15);
  insereDados(&a,9);
  insereDados(&a,2);

  mostraArvore(a);
  
}