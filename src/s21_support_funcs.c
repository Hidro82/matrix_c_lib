#include "s21_matrix.h"

void matrix_print(matrix_t *A) {
    // Простой принт матрицы, nuff said
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            printf("%f\t", A->matrix[i][j]);
        }
        printf("\n");
    }
}

int matrix_checker(matrix_t *A) {
    // Проверка матрицы на корректность
    int errCode = 0;

    if ((A == NULL) || (A->columns <= 0)
    || (A->rows <= 0) || (A->matrix == NULL)) {
        errCode = 1;
    }
    return errCode;
}

int sqr_checker(matrix_t *A) {
    // Проверка, квадратная ли матрица
    int errCode = 0;

    if (A->columns != A->rows) {
        errCode = 2;
    }
    return errCode;
}

int possibility_mult(matrix_t *A, matrix_t *B) {
    // Проверка, возможно ли умножение между матрицами
    int errCode = 0;

    if (A->columns != B->rows) {
        errCode = 2;
    }
    return errCode;
}

int possibility_add(matrix_t *A, matrix_t *B) {
    // Проверка, возможно ли сложение между матрицами
    int errCode = 0;

    if ((A->columns != B->columns) || (A->rows != B->rows)) {
        errCode = 2;
    }
    return errCode;
}

void mat_multiplicate(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Логика перемножения матриц
    int flag = s21_create_matrix(A->rows, B->columns, result);

    if (flag == 0) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                for (int k = 0; k < B->rows; k++) {
                    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                }
            }
        }
    }
}

void num_multiplicate(matrix_t *A, double number, matrix_t *result) {
    // Логика умножения матрицы на скаляр
    int flag = s21_create_matrix(A->rows, A->columns, result);

    if (flag == 0) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * number;
            }
        }
    }
}

void add_logic(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Логика для сложения матриц
    int flag = s21_create_matrix(A->rows, A->columns, result);

    if (flag == 0) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
}

void minus_maker(matrix_t *A, matrix_t *minus) {
    // Смена знака у всех элементов матрицы
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            minus->matrix[i][j] = -A->matrix[i][j];
        }
    }
}

void complement(matrix_t *A, matrix_t *result) {
    // Логика для расчёта алгебраического дополнения
    int coor_1 = 0;
    int coor_2 = 0;
    double deter = 0;
    matrix_t minor;

    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            for (int l = 1; l < A->rows; l++) {
                for (int k = 1; k < A->columns; k++) {
                    coor_1 = i + l;
                    coor_2 = j + k;
                    if (coor_2 >= A->rows)
                        coor_2 -= A->rows;
                    if (coor_1 >= A->columns)
                        coor_1 -= A->columns;
                    minor.matrix[l - 1][k - 1] = A->matrix[coor_1][coor_2];
                }
            }
            s21_determinant(&minor, &deter);
            result->matrix[i][j] = deter;
        }
    }
    s21_remove_matrix(&minor);
}

void det_logic(matrix_t *A, double *result) {
    // Логика расчёта определителя матрицы
    matrix_t comply;
    *result = 0;

    if (A->rows == 1) {
        *result = A->matrix[0][0];
    } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else if (A->rows == 3) {
        *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2]
        + A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0]
        + A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1]
        - A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0]
        - A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2]
        - A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1];
    } else {
        complement(A, &comply);
        for (int i = 0; i < A->rows; i++) {
            *result += A->matrix[0][i] * comply.matrix[0][i];
        }
        s21_remove_matrix(&comply);
    }
}

void transposer(matrix_t *A, matrix_t *result) {
    // Логика для транспонирования матрицы
    int flag = s21_create_matrix(A->columns, A->rows, result);

    if (flag == 0) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[j][i] = A->matrix[i][j];
            }
        }
    }
}
