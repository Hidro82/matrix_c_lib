#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int errCode = SUCCESS;

    if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = FAILURE;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (A->matrix[i][j] != B->matrix[i][j])
                    errCode = FAILURE;
            }
        }
    }
    return errCode;
}