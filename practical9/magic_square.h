#include <stdio.h>

int isMagicSquare(int ** square, const int n) {

    int main_diagonal = 0;
    int secondary_diagonal = 0;

    // Eliminate the case where 'n' is negative
    if (n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    int M = (n * (n*n + 1))/2;
    printf("M = %d\n", M);

    // Perform row sum, main & secondary diagonal calculation and verification
    int i, j;
    for (i = 0; i< n; i++) {
        int rowSum = 0;
        for (j = 0; j< n; j++) {
            rowSum = rowSum + square[i][j];
            if (i == j) {
                main_diagonal = main_diagonal + square[i][j];
            }
            if (i + j == n-1) {
                secondary_diagonal = secondary_diagonal + square[i][j];
            }
        }
        if (rowSum != M) {
            printf("Row %d does not sum to %d (row sum = %d).\n", i + 1, M, rowSum);
            return 0;
        }
    }
    // Perform column sum calculation and verification
    for (j=0; j<n; j++) {
        int colSum = 0;
        for (i=0;i<n;i++) {
            colSum = colSum + square[i][j];
        }
        if (colSum != M) {
            printf("Column %d does not sum to %d (column sum = %d).\n", j + 1, M, colSum);
            return 0;
        }
    }

    // Perform main and secondary diagonal verification
    if (main_diagonal != M || secondary_diagonal != M) {
        printf("Diagonals do not sum to %d (main diagonal = %d, secondary diagonal = %d).\n", M, main_diagonal, secondary_diagonal);
        return 0;       
    }

    return 1;
}
