#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int errCode = matrix_checker(A);;
    double det = 0;
    matrix_t minors;
    matrix_t trans_minors;

    s21_determinant(A, &det);
    if (!errCode)
        errCode = sqr_checker(A);
    if (!errCode && (det != 0)) {
        s21_calc_complements(A, &minors);
        s21_transpose(&minors, &trans_minors);
        s21_mult_number(&trans_minors, (1 / det), result);
        s21_remove_matrix(&minors);
        s21_remove_matrix(&trans_minors);
    }
    return errCode;
}
