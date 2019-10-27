#include <stdio.h>
#include <stdlib.h>


/*
Essa é uma forma de fazer a String aceitar nome com espaçamento
e pular para o próximo scanf

scanf("%[^\n]s", variavel);
setbuf(stdin, NULL);
*/

typedef struct{
        char nome[256], matricula[256], cel[9];
        int idade;
} Aluno;

int main(int argc, char *argv[]){
        int i=0;
        Aluno alunosi;
        Aluno turma[30];

        //for(i=0; i<30; i++) {
        for(;i<2;i++){
            printf("\n\nEntre com o nome: ");
            scanf("%[^\n]s%*c", alunosi.nome);
            setbuf(stdin, NULL);
            printf("\n\nEntre com a matricula: ");
            scanf("%[^\n]s%*c",alunosi.matricula );
            setbuf(stdin, NULL);
            printf("\n\nEntre com o telefone.: ");
            scanf("%[^\n]s%*c", alunosi.cel);
            setbuf(stdin, NULL);
            printf("\n\nEntre com a idade: ");
            scanf("%d%*c", &alunosi.idade);
            turma[i] = alunosi;
            printf("\n\n");
        }
        // for(i=0; i<30; i++) {
        for(i=0; i<2; i++) {
            printf("Nome.: %s\n", turma[i].nome);
            printf("Matricula.: %s\n", turma[i].matricula);
            printf("Telefone.: %s\n", turma[i].cel);
            printf("Idade.: %d\n\n", turma[i].idade);
        }
    //system("PAUSE");
    return(0);
}
