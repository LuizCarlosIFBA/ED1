#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct nodo{
         int prioridade,tVida;
         struct nodo *esq,*dir;
}Arvore;



//*********************************************
//   Funções
//*********************************************
// Inserir um elemento na arvore binaria


 Arvore* inserir( Arvore* raiz, int t,int p) {
    // se a arvore esta vazia retorna um unico nodo
 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if(raiz == NULL)exit(1);
     raiz->prioridade =5;
     raiz->tVida =5;
     raiz->esq = NULL;
     raiz->dir =  NULL;
 return(raiz);
 }
 // senao percorre a arvore recursivamente
 if ((p<=raiz->prioridade) && (4>=raiz->dir)){
     raiz->dir = inserir(raiz->dir,t,p);
     printf("Multimidia:\nTempo de vida:%i\n\Prioridade:%i\n ",t,p);
 }else if (p<raiz->dir){
             raiz->esq = inserir(raiz->esq,t,p);
             printf("Tempo real:\nTempo de vida:%i\n\Prioridade:%i\n ",t,p);
       }else if(raiz->tVida<=7){
                raiz->dir = inserir(raiz->dir,t,p);
                printf("Normal:\nTempo de vida:%i\n\Prioridade:%i\n ",t,p);
             }else{
                    raiz->dir = inserir(raiz->dir,t,p);
                    printf("Não prioritario:\nTempo de vida:%i\n\Prioridade:%i\n ",t,p);
                  }

 return(raiz); // retorna a raiz sem mudar

}


int main()
{   Arvore *raiz = NULL;

    srand (time(NULL));
    raiz = inserir(raiz,1 + ( rand() % 10),1 + ( rand() % 10));
    raiz = inserir(raiz,1 + ( rand() % 10),1 + ( rand() % 10));

    printf("\n");

    system("pause");

   return 0;
}
