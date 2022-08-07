#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = 0;
    int flag = 0;

    if ((A == NULL) || (B == NULL)) {
        errCode = 1;
    } else if ((A->columns != B->rows)
    || (A->columns <= 0) || (A->rows <= 0)
    || (B->columns <= 0) || (B->rows <= 0)
    || (A->matrix == NULL) || (B->matrix == NULL)) {
        errCode = 2;
    } else {
        flag = s21_create_matrix(A->rows, B->columns, result);
        if (flag == 0) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    for (int k = 0; k < B->rows; k++) {
                        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                    }
                }
            }
        }
    }
    return errCode;
}