
#include "definicoes.h"

//*********************************************
//   Funções
//*********************************************
// Inserir um elemento na arvore binaria


 Arvore* inserir( Arvore* raiz, int t,int p) {
    // se a arvore esta vazia retorna um unico nodo
 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if( raiz == NULL)exit(1);
     raiz->tVida =t;
     raiz->prioridade =p;
     raiz->esq = NULL;
     raiz->dir = NULL;
 return(raiz);

 // senao percorre a arvore recursivamente
 if (p < raiz->info) raiz->esq = inserir(raiz->esq, p);
 else if ( p > raiz->info) raiz->dir = inserir(raiz->dir, p);
      else {printf("\nERRO numero repetido\n");
            system("pause");}
 return(raiz); // retorna a raiz sem mudar

}


