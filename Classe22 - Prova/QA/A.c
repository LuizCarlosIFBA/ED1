#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
         int info;
         struct nodo *esq,*dir;
}Arvore;


int contRaiz=0;

Arvore *retirar(Arvore* raiz, int num)
{ if (raiz != NULL)
    if (raiz->info == num){
       free(raiz);
       contRaiz++;
    }else {raiz->esq=retirar(raiz->esq,num);
           raiz->dir=retirar(raiz->dir,num);
          }
  return raiz;
}


Arvore* inserir( Arvore* raiz, int num) {
    // se a arvore esta vazia retorna um unico nodo
 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if( raiz == NULL)exit(1);
     raiz->info =num;
     raiz->esq = NULL;
     raiz->dir = NULL;
     
 return(raiz);
 }
 else {
 // senao percorre a arvore recursivamente
 if (num < raiz->info) raiz->esq = inserir(raiz->esq, num);
 else if ( num > raiz->info) raiz->dir = inserir(raiz->dir, num);
      else {printf("\nERRO numero repetido\n");
            system("pause");}
 return(raiz); // retorna a raiz sem mudar
 }


}


void main(){
    Arvore *raiz = NULL;
    raiz = inserir(raiz,1);
    raiz = inserir(raiz,2);
    raiz = inserir(raiz,3);
    retirar(raiz,2);
    printf("Foram/foi eliminada(s) %d sub-arvore(s) \n",contRaiz);
    system("pause");
}
