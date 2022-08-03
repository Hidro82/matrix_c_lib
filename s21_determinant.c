#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int errCode = 0;
    int coor_1 = 0;
    int coor_2 = 0;
    double diag = 1;
    double deter = 0;
    
    if (A->columns != A->rows) {
        errCode = 2;
    } else if ((A->columns <= 0) || (A->rows <= 0)) {
        errCode = 1;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                coor_1 = j;
                coor_2 = j + i;
                if (coor_2 >= A->rows)
                    coor_2 -= A->rows;
                diag *= A->matrix[coor_1][coor_2];
            }
            deter += diag;
            diag = 1;
        }
        diag = -1;
        for (int i = 2; i >= 0; i--) {
            for (int j = 0; j < A->columns; j++) {
                coor_1 = j;
                coor_2 = i - j;
                if (coor_2 < 0)
                    coor_2 += A->rows;
                diag *= A->matrix[coor_1][coor_2];
            }
            deter += diag;
            diag = -1;
        }
        *result = deter;
    }
    return errCode;
}