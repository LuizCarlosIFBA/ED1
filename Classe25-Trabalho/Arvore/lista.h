#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
    int tVida,prioridade;
    struct nodo *prox;
}Nodo;

Nodo *fim, *inicio=NULL;
int eliminado=0;

void inserir_lista(int t, int p){

    Nodo *novo, *ant, *atual;
    novo = (Nodo*)malloc(sizeof(Nodo));

    if (novo == NULL) exit(1);
    novo->tVida=t;
    novo->prioridade=p;
    novo -> prox  = NULL;

    if(inicio == NULL){
        inicio=novo;
        fim = novo;
        ant = novo;
    } else{
            fim -> prox = novo;
            fim = novo;
    }
}

void dimiuirTLL(int fila){
   Nodo *aux;
   aux=inicio;

   if(fila==1){
      aux->tVida--;
      if(aux->tVida==0){
           free(aux);
           eliminado++;
      }
   }else if(fila==2){
             aux->tVida;
             aux->prox;
             aux->tVida--;
             if(aux->tVida==0){
                free(aux);
                eliminado++;
             }
          }else if(fila==3){
                    aux->tVida;
                    aux->prox;
                    aux->prox;
                    aux->tVida--;
                    if(aux->tVida==0){
                      free(aux);
                      eliminado++;
                    }
                 }else{
                        aux = fim;
                        aux->tVida--;
                        if(aux->tVida==0){
                          free(aux);
                          eliminado++;

                        }
                       }
}

