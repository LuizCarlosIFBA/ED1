#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CONT 10

typedef struct nodo{
         int info;
         struct nodo *esq,*dir;
          }Arvore;

typedef struct nodo2{
         int info2;
         struct nodo2 *esq2,*dir2;
          }Arvore2;


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

Arvore2* inserir2( Arvore2* raiz2, int num) {
    // se a arvore esta vazia retorna um unico nodo
 if (raiz2 == NULL) {
     raiz2 =(Arvore2 *)malloc(sizeof(Arvore2));
     if( raiz2 == NULL)exit(1);
     raiz2->info2 =num;
     raiz2->esq2 = NULL;
     raiz2->dir2 = NULL;

 return(raiz2);
 }
 else {
 // senao percorre a arvore recursivamente
 if (num < raiz2->info2) raiz2->esq2 = inserir2(raiz2->esq2, num);
 else if ( num > raiz2->info2) raiz2->dir2 = inserir2(raiz2->dir2, num);
      else {printf("\nERRO numero repetido\n");
            system("pause");}
 return(raiz2); // retorna a raiz sem mudar
 }
}



int contanodo(Arvore*raiz){
    if(raiz != NULL)
return contanodo(raiz->esq) + contanodo(raiz->dir) +1;

}

int contanodo2(Arvore2*raiz2){
    if(raiz2 != NULL)
return contanodo2(raiz2->esq2) + contanodo2(raiz2->dir2) +1;
}

int resultado (int valor, int valor2){

if(valor>valor2)
    return -1;
else if(valor<valor2)
    return 1;
else
    return 0;

}




void main (){

    Arvore *raiz = NULL;
    Arvore2 *raiz2 = NULL;
    raiz = inserir(raiz, 5);
    raiz2 = inserir2(raiz2, 8);


     int valor = contanodo(raiz);
     int valor2 = contanodo2(raiz2);

     printf(" Resultado %d\n",resultado(valor,valor2));
     system("pause");

}