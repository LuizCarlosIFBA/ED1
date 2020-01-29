

//**************************************************
//                Funções para Percorrer a Arvore
//**************************************************

void em_ordem(Arvore *raiz){
if (raiz == NULL) return;
   em_ordem(raiz->esq);
   printf("%d ", raiz->info);
   em_ordem(raiz->dir);

}

void pre_ordem(Arvore *raiz){
   if (raiz == NULL) return;
   printf("%d ", raiz->info);
   pre_ordem(raiz->esq);
   pre_ordem(raiz->dir);

}
void post_ordem(Arvore *raiz){
   if (raiz == NULL) return;
   post_ordem(raiz->esq);
   post_ordem(raiz->dir);
   printf("%d ", raiz->info);
}

