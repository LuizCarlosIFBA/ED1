typedef struct nodo{
         int info;
         struct nodo *esq,*dir;
}Arvore;

// Funções para Arvore Binaria

Arvore* inserir(Arvore*, int);

int buscar(Arvore *raiz, int num);

Arvore* retirar(Arvore *raiz, int num);

void em_ordem(Arvore *raiz);

void pre_ordem(Arvore *raiz);

void post_ordem(Arvore *raiz);

void print2D(Arvore *raiz);

void print2DUtil(Arvore *raiz, int espaco);


