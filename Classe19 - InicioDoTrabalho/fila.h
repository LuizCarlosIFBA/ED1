#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
/*Nós
*/
typedef struct nodo1{
    int tVida,prioridade;
    struct nodo1 *prox;
}Nodo1;

typedef struct nodo2{
    int tVida,prioridade;
    struct nodo2 *prox;
}Nodo2;

typedef struct nodo3{
    int tVida,prioridade;
    struct nodo3 *prox;
}Nodo3;

typedef struct nodo4{
    int tVida,prioridade;
    struct nodo4 *prox;
}Nodo4;
//

//Início e fim
Nodo1 *fim1, *inicio1=NULL;
Nodo2 *fim2, *inicio2=NULL;
Nodo3 *fim3, *inicio3=NULL;
Nodo4 *fim4, *inicio4=NULL;
//


void inserir_fila1(int t, int p){

    Nodo1 *novo1;
    novo1=(Nodo1*)malloc(sizeof(Nodo1));

    if(novo1==NULL)exit(1);
    novo1->tVida=t;
    novo1->prioridade=p;
    if(inicio1==NULL){
       inicio1=novo1;
       inserir_lista(t,p);
       fim1=novo1;
    }else{
           fim1->prox = novo1;
           fim1=novo1;
           dimiuirTLL(1);
         }

}

void inserir_fila2(int t, int p){
    Nodo2 *novo2;
    novo2=(Nodo2*)malloc(sizeof(Nodo2));
    if(novo2==NULL)exit(1);
    novo2->tVida=t;
    novo2->prioridade=p;
    novo2->prox = NULL;
    if(inicio2==NULL){
       inserir_lista(t,p);
       inicio2=novo2;
       fim2=novo2;
    }else{
           fim2->prox = novo2;
           fim2=novo2;
           dimiuirTLL(2);
         }
}

void inserir_fila3(int t, int p){

    Nodo3 *novo3;
    novo3=(Nodo3*)malloc(sizeof(Nodo3));
    if(novo3==NULL)exit(1);
    novo3->tVida=t;
    novo3->prioridade=p;
    novo3->prox = NULL;
    if(inicio3==NULL){
       inserir_lista(t,p);
       inicio3=novo3;
       fim3=novo3;
    }else{
           fim3->prox = novo3;
           fim3=novo3;
           dimiuirTLL(3);
         }
}

void inserir_fila4(int t, int p){

    Nodo4 *novo4;
    novo4=(Nodo4*)malloc(sizeof(Nodo4));
    if(novo4==NULL)exit(1);
    novo4->tVida=t;
    novo4->prioridade=p;
    novo4->prox = NULL;
    if(inicio4==NULL){
       inserir_lista(t,p);
       inicio4=novo4;
       fim4=novo4;

    }else{
           fim4->prox = novo4;
           fim4=novo4;
           dimiuirTLL(4);
         }
}

void imprimir1(){
   Nodo1 *aux1;
   aux1=inicio1;
   printf(aux1==NULL?"Aplicacao em tempo real:\n Fila vazia\n":"Aplicacao em tempo real:\n");
   while(aux1 != NULL){
         printf("Tempo de vida: %d\n", aux1->tVida);
         printf("Prioridade:  %d\n", aux1->prioridade);
         aux1 = aux1->prox;
   }
   printf("\n");
    //printf("\nTamanho da pilha: %d\n\n", size);
}



void imprimir2(){
   Nodo2 *aux2;
   aux2=inicio2;
   printf(aux2==NULL?"Aplicacoes multimidia:\n Fila vazia\n":"Aplicacoes multimidia:\n");
   while(aux2 != NULL){
         printf("Tempo de vida: %d\n", aux2->tVida);
         printf("Prioridade:  %d\n", aux2->prioridade);
         aux2 = aux2->prox;
   }
   printf("\n");
    //printf("\nTamanho da pilha: %d\n\n", size);
}

void imprimir3(){
   Nodo3 *aux3;
   aux3=inicio3;
   printf(aux3==NULL?"Aplicacoes normais:\n Fila vazia\n":"Aplicacoes normais:\n");
   while(aux3 != NULL){
         printf("Tempo de vida: %d\n", aux3->tVida);
         printf("Prioridade:  %d\n", aux3->prioridade);
         aux3 = aux3->prox;
   }
   printf("\n");
    //printf("\nTamanho da pilha: %d\n\n", size);
}

void imprimir4(){
   Nodo4 *aux4;
   aux4=inicio4;
   printf(aux4==NULL?"Aplicacoes nao prioritarias:\n Fila vazia\n":"Aplicacoes nao prioritarias:\n");
   while(aux4 != NULL){
         printf("Tempo de vida: %d\n", aux4->tVida);
         printf("Prioridade:  %d\n", aux4->prioridade);
         aux4 = aux4->prox;
   }
   printf("\n");
    //printf("\nTamanho da pilha: %d\n\n", size);
}

void filas(){
    printf("-----Lista de espera-----\n");
    imprimir1();
    imprimir2();
    imprimir3();
    imprimir4();
}

void imprimirPacotesIO(){
   printf("Enviados %i \n",3-eliminado);
   printf("Eliminados %i \n \n",eliminado);
   printf("Deseja imprimir filas? 1 - sim, caso contrario digite qualquer numero\n");
   int op;
   scanf("%d",&op);
   if(op==1){
        filas();
   }
}




