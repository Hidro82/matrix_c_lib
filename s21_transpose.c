#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    int errCode = 0;
    int flag = 0;
    
    if ((A == NULL) || (A->matrix == NULL)) {
        errCode = 1;
    } else if ((A->columns <= 0) || (A->rows <= 0)) {
        errCode = 2;
    } else {
        flag = s21_create_matrix(A->columns, A->rows, result);
        if (flag == 0) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[j][i] = A->matrix[i][j];
                }
            }
        }
    }
    return errCode;
}