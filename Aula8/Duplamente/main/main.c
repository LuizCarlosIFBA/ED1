#include <stdio.h>
#include <stdlib.h>
#include "retirar.h"


void inserir_lista(int n);


void inserir_lista(int n){
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
    } else
          if (n > 0){
            penultimo=fim;
            fim -> prox = novo;
            fim = novo;
    }
    else
        if (n < 0){
            novo -> prox = inicio;
            inicio = novo;
    } else {
        ant = NULL;
        atual = inicio;
        while((atual != NULL)&&(atual->info < 0)){
            ant = atual;
            atual =  atual -> prox;
        }
        if (atual == NULL){
            fim -> prox = novo;
            fim =  novo;
        } else
            if (atual == inicio){
                novo -> prox = atual;
                inicio = novo;
            }
            else{
                ant -> prox = novo;
                novo -> prox = atual;
            }
    }

}

void listar(){
   Nodo *aux;
   aux=inicio;
   if(aux==NULL){
       printf("Fila vazia\n");
   }else{
         printf("SAIDA:\n");
         while(aux != NULL){
              printf(" %d ", aux->info);
              aux = aux->prox;
         }

    printf("\n");

    }
}

void inserir_ordenado(int n){
    Nodo *novo, *ant, *atual;
    novo = (Nodo*)malloc(sizeof(Nodo));

    if(novo==NULL)exit(1);
    novo->info=n;
    if(inicio==NULL){
       inicio=novo;
       novo->prox=NULL;
    }else{ ant = NULL;
           atual=inicio;
           while(atual!=NULL && atual->info<n){
                   ant = atual;
                   atual = atual->prox;
           }

            if (atual == NULL){
            fim -> prox = novo;
            fim =  novo;
        } else
            if (atual == inicio){
                novo -> prox = atual;
                inicio = novo;
            }
            else{
                ant -> prox = novo;
                novo -> prox = atual;
            }
    }


}



void main(){
   int op;
   int valorLista;
   do{
      printf("Escolha uma das opcoes abaixo\n");
      printf("0 -> sair\n");
      printf("1 -> Inserir\n");
      printf("2 -> Remover no inicio\n");
      printf("3 -> Remover no fim\n");
      printf("4 -> Inserir ordenado\n");
      printf("5 -> Listar\n");
      printf("Opcao: "); scanf("%d", &op);

      switch(op){
          case 0:
            exit(0);
            break;
         case 1:
           printf("Insera um numero: ");
           scanf("%d", &valorLista);
           inserir_lista(valorLista);
           break;
        case 2:
           retirarInicio();
           break;
        case 3:
           retirarFim();
           break;
        case 4:
           printf("Insera a um numero: ");
           scanf("%d", &valorLista);
            inserir_ordenado(valorLista);
           break;
        case 5:
           listar();
           break;
         default:
            if(op < 0 || op>5) printf("Escreva um número\n\n");

         }
   }while(op != 0);
}
