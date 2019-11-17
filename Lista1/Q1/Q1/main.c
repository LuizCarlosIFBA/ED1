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

void remover(){
    int confirmar =1;
    int fila;
    while(confirmar==1){
    printf("\nDeseja remover algum valor? Sim -1 Nao - Qualquer numero ");scanf("%d",&confirmar);

    printf("\nPara remover a fila 1 digite - 1, para a fila 2 digite qualquer numero ");
    scanf("%i",&fila);

    if(fila==1){
       vetor_fila[fim1]=0;
       fim1--;
    }else{
       vetor_fila[fim2]=0;
       fim2++;
    }

    printf("Deseja remover outro valor? Sim -1 Nao - Qualquer numero ");scanf("%d",&confirmar);

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

    printf("inserido com sucesso!");
}

int main()
{
    inserir();
    printf("\nFila 1\n");
    for(int i=0;i<50;i++)printf("%d ",vetor_fila[i]);

    //Fila 2
    printf("\nFila 2\n");
    for(int j=99;49<j;j--)printf("%d ",vetor_fila[j]);

    remover();

    for(int y=0;y<50;y++)
        if(vetor_fila[y]!=0)inserir_fila(vetor_fila[y]);
        for(int z=99;49<z;z--)inserir_fila(vetor_fila[z]);


    imprimir();

    return 0;
}
