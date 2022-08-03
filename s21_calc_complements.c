#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int errCode = 0;
    int coor_1 = 0;
    int coor_2 = 0;
    matrix_t minor;

    if (A->columns != A->rows) {
        errCode = 2;
    } else if ((A->columns <= 0) || (A->rows <= 0)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0, l = j; j < A->columns; j++) {
                for (int l = 1; l < A->rows - 1; l++) {
                    for (int k = 1; k < A->columns - 1; k++) {
                        coor_1 = i + l;
                        coor_2 = j + k;
                        minor.matrix[i][j] = A->matrix[coor_1][coor_2];
                    }
                }
                s21_determinant(&minor, &(result->matrix[i][j]));
                if ((i + j) % 2 != 0)
                    result->matrix[i][j] *= -1;
            }
        }
    }
    s21_remove_matrix(&minor);
    return errCode;
}