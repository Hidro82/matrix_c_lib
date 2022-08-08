#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
    int errCode = matrix_checker(A);
    
    if (!errCode)
        errCode = sqr_checker(A);
    if (!errCode) {
        det_logic(A, result);
    }
    return errCode;
}