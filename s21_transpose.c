#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    int errCode = matrix_checker(A);

    if (!errCode) {
        transposer(A, result);
    }
    return errCode;
}
