    // se a arvore esta vazia retorna um unico nodo
 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if( raiz == NULL)exit(1);
     raiz->info = num;
     raiz->esq = NULL;
     raiz->dir = NULL;

 return(raiz);
 }
 else {
 // senao percorre a arvore recursivamente
 if (num < raiz->info) raiz->esq = inserir(raiz->esq, num);
 else if ( num > raiz->info) raiz->dir = inserir(raiz->dir, num);
      else {printf("\nERRO numero repetido\n");
            system("pause");}
 return(raiz); // retorna a raiz sem mudar
 }
}

Arvore* contar( Arvore* raiz){
    
    if( raiz == NULL)
        printf("\nArvore vazia\n");
    else{
        if ((raiz -> esq == NULL)&&(raiz -> dir == NULL)) return 1;
        return(contar(raiz->esq) + contar(raiz->dir));
    }
}
