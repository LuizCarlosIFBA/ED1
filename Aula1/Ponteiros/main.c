#include <stdio.h>
#include <stdlib.h>

//& endereço
//*Ponteiro
int main()
{   printf("Estado inicial \n");
    int a,b;
    int *ptr;
    a=3;
    ptr=&a;//Ponteiro prt recebe o endereço e A
    printf("Endereço de A %p\n",&a);
    printf("Valor ptr %d\n",*ptr);
    printf("Valor de A %d \n",a);
    printf("Valor do ponteiro PTR %p \n\n",ptr);


    //No final o valor de PTR mudou poque
    return 0;
}
