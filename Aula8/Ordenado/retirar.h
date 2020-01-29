typedef struct nodo {
    int info;
    struct nodo *prox;
}Nodo;

Nodo *topo = NULL;
Nodo *fim, *inicio = NULL;
Nodo *penultimo;


int retirarInicio(){
    Nodo *aux;
    int n;
    if(inicio==NULL){
        printf("Nao existe valor no inicio");
        return 0;
    }

    aux=inicio;
    n=aux->info;
    inicio = inicio->prox;
    free(aux);

    return n;
}

void retirarFim(){
    Nodo *ultimo;
    Nodo *penultimo;

    if(inicio==NULL){
        printf("Nao existe valor no fim");
        return ;
    }else if(inicio==fim){retirarInicio(); return;}

    ultimo=inicio->prox;
    penultimo=inicio;

    while(ultimo->prox!=NULL){
        penultimo=ultimo;
        ultimo=ultimo->prox;
    }

    penultimo->prox=NULL;


/*
    aux=fim;
    n=aux->info;
    free(aux);
    fim=penultimo;*/

}
