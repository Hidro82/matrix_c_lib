#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int errCode = !(matrix_checker(A)) && !(matrix_checker(B));

    if (errCode && possibility_add(A, B))
        errCode = FAILURE;
    if (errCode) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-8)
                    errCode = FAILURE;
            }
        }
    }
    return errCode;
}
