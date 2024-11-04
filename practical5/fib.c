#include <stdio.h>

// Function to compute Fibonacci series step
void fibonacci_step(int *fn1, int *fn2) {
    int temp = *fn1;   // Store current Fn-1
    *fn1 = *fn1 + *fn2; // Compute Fn
    *fn2 = temp;        // Update Fn-1 to the previous Fn-1
}

int main() {
    int n, i;
    
    // Get the value of n from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Initial values for Fibonacci sequence
    int fn1 = 1, fn2 = 0;
    
    // Print F0 and F1
    printf("Fibonacci series up to %d: \n", n);
    printf("%d, %d", fn2, fn1);

    // Loop to calculate and print Fibonacci series up to n
    for (i = 2; i <= n; i++) {
        fibonacci_step(&fn1, &fn2);  // Update fn1 and fn2 using the function
        printf(", %d", fn1);         // Print next Fibonacci number
    }
    
    printf("\n");
    return 0;
}
