#include "s21_matrix.h"

void matrix_print(matrix_t *A) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            printf("%f\t", A->matrix[i][j]);
        }
        printf("\n");
    }
}