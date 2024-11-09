#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double arc1(double x, double delta);
double arc2(double x);

int main(void)
{
    double delta;
    printf("Please enter a Positive real number delta: \n");
    scanf("%lf", &delta);

    if (delta < 0)
    {
        printf("Delta was negative\n");
        exit(1);
    }

    double x = -0.9;
    int length = 1000;
    double tan1[1000];
    double tan2[1000];
    int i = 0;
    while (x <= 0.9 && i < length)
    {
        tan1[i] = arc1(x, delta);
        tan2[i] = arc2(x);
        printf("The Difference at x=%lf is %.10lf \n", x, fabs((tan1[i] - tan2[i])/ tan2[i]));
        i++;
        x += 0.1; 
    }
    return 0;
}

double arc1(double x, double delta)
{
    double sum = 0;
    double elem, val;
    int n = 0;
    do{
        val = 2*n +1;
        elem = pow(x, val) / val;
        sum += elem;
        n++;
    }while (fabs(elem)>= delta);
    return sum;
}

double arc2(double x)
{
    return (log(1 + x) - log(1 - x)) / 2;
}
