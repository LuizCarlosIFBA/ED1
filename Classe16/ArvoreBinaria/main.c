#include <stdio.h>
#include <stdlib.h>
#include "definicoes.h"
#include "print.h"
#include "ordem.h"
#include "outras.h"
#include <ctype.h>

int main()
{   Arvore *raiz = NULL;
    int num;
    char op;
    for(;;){
       system("cls");

      printf("\n----------------------------------");
      printf("\n    ARVORE DE BUSCA BINARIA\n\n");
      printf("\n I: Inserir um elemento");
      printf("\n B: Buscar um elemento");
      printf("\n R: Retirar un elemento");
      printf("\n E: Imprimir Em-Ordem");
      printf("\n P: Imprimir Pre-Ordem");
      printf("\n U: Imprimir Post-Ordem");
      printf("\n D: Imprimir 2D");
      printf("\n S: Sair");
      printf("\n\n\n Digite sua opcao: ");
      scanf("%c",&op);
      if (islower(op))op =toupper(op);

    switch (op)
    {
       case 'I': printf("\n-----Inserir-----\n");
                 printf("\n Digite um numero: ");
                 scanf("%d", &num);
                 raiz = inserir(raiz, num);
                 break;
       case 'B': printf("\n-----Buscar-----\n");
                 printf("\n Digite um numero: ");
                 scanf("%d", &num);
                 if ( buscar(raiz,num)== 0) printf("\n O numero nao encontra-se na arvore");
                 else printf("\n O numero encontra-se na arvore");
                 printf("\n\n ");
                 system("pause");
                 break;
       case 'R': printf("\n-----Retirar-----\n");
                 printf("\n Digite um numero: ");
                 scanf("%d", &num);
                 raiz = retirar(raiz,num);
                 printf("\n\n ");
                 system("pause");
                 break;
       case 'E': printf("\n-----Em-Ordem-----\n");
                 em_ordem(raiz);
                 printf("\n\n ");
                 system("pause");
                 break;
       case 'P': printf("\n-----Pre-Ordem-----\n");
                 pre_ordem(raiz);
                 printf("\n\n ");
                 system("pause");
                 break;
       case 'U': printf("\n-----Post-Ordem-----\n");
                 post_ordem(raiz);
                 printf("\n\n ");
                 system("pause");
                 break;
       case 'D': printf("\n-----Arvore 2D-----\n");
                 print2D(raiz);
                 printf("\n\n ");
                 system("pause");
                 break;
       case 'S': exit(1);

    }
   }
   return 0;
}
