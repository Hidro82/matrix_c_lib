#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = matrix_checker(A) || matrix_checker(B);

    if (!errCode) {
        errCode = possibility_add(A, B);
    }
    if (!errCode) {
        add_logic(A, B, result);
    }
    return errCode;
}
