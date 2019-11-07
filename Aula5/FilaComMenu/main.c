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

Nodo *fim, *inicio=NULL;
Nodo *topo = NULL;

void inserir_fila(int n);
int retirar_fila();
void imprimir();
Nodo *pusher(int n);
//Pilha
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
     // size++;
   }else{
        new->prox=topo;
        topo=new;
      }
   //size++;
}
   //size++;

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
      //printf("\nTamanho da pilha: %d\n\n", size);
   }
}

//

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
   //printf(aux==NULL?"Fila vazia\n":"Os elementos sao:\n");
   if(aux==NULL){
       printf("Fila vazia\n");
   }else{
         printf("Antes de empilhar\n");
         while(aux != NULL){
              printf("%d ", aux->info);
              aux = aux->prox;
         }

        printf("\nDepois de empilhar\n");
        while(inicio!=NULL){
        n=retirar_fila();
        inserir(n);
        }
        imprimir_pilha();

        printf("\n");
    //printf("\nTamanho da pilha: %d\n\n", size);
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
      printf("2 -> Remover\n");
      printf("3 -> Imprimir\n");
      printf("Opcao: "); scanf("%d", &op);

      switch(op){
          case 0:
            exit(0);
            break;
         case 1:
           printf("Inseri a um numero: "); scanf("%d", &valor_pilha);
           inserir_fila(valor_pilha);
            break;
         case 2:
           retirar_fila();
           break;
         case 3:
            imprimir();
            break;
         default:
            if(op < 0 || op>4) printf("Escreva um número\n\n");

         }
   }while(op != 0);
     /*
    inserir_fila(5);
    inserir_fila(8);
    imprimir();
    retirar_fila();
    imprimir();*/
    return 0;
}
