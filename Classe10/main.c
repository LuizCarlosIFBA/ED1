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

void listar_dupla(Nodo *inicio){
     Nodo *atual;
     atual = inicio;

     if(atual==NULL){
            printf("Lista vazia");
            exit(0);
     }

     printf("Lista normal\n");
     while(atual->prox != NULL){
        printf("%d  ",atual->info);
        atual = atual->prox;
     }
     printf("%d  ",atual->info);
     printf("\nLista inversa\n");
     while(atual->ant != NULL){
        printf("%d  ",atual->info);
        atual = atual->ant;
     }
     printf("%d  ",atual->info);
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
		printf("2 Mostrar Lista: \n");
		printf("3 sair: \n");
		printf("4 retirar: \n");
		printf("\n");
		scanf("%d",&opc);

		switch(opc){
			case 1:
				printf("Digite o Valor:\n");
				scanf("%d",&num);
				inserir(&inicio,num);
				break;
            case 2:
				listar_dupla(inicio);
				break;
            case 3:
				exit(0);
				break;
			case 4:
			    if(inicio!=NULL){
                    printf("Digite o valor que queira remover:\n");
                    scanf("%d",&num);
                    retirar(&inicio,num);
			    }else printf("Lista vazia\n");
                break;
			default:printf("Digite apenas numeros de 1 ate 4!\n\n");
		}
	}while(opc!=3);


    return 0;
}
