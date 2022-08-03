#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = 0;
    int flag = 0;

    if ((A->columns <= 0) || (A->rows <= 0) || (B->columns <= 0) || (B->rows <= 0)) {
        errCode = 1;
    } else if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = 2;
    } else {
        flag = s21_create_matrix(A->rows, A->columns, result);
        if (flag == 0) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                }
            }
        }
    }
    return errCode;
}