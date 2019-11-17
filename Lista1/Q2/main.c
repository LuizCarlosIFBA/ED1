#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
int vetor_fila[MAX];

int inicio1=0;
int fim1=49;

int inicio2=99;
int fim2=50;

typedef struct nodo{
    int info;
    struct nodo *prox;
}Nodo;

Nodo *fim, *inicio=NULL;

void inserir_fila(int n);
int retirar_fila();
void imprimir();


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
   Nodo *aux;
   aux=inicio;
   printf(aux==NULL?"Fila vazia\n":"\nOs elementos apos a insercao da fila dinamica sao:\n");
   while(aux != NULL){
         printf("%d ", aux->info);
         aux = aux->prox;
   }
   printf("\n");
    //printf("\nTamanho da pilha: %d\n\n", size);
}

void inserir(){
    srand(time(NULL) );

    //Fila 1
    for(int i=0;i<50;i++){
       vetor_fila[i]=(rand()%9)+1;
    }

    //Fila 2
    for(int j=99;49<j;j--){
       vetor_fila[j]=(rand()%9)+1;
    }
}

int main()
{
    inserir();
    printf("\nFila 1\n");
    for(int i=0;i<50;i++)printf("%d ",vetor_fila[i]);

    //Fila 2
    printf("\nFila 2\n");
    for(int j=99;49<j;j--)printf("%d ",vetor_fila[j]);

    for(int y=0;y<99;y++){
        inserir_fila(vetor_fila[y]);
    }
    imprimir();

    return 0;
}
