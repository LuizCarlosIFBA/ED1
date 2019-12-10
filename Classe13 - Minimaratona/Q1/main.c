#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int info;
    struct nodo *prox;
}Nodo;

Nodo *fim, *inicio=NULL;
Nodo *topo = NULL;

void inserir_fila(int n);
int retirar_fila();
void imprimir();
Nodo *pusher(int n);

int testaVazia(){
   if(topo == NULL) return 1;
   else return 0;
}

Nodo *pusher(int n){
  Nodo *new = (Nodo*) malloc(sizeof(Nodo));
   if(!new) printf("\nSem memória\n\n");
   else{
     new->info=n;
   }
   return new;
}


void inserir(int n){
   Nodo *new = pusher(n);
   new->prox = NULL;
   if(testaVazia()){
      topo= new;
   }else{
        new->prox=topo;
        topo=new;
      }
}

void imprimir_pilha(){
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
      printf("\n");
   }
}


void inserir_fila(int n){
    Nodo *novo;
    novo=(Nodo*)malloc(sizeof(Nodo));
    if(novo==NULL)exit(1);
    novo->info=n;
    novo->prox = NULL;
    if(inicio==NULL){
       inicio=novo;
       fim=novo;
    }else{
           fim->prox = novo;
           fim=novo;
         }
}


void imprimir(){
   int n;
   Nodo *aux;
   aux=inicio;
   if(aux==NULL){
       printf("Fila vazia\n");
   }else{
         printf("Antes de empilhar(normal)\n");
         while(aux != NULL){
              printf("%d ", aux->info);
              aux = aux->prox;
         }

        printf("\nDepois de empilhar(inversa)\n");
        while(inicio!=NULL){
        n=retirar_fila();
        inserir(n);
        }
        imprimir_pilha();

        printf("\n");
   }
}

int retirar_fila(){
    Nodo *aux;
    int n;
    if(inicio==NULL){
        printf("\nFila vazia\n");
        return 0;
    }

    aux=inicio;
    n=aux->info;
    inicio = inicio->prox;
    free(aux);

    return n;
}


int main()
{
      int op;
      int valor_pilha;
      do{
      printf("Escolha uma das opcoes abaixo\n");
      printf("0 -> sair\n");
      printf("1 -> Inserir\n");
      printf("2 -> Imprimir\n");
      printf("Opcao: "); scanf("%d", &op);

      switch(op){
          case 0:
            exit(0);
            break;
         case 1:
           printf("Inserir numero: "); scanf("%d", &valor_pilha);
           inserir_fila(valor_pilha);
            break;
         case 2:
            imprimir();
            break;
         default:
            if(op < 0 || op>2) printf("Escreva um número\n\n");

         }
   }while(op != 0);

   return 0;
}
