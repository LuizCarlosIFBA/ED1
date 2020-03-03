#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CONT 10

typedef struct nodo{
         int info;
         struct nodo *esq,*dir;
          }Arvore;

int contanodo(Arvore*raiz){
    if(raiz != NULL)
return contanodo(raiz->esq) + contanodo(raiz->dir) +1;

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
 if (num < raiz->info){
        raiz->esq = inserir(raiz->esq, num);
 }else if ( num > raiz->info){
         raiz->dir = inserir(raiz->dir, num);
       }else {printf("\nERRO numero repetido\n");
            system("pause");
           }
 
 return(raiz); // retorna a raiz sem mudar
 }
}

void main (){

    Arvore *raiz = NULL;
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 9);
    printf("Direita %d\n",contanodo(raiz->dir));
    printf("Esquerda %d\n",contanodo(raiz->esq));
    system("pause");

}
