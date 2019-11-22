#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
    struct nodo *ant;
}Nodo;

void inserir(Nodo **inicio, int n){
     Nodo *atual,*novo;
     novo = (Nodo*)malloc(sizeof(Nodo));
     novo->info = n;
     novo->ant = novo->prox = NULL;

     if (novo == NULL)exit(1);
     if(*inicio == NULL)
     {
         *inicio = novo;
         return;
     }
     atual = *inicio;
     while((atual->prox !=NULL)&&(n > atual->info))
        atual= atual->prox;

    if((atual == *inicio) && (atual -> prox != NULL)){
           novo->prox = *inicio;
           (*inicio)->ant = novo;
           *inicio = novo;
    }else{
        if(atual->prox == NULL)
        {
            atual->prox = novo;
            novo->ant = atual;
        }else{
            atual->ant->prox = novo;
            novo->ant = atual->ant;
            novo->prox = atual;
            atual->ant = novo;
        }
     }
}

 int retirar(Nodo **inicio, int n) {
    Nodo *atual;
    if (*inicio == NULL)return 0;

    atual = *inicio;
    while((atual != NULL)&& ( n!= atual->info))
    {
          atual = atual->prox;
    }
    if (  atual == NULL)return 0;
    if ( atual== *inicio){
        *inicio = (*inicio)->prox;
        (*inicio )-> ant = NULL;
    }else{
        if ( atual-> prox == NULL){
            atual->ant->prox = NULL;
        }else{
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
        }
    }
    free(atual);
    return 1;
}

int main()
{
    int num, opc;
    Nodo *inicio = NULL;
	do{
		printf("\n1 inserir na Lista: \n");
		printf("2 sair: \n");
		printf("3 retirar: \n");
		printf("\n");
		scanf("%d",&opc);

		switch(opc){
			case 1:
				printf("Digite o Valor:\n");
				scanf("%d",&num);
				inserir(&inicio,num);
				break;
            case 2:
				exit(0);
				break;
			case 3:
			    if(inicio!=NULL){
                    printf("Digite o valor que queira remover:\n");
                    scanf("%d",&num);
                    retirar(&inicio,num);
			    }else printf("Lista vazia\n");
                break;
			default:printf("Digite apenas numeros de 1 ate 3!\n\n");
		}
	}while(opc!=3);


    return 0;
}
