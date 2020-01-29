#include <stdio.h>
#include <stdlib.h>


//SUBSTITUIR OS VALORES


void trocar (int *A, int *B){
    int aux;

    aux = *A;
    *A = *B;
    *B = aux;
//printf("%d %d", &A, &B);
}

// função para trocar os valores das variaveis


int main(){
    int C, D;
    C= 3, D = 5;

    trocar(&C , &D);
    printf("%d%d", C,D);

}


