#include <stdio.h>
#include <stdlib.h>

void fib(int *a, int *b);

int main(void){
    int n;
    printf("Please input the positive integer n\n");
    scanf("%d", &n);
    if (n < 1){
        printf("n must be bigger than 1\n");
        exit(1);
    }
    int f0=0;
    int f1=1;
    printf("The fib. series is: \n");
    printf("%d, %d", f0, f1);

    int i;
    for (i = 2; i < n+1; i++){
        fib(&f1, &f0);
        printf("%d ", f1);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }
    return 0;
}
void fib(int *a, int *b){
    int next;
    next = *a + *b;
    *b = *a;
    *a = next;
}