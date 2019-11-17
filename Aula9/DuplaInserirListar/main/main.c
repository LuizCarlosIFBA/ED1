#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int info;
    struct nodo *prox;
    struct nodo *ant;
}Nodo;

Nodo *insere(Nodo *ini,int n){

    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->info = n;
    aux->prox = NULL;
    aux->ant = NULL;

    if(ini==NULL)ini = aux; /// caso o ponteiro ini seja nulo entra aqui
    else{

        Nodo *ultimo = ini;
        int flag= 0;

        if(ultimo->prox==NULL){ /// condição de único bloco

            if(aux->info > ultimo->info){

                ultimo->prox = aux;
                aux->ant = ultimo;
            }else{

                aux->prox = ultimo;
                ultimo->ant = aux;
                ini = aux;
            }
        }else{
            /// no caso de ser menor que o primeiro ou igual o bloco novo que chegar entra aqui
            if(aux->info < ultimo->info || aux->info==ultimo->info){
                aux->prox = ultimo;
                ultimo->ant = aux;
                ini = aux;
            }else{
                    /// caso o bloco esteja no meio aqui será deslocado para a posição certa
                    while(ultimo->prox!=NULL){
                        if(aux->info > ultimo->info &&
                           aux->info < ultimo->prox->info){ /// desloca blocos do meio para encaixar o bloco na posição certa
                                flag=1;
                                aux->ant = ultimo;
                                aux->prox = ultimo->prox;
                                ultimo->prox->ant = aux;
                                ultimo->prox = aux;
                                break;
                           }else{

                                if(aux->info==ultimo->info){ /// Se tiver bloco com valores no meio igual entra aqui pra encaixar na posição certa
                                    flag=1;
                                    aux->prox = ultimo->prox;
                                    aux->ant = ultimo;

                                    ultimo->prox->ant = aux;
                                    ultimo->prox = aux;

                                    break;
                                }
                           }

                           ultimo = ultimo->prox;
                        }

                    if(flag==0){ /// aqui é só pra valores que vão pro final mesmo da lista
                        ultimo->prox = aux;
                        aux->ant = ultimo;
                    }
                }
            }
        }
    return ini;
}

void listarNormal(Nodo *inicio){
    Nodo *atual;
    atual = inicio;
    if (atual == NULL){
        printf("Lista vazia");
    }else{  do{
               printf("%d -> ", atual -> info);
               atual = atual -> prox;
            }while(atual -> prox != NULL);

            while(atual != NULL){
                printf("%d -> ", atual -> info);
                atual = atual -> ant;
            }
        }
}


int main()
{
    Nodo *inicio = NULL;
    inicio = insere(inicio,8);
    inicio = insere(inicio,0);
    inicio = insere(inicio,1);

    printf("Saida : \n");
    listarNormal(inicio);

    system("pause");
    return 0;
}
