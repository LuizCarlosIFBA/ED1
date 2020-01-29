#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *prox;
}Nodo;

Nodo *topo = NULL;
Nodo *fim, *inicio = NULL;

void listar_fila();
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
    } else
          if (n > 0){
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
int n;
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

void main(){
    int n, op;

    printf("Escolha uma opcao:\n1 - inserir\n3 - listar\n0 - Sair\n ");
    scanf("%d",&op);
    system("cls");
    switch (op)
    {
    case 0:
        printf("saindo do programa em 3 .... 2 .... 1 .... 0");
        exit(1);
        break;
    case 1:
        printf("Digite um valor para inserir: ");
        scanf("%d",&n);
        inserir_lista(n);

        return main();

    break;

    case 3:
        listar();
        system("pause \n");

        return main();
    break;

    default:
        printf("valor invalido");

        return main();
    }
    

}

