#define CONT 10

//********************************************************************
//    Impressão 2D
//********************************************************************
// função que prepara a chamada da função print2Util
void print2D(Arvore *raiz)
{
    print2DUtil(raiz, 0);
}
// Função para imprimir a arvore em 2d
//  percurso dir-raiz-esq
void print2DUtil(Arvore *raiz, int espaco)
{
    // Base case
    if (raiz == NULL)
        return;

    // aumenta distancia entre os niveis
    espaco += CONT;

    // processa dir primeiro
    print2DUtil(raiz->dir, espaco);

    // Imprime o nodo depois do espaço
    printf("\n");

    for (int i = CONT; i < espaco; i++)
        printf(" ");
    printf("%d\n", raiz->info);

    print2DUtil(raiz->esq, espaco);
}
