#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int errCode = 0;
    double det = 0;
    matrix_t minors;
    matrix_t trans_minors;

    s21_determinant(A, &det);
    if ((A->columns != A->rows) || (det == 0)) {
        errCode = 2;
    } else if ((A->columns <= 0) || (A->rows <= 0)) {
        errCode = 1;
    } else {
        s21_calc_complements(A, &minors);
        s21_create_matrix(A->rows, A->columns, &trans_minors);
        s21_transpose(&minors, &trans_minors);
        s21_create_matrix(A->rows, A->columns, &result);
        s21_mult_number(&trans_minors, (1 / det), result);
        s21_remove_matrix(&minors);
        s21_remove_matrix(&trans_minors);
    }
    return errCode;
}