#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <time.h>

void main()
{
    srand(time(NULL));

    int qtd=3;
    for (int i = 0; i < qtd; i++) {
      escolha((rand() % 10)+1,(rand() % 10)+1);
    }
    imprimirPacotesIO();
    system("pause");

}






