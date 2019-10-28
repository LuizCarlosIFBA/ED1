#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


/*
    Essa estrutura serve para
    pegar as infoma��es com o
    info e passar para a pr�xima
    posi��o como *prox
*/
typedef struct nodo{
    int info;
    struct nodo *prox;
}Nodo;

//Inicializa��o do topo
Nodo *topo = NULL;

//Testa de a pilha est� vazia
int testaVazia(){
   if(topo == NULL) return 1;
   else return 0;
}


Nodo *pusher(){
   Nodo *new = (Nodo*) malloc(sizeof(Nodo));
   if(!new) printf("\nSem mem�ria\n\n");
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

void imprimir(){
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





int main(){
   int op;
      do{
      printf("Escolha uma das opcoes abaixo\n");
      printf("0 -> Sair\n");
      printf("1 -> Inserir\n");
      printf("2 -> Remover\n");
      printf("3 -> Imprimir\n");
      printf("Opcao: "); scanf("%d", &op);

      switch(op){
          case 0:
            exit(0);
            break;
         case 1:
            inserir();
            break;
         case 2:
           retirar(); 
           break;
         case 3:
            imprimir();
            break;
         default:
            if(op < 0 || op>4) printf("Escreva um n�mero\n\n");

         }
   }while(op != 0); 
   return -1;
}
