#include <stdio.h>
#include <stdlib.h>

int *allocate_array(int n);
void fillwithhones(int *p, int n);
void printarray(int *p, int n);


int main(void) {
    int size = 5;
    int *p;
    p = allocate_array(size);
    fillwithhones(p, size);
    printarray(p, size);
    free(p);
    return 0;
} 

int *allocate_array(int n) 
{
    return (int *)malloc(n * sizeof(int));
}

void fillwithhones(int *p, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        p[i] = 1;
        //*(p+i) = 1;
    }
}

void printarray(int *p, int n) 
{
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void freepointer(int *p) 
{
    free(p); //memory is freed when the pointer is no longer needed
}