#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = matrix_checker(A) || matrix_checker(B);
    matrix_t minus;

    if (!errCode) {
        errCode = possibility_add(A, B);
    }
    if (!errCode) {
        s21_create_matrix(B->rows, B->columns, &minus);
        minus_maker(B, &minus);
        add_logic(A, &minus, result);
        s21_remove_matrix(&minus);
    }
    return errCode;
}
