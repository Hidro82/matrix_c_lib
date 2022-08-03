#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int errCode = SUCCESS;

    if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = FAILURE;
    } else if ((A->columns <= 0) || (B->columns <= 0) || (A->rows <= 0) || (B->rows <= 0)) {
        errCode = FAILURE;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(fabs(A->matrix[i][j]) - fabs(B->matrix[i][j])) > 1e-06)
                    errCode = FAILURE;
            }
        }
    }
    return errCode;
}