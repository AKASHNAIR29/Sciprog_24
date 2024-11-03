#include <stdio.h>
#include <math.h>

// Function to calculate the slope (alpha) and intercept (beta) for the linear regression line
void linear_regression(double x[], double y[], int n, double *alpha, double *beta) {
    // Initialize sums needed for the calculation of 'alpha' and 'beta'
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;
    
    // (b) Loop through each data point to accumulate the sums for calculations
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += pow(x[i], 2);  // Square each x value
    }
    
    // (c) Calculate the denominator to prevent division by zero
    double denominator = n * sum_x_squared - pow(sum_x, 2);
    if (denominator == 0) {
        printf("Error: Cannot calculate due to zero denominator.\n");
        return;
    }

    // Calculate 'alpha' (slope) and 'beta' (y-intercept)
    *alpha = (n * sum_xy - sum_x * sum_y) / denominator;
    *beta = (sum_y - (*alpha) * sum_x) / n;
}

int main() {
    // TODO: Complete variable declarations
    int n;

    // TODO: Enter the number of data points  
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Define arrays to hold x and y values based on the number of data points
    double x[n], y[n];  

    // TODO: Enter (xi, yi) values i=1, 2, ..., n
    // Input each pair of x and y values
    for (int i = 0; i < n; i++) {
        printf("Enter x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("Enter y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    double alpha, beta;

    // TODO: Calculate alpha and beta formulas
    linear_regression(x, y, n, &alpha, &beta);

    // TODO: Print the equation of the line 
    printf("The equation of the best-fitting line is: y = %.2fx + %.2f\n", alpha, beta);

    return 0; // Indicate successful completion
}
