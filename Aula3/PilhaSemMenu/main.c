#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


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

//Testa de a pilha está vazia
int testaVazia(){
   if(topo == NULL) return 1;
   else return 0;
}


Nodo *pusher(){
   Nodo *new = (Nodo*) malloc(sizeof(Nodo));
   if(!new) printf("\nSem memória\n\n");
   else{
       printf("\nEscreva um numero: "); scanf("%d", &new->info);
   }
   return new;
}


void inserir(){
   Nodo *new = pusher();
   new->prox = NULL;
   if(testaVazia()){
      topo= new;
     // size++;
   }else{
        new->prox=topo;
        topo=new;
      }
   //size++;
   }



int retirar(){
    Nodo *aux;
    int n;
    if(topo==NULL){
        printf("Pilha vazia");
        return 0;
    }

    aux=topo;
    n=aux->info;
    topo = topo->prox;
    free(aux);
    return n;
}

void Imprimir(){
   Nodo *aux;
   if(testaVazia()){
      printf("\n Pilha vazia\n\n");
      return ;
   }else{
      aux=topo;
      printf("\n");
      while(aux != NULL){
         printf("%d ", aux->info);
         aux = aux->prox;
      }
      //printf("\nTamanho da pilha: %d\n\n", size);
   }
}





int main(){
   inserir();
   inserir();
   Imprimir();
   retirar();
   Imprimir();

   return -1;
}
