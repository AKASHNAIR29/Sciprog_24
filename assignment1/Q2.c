#include <stdio.h>

/*
TODO: Write function declaration 
      for the calculation of the determinant of 3x3 matrix
*/
float getdet(float minor[3][3]);

int main(void) {

    //TODO: Complete variable declarations
    float hmat[4][4], minor[3][3];
    float determinant = 0.0;

    //TODO: Initialise Hilbert matrix and print
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            hmat[i][j] = 1.0 / (i + j + 1);
        }
    }

    printf("Hilbert Matrix 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.4f ", hmat[i][j]);
        }
        printf("\n");
    }

    //TODO: Find determinant of 4x4 Hilbert matrix using Cramer rule
    for (int i = 0; i < 4; i++) {
        int row = 0;

        for (int j = 1; j < 4; j++) {
            int col = 0;

            for (int k = 0; k < 4; k++) {
                if (k != i) {
                    minor[row][col] = hmat[j][k];
                    col++;
                }
            }
            row++;
        }

        // Add/subtract the determinant of the minor based on the column index
        determinant += (i % 2 == 0 ? 1 : -1) * hmat[0][i] * getdet(minor);
    }

    //TODO: Print calculated determinant
    printf("Determinant of the 4x4 Hilbert matrix: %.10f\n", determinant);

    return 0;
}

//TODO: Complete function definition to get determinant  
float getdet(float minor[3][3]) {
    float a = minor[0][0], b = minor[0][1], c = minor[0][2];
    float d = minor[1][0], e = minor[1][1], f = minor[1][2];
    float g = minor[2][0], h = minor[2][1], i = minor[2][2];

    // Determinant formula for a 3x3 matrix
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}
