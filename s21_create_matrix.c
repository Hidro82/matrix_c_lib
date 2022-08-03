#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int errCode = 1;    
    if (rows > 0 && columns > 0) {    
        result->matrix = calloc(rows, sizeof(double *));
        if (result->matrix != NULL)
        {
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = calloc(columns, sizeof(double));
            }
        }
        result->rows = rows;
        result->columns = columns;
        errCode = 0;
    }
    return errCode;
}