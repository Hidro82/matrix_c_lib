#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#define SUCCESS 1
#define FAILURE 0

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
void matrix_print(matrix_t *A);
int matrix_checker(matrix_t *A);
int sqr_checker(matrix_t *A);
int possibility_mult(matrix_t *A, matrix_t *B);
void mat_multiplicate(matrix_t *A, matrix_t *B, matrix_t *result);
void num_multiplicate(matrix_t *A, double number, matrix_t *result);
int possibility_add(matrix_t *A, matrix_t *B);
void add_logic(matrix_t *A, matrix_t *B, matrix_t *result);
void minus_maker(matrix_t *A, matrix_t *minus);
void complement(matrix_t *A, matrix_t *result);
void det_logic(matrix_t *A, double *result);
void transposer(matrix_t *A, matrix_t *result);

#endif  // SRC_S21_MATRIX_H_