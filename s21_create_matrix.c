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