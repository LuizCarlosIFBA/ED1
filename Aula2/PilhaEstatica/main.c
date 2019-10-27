#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int topo=-1;
int pilha[TAM];

/*
Antes de inserir necessito ver se a pilha
está vazia. Caso não esteja, sou autorizado
a preencher.
*/
void inserir(int n){
    if(topo==TAM-1){
        printf("Pilha cheia");
    }else pilha[++topo]=n;
}

/*
Antes de inserir necessito ver se a pilha
está cheia. Caso não esteja, sou autorizado
a remover.
*/
int remover(){
    int n;
    if(topo==-1){
        printf("Pilha vazia");
    }else n = pilha[topo];
    topo--;
    return n;
}

int main()
{
    inserir(3);
    printf("O valor adicionado e removido foi %d \n",remover());
    return 0;
}
