#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *prox;
    struct nodo *ant;
}Nodo;

Nodo *fim, *inicio = NULL;
Nodo *penultimo;

Nodo lista[3];

int inserir_lista(int n){
    Nodo *novo, *ant, *atual;
    novo = (Nodo*)malloc(sizeof(Nodo));

    if (novo == NULL) exit(1);
    novo -> info = n;
    novo -> prox  = NULL;

    if(inicio == NULL){
        inicio = novo;
        fim = novo;
        ant = novo;
        penultimo=novo;
    } else{
            penultimo=fim;
            fim -> prox = novo;
            fim = novo;
          }
    return n;
}


void verificar(){
    if(inicio->info!=1){
        lista[0].info=1;
    }

    if(inicio->prox->info!=0){
        lista[1].info=0;
    }

    if(fim->info!=1){
        lista[2].info=1;
    }

    for(int i=0;i<3;i++)printf("%d ",lista[i].info);
}

void listar(){
   Nodo *aux;
   aux=inicio;

   if(aux==NULL){
       printf("Fila vazia\n");
   }else{
         printf("SAIDA:\n");
         printf("\nAntes\n");
         while(aux != NULL){
              printf("%d ", aux->info);
              aux = aux->prox;
         }

    printf("\nDepois\n");
    verificar();

    }
}

void main(){
    lista[0].info=inserir_lista(0);
    lista[1].info=inserir_lista(0);
    lista[2].info=inserir_lista(1);
    listar();
}
