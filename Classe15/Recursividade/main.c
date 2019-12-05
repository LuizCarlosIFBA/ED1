#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if(n == 1) {
        return 1;
    }
    else {
        return n*fatorial(n-1);
    }
}

int fib(int n) {
    if(n < 3) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int main()
{
    printf("Fibonacci de 6: ");
    printf("%d \n",fib(6));
    printf("Fatorial de 7:");
    printf("%d \n",fatorial(7));
    return 0;
}
