#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <ctype.h>


typedef struct nodoArvore{
         int info;
         struct nodo *esq,*dir;
}Arvore;

Arvore* inserir( Arvore* raiz,int num) {

 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if( raiz == NULL)exit(1);
     raiz->info =num;
     raiz->esq = NULL;
     raiz->dir = NULL;
 return(raiz); // retorna a raiz sem mudar
 }
}

Arvore *raiz = NULL;
void add(int num){
  raiz = inserir(raiz, num);
}


void escolha(int t, int p){

 add(6);

 if (p<=raiz->info){
    if(p<=3){
        inserir_fila1(t,p);//Aplicaçoes de tempo real
    }else inserir_fila2(t,p);//Aplicaçoes multimidia
 }else if(t>7){
            inserir_fila4(t,p);//Aplicações não prioritárias
        }else inserir_fila3(t,p);//Aplicações normais

}
