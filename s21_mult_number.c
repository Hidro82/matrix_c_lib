#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int errCode = matrix_checker(A);

    if (!errCode) {
        num_multiplicate(A, number, result);
    }
    return errCode;
}
