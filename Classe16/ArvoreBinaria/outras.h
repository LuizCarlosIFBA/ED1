
//*********************************************
//   Funções
//*********************************************
// Inserir um elemento na arvore binaria


 Arvore* inserir( Arvore* raiz, int num) {
    // se a arvore esta vazia retorna um unico nodo
 if (raiz == NULL) {
     raiz =(Arvore *)malloc(sizeof(Arvore));
     if( raiz == NULL)exit(1);
     raiz->info =num;
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


int buscar(Arvore *raiz,int num){
    if (raiz == NULL)  return 0;
    if(raiz->info == num) return 1;
    return(buscar(raiz->esq,num));
    return(buscar(raiz->dir,num));

}

Arvore *substitui ( Arvore *raiz, Arvore *sucessor)
{ Arvore *ret;
   if ((sucessor->esq)==NULL)
   {  raiz->info=sucessor->info;
      ret=sucessor;
      sucessor=sucessor->dir;
      free(ret);
   }
   else
      sucessor->esq=substitui(raiz, sucessor->esq);
   return(sucessor);
}


Arvore* retirar(Arvore* raiz, int num)
{ Arvore *ret;
  if (raiz != NULL)
    if (raiz->info < num)
       raiz->dir=retirar(raiz->dir, num);
    else
    { if (raiz->info > num)
      raiz->esq=retirar(raiz->esq,num);
      else
      {
        if ((raiz->esq)==NULL)
        {   ret=raiz;
            raiz=raiz->dir;
            free(ret);
        }
        else
          if (raiz->dir==NULL)
          {   ret=raiz;
              raiz=raiz->esq;
              free(ret);
           }
           else
               raiz->dir=substitui(raiz, raiz->dir);
        }
    }
  return(raiz);
  }

