//Joao Luis Chiarelotto Crema

/* ENUNCIADO
Sua  tarefa  será  construir  uma  árvore  binária,  lembrando  que  árvore  binária  são  aquelas  que 
possuem  no  máximo  dois  filhos  em  cada  vértice.  Esta  árvore  será  gerada  de  forma  aleatória  e  deve 
possuir  um  número  de  vértices  aleatoriamente  selecionado  entre  10  e  26  vértices.  Para  criar  esta 
árvore você irá criar um array capaz de armazenar uma quantidade de itens equivalente ao número de 
vértices da árvore que será gerada e preencher estes vértices com valores aleatórios entre 1 e 1000. 
Este array será usado para montar a árvore a árvore binária.  
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
  int num;
  struct arvore* sad; //Sub Arvore Direita
  struct arvore* sae; //Sub Arvore Esquerda
} Arvore;

Arvore* criaArvore() // cria Arvore
{
  return NULL;
}

int arvoreVazia(Arvore* t)
{
  return t == NULL;
}
void mostraArvore(Arvore* t)
{
  
  printf("<");
  if(!arvoreVazia(t))
  {
    
    printf("+%d ", t->num); 
    mostraArvore(t->sae);
    mostraArvore(t->sad);
  }
  printf(">");
}

void insereArvore(Arvore** t, int num)
{
  //insere os elementos de forma recursiva
  if(*t == NULL)
  {
    *t = (Arvore*)malloc(sizeof(Arvore)); 
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  } else {
    if(num < (*t)->num)
    {
      insereArvore(&(*t)->sae, num);
    }
    if(num > (*t)->num)
    {
      insereArvore(&(*t)->sad, num);
    }
  }
}

int achaArvore(Arvore* t, int num) {
  
  if(arvoreVazia(t)) {
    return 0;
  }
  
  return t->num==num || achaArvore(t->sae, num) || achaArvore(t->sad, num);
}

int main()
{
  Arvore* t = criaArvore();
  
  insereArvore(&t, 1);
  insereArvore(&t, 12); 
  insereArvore(&t, 45); 
  insereArvore(&t, 3); 
  insereArvore(&t, 6); 
  mostraArvore(t); 
  
  if(arvoreVazia(t))
  {
    printf("\n\nArvore vazia!!!\n");
  } else {
    printf("\n\nArvore NAO vazia\n");
  }
  
  if(achaArvore(t, 15)) {
    printf("\nO numero 15 pertence a arvore\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore\n");
  }
  
  if(achaArvore(t, 45)) {
    printf("\nO numero 45 pertence a arvore\n\n");
  } else {
     printf("\nO numero 45 NAO pertence a arvore\n\n");
  }
  
  free(t);
  
  return 0;
}