void inserir_zero(Nodo *novo){
    Nodo *ant, *atual;
    ant=NULL;
    atual=inicio;

    while((atual!=NULL)&&(atual->info<0)){
        ant=atual;
        atual=atual->prox;
    }
    if(atual==inicio){
        novo->prox=inicio;
        inicio=novo;
    }else if(atual==NULL){
                ant->prox=novo;
                fim=novo;
        }else {
            ant->prox=novo;
            novo->prox=atual;
            }
}
