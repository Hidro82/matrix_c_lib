#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = 0;

    if ((A->columns != B->rows) || (A->rows != B->columns)) {
        errCode = 2;
    } else if ((A->columns <= 0) || (A->rows <= 0) || (B->columns <= 0) || (B->rows <= 0)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * B->matrix[j][i];
            }
        }
    }
    return errCode;
}