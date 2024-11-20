#include<stdio.h>
int interactiveGCD(int a, int b)
{
    
    while (b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int recursiveGCD(int a, int b)
{
    if (b==0){
        return a;
    }
    else{
        return recursiveGCD(b, a % b);
    }
}

int main()
{
    int a, b, error;
    printf("Enter two positive integers: ");
    error = scanf("%d %d", &a, &b);
    if (error!= 2){
        printf("Invalid input\n");
        return 1;
    }
    
    if (a<=0 || b<=0){
        printf("Invalid input\n");
        return 1;
    }

    printf("GCD of %d and %d by interactive method is %d\n", a, b, interactiveGCD(a,b));
    printf("GCD of %d and %d by recursive method is %d\n", a, b, recursiveGCD(a,b));
    return 0;
}
