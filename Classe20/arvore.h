#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct nodo{
         int info;
         struct nodo *esq,*dir;
          }Arvore;


Arvore* inserir( Arvore* raiz, int num) {
    // se a arvore esta vazia retorna um unico nodo
 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if( raiz == NULL)exit(1);
     raiz->info = num;
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

Arvore* contar( Arvore* raiz){
    
    if( raiz == NULL) return 0;

        return(contar(raiz->esq)+ contar(raiz->dir)+1);
    }