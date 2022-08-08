#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = matrix_checker(A) || matrix_checker(B);

    if (!errCode) {
        errCode = possibility_mult(A, B);
    if (!errCode)
        mat_multiplicate(A, B, result);
    }
    return errCode;
}