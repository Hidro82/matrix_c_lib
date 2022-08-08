#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int errCode = matrix_checker(A);

    if (!errCode) {
        errCode = sqr_checker(A);
    }
    if (!errCode) {
        complement(A, result);
    }
    return errCode;
}