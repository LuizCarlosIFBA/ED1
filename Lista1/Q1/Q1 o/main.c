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

Nodo fila_dupla[2][3];

Nodo *fim, *inicio=NULL;
Nodo *topo = NULL;

Nodo * inserir_fila(int n);
int retirar_fila();
void imprimir();

int cont_fila1=0;
int cont_fila2=0;
int i_fila = 0;
int j_fila = 0;
Nodo * inserir_fila(int n){
    Nodo *novo;
    novo=(Nodo*)malloc(sizeof(Nodo));
    if(novo==NULL)exit(1);
    novo->info=n;
    novo->prox = NULL;
    if(inicio==NULL){
       inicio=novo;
       fim=novo;
       printf("\nValor inserido!!\n");
    }else{
           fim->prox = novo;
           fim=novo;
           printf("\nValor inserido!!\n");
         }
    return novo->info;
}

//verificar vazio
void imprimir(){
   printf("Fila 1 \n");
   int i = i_fila;
   int j = j_fila;
   for(i;i<cont_fila1;i++){printf("%d ",fila_dupla[0][i].info);}
   printf("\nFila 2 \n");
   for(j;j<cont_fila2;j++){printf("%d ",fila_dupla[1][j].info);}
   printf("\n");
}


int retirar_fila(int fila){
    Nodo *aux;
    int n;
    if(inicio==NULL){
        printf("\nFila vazia\n");
        return 0;
    }else{
            if(fila==1){
                printf("O elemento %d foi retirado\n",fila_dupla[0][cont_fila1].info);
                i_fila++;
            }else{
                   j_fila++;
                   printf("O elemento %d foi retirado\n",fila_dupla[1][cont_fila2].info);
                 }
         }

    return n;
}


int main()
{     int op;
      int fila;
      int valor;
      int retirar;
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
           for(int i =0;i<6;i++){
           printf("Insera um numero: "); scanf("%d", &valor);
           printf("Digite 1 para guardar na fila 1 e qualquer numero para a fila 2 : "); scanf("%d", &fila);

           if(fila==1){
                 fila_dupla[0][cont_fila1].info=inserir_fila(valor);
                 cont_fila1++;
           }else {fila_dupla[1][cont_fila2].info=inserir_fila(valor);
                  cont_fila2++;
                  }
           }
           break;
         case 2:
           printf("Digite 1 para retirar na fila 1 e qualquer numero para a fila 2 : "); scanf("%d", &retirar);
           retirar_fila(retirar);
           break;
         case 3:
            imprimir();
            break;
         default:
            if(op < 0 || op>3) printf("Escreva um numero de zero ate tres\n\n");

         }
   }while(op != 0);

    return 0;
}
