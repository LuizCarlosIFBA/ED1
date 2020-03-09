#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*
    Essa estrutura serve para
    pegar as infomações com o
    info e passar para a próxima
    posição como *prox
*/
typedef struct nodo{
    int info;
    struct nodo *prox;
}Nodo;

//Inicialização do topo
Nodo *topo = NULL;
Nodo *anterior = NULL;
//Testa de a pilha está vazia
int testaVazia(Nodo *pilha){
   if(pilha->prox == NULL) return 1;
   else return 0;
}


Nodo *pusher(){
   Nodo *new = (Nodo*) malloc(sizeof(Nodo));
   if(!new) printf("\nSem memória\n\n");
   else{
       printf("\nEscreva um número: "); scanf("%d", &new->info);
   }
   return new;
}


void inserir(Nodo *pilha){
   Nodo *new = pusher();
   new->prox = NULL;
   if(testaVazia(pilha)){
      pilha->prox = new;
     // size++;
   }else{
      topo = pilha->prox;
      while(topo->prox!= NULL){
         topo = topo->prox;
      }
   topo->prox = new;
   //size++;
   }
}


Nodo *pop(Nodo *pilha){
   if(testaVazia(pilha)){
      printf("\nPilha vazia\n\n");
      return NULL;
   }else{
      Nodo *ultimo = pilha->prox;
      Nodo *antultimo = pilha;

      while(ultimo->prox != NULL){
         antultimo = ultimo;
         ultimo = ultimo->prox;
      }
   antultimo->prox = NULL;
   //size--;
   return ultimo;
   }
}

void Imprimir(Nodo *pilha){
   if(testaVazia(pilha)){
      printf("\n Pilha vazia\n\n");
   }else{
      topo = pilha->prox;
      printf("\n");
      while(topo != NULL){
         printf("%d ", topo->info);
         topo = topo->prox;
      }
      //printf("\nTamanho da pilha: %d\n\n", size);
   }
}





int main(){
   Nodo *pilha = (Nodo*) malloc(sizeof(Nodo));
   inserir(pilha);
   inserir(pilha);
   Imprimir(pilha);
   pop(pilha);
   Imprimir(pilha);

   return 0;
}

/*
void inserir(int n){
    Nodo *novo;
    novo = (Nodo*)malloc(sizeof(Nodo));
    //adicionado
    novo->prox=NULL;
    if(novo==NULL)exit(1);
    novo->info=n;

    if(topo==NULL){
        novo->prox=NULL;
        topo=novo;
    }else{
        topo->info;
        topo=novo;
    }
}
*/
