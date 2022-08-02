#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int errCode = 1;    
    if (rows > 0 && columns > 0) {    
        double** matrix = malloc(sizeof *matrix * rows);
        if (matrix)
        {
            for (int i = 0; i < rows; i++) {
                matrix[i] = malloc(sizeof *matrix[i] * columns);
            }
        }
        result->rows = rows;
        result->columns = columns;
        result->matrix = matrix;
        errCode = 0;
    }
    return errCode;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix) {
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
    }
    if (A->rows)
        A->rows = 0;
    if (A->columns)
        A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int errCode = SUCCESS;

    if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = FAILURE;
    } else {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (A->matrix[i][j] != B->matrix[i][j])
                    errCode = FAILURE;
            }
        }
    }
    return errCode;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = 0;

    if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
    return errCode;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = 0;

    if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return errCode;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
        int errCode = 0;

    if ((A->columns <= 0) || (A->rows <= 0)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * number;
            }
        }
    }
    return errCode;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errCode = 0;

    if ((A->columns != B->rows) || (A->rows != B->columns)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * B->matrix[j][i];
            }
        }
    }
    return errCode;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int errCode = 0;
    
    if ((A->columns <= 0) || (A->rows <= 0)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->columns, A->rows, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[j][i] = A->matrix[i][j];
            }
        }
    }
    return errCode;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int errCode = 0;
    int coor_1 = 0;
    int coor_2 = 0;
    matrix_t minor;

    if ((A->columns != A->rows) || (A->rows <= 0) || (A->columns <= 0)) {
        errCode = 1;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0, l = j; j < A->columns; j++) {
                for (int l = 1; l < A->rows - 1; l++) {
                    for (int k = 1; k < A->columns - 1; k++) {
                        coor_1 = i + l;
                        coor_2 = j + k;
                        minor.matrix[i][j] = A->matrix[coor_1][coor_2];
                    }
                }
                s21_determinant(&minor, &(result->matrix[i][j]));
                if ((i + j) % 2 != 0)
                    result->matrix[i][j] *= -1;
            }
        }
    }
    s21_remove_matrix(&minor);
    return errCode;
}

int s21_determinant(matrix_t *A, double *result) {
    int errCode = 0;
    int coor_1 = 0;
    int coor_2 = 0;
    double diag = 1;
    double deter = 0;
    
    if ((A->columns != A->rows) || (A->rows <= 0) || (A->columns <= 0)) {
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

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {

}