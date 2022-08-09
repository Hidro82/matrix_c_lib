#include "tests.h"

START_TEST(add_test) {
  matrix_t a, b, c, d;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  b.matrix[0][0] = 3;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 1;
  b.matrix[1][0] = 3;
  b.matrix[1][1] = 2;
  b.matrix[1][2] = 1;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 2;
  b.matrix[2][2] = 1;
  d.matrix[0][0] = 4;
  d.matrix[0][1] = 4;
  d.matrix[0][2] = 4;
  d.matrix[1][0] = 4;
  d.matrix[1][1] = 4;
  d.matrix[1][2] = 4;
  d.matrix[2][0] = 4;
  d.matrix[2][1] = 4;
  d.matrix[2][2] = 4;
  int res = s21_sum_matrix(&a, &b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(sub_test) {
  matrix_t a, b, c, d;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  b.matrix[0][0] = 3;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 1;
  b.matrix[1][0] = 3;
  b.matrix[1][1] = 2;
  b.matrix[1][2] = 1;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 2;
  b.matrix[2][2] = 1;
  d.matrix[0][0] = -2;
  d.matrix[0][1] = 0;
  d.matrix[0][2] = 2;
  d.matrix[1][0] = -2;
  d.matrix[1][1] = 0;
  d.matrix[1][2] = 2;
  d.matrix[2][0] = -2;
  d.matrix[2][1] = 0;
  d.matrix[2][2] = 2;
  int res = s21_sub_matrix(&a, &b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(mul_num) {
  matrix_t a, c, d;
  double b = 2;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  d.matrix[0][0] = 2;
  d.matrix[0][1] = 4;
  d.matrix[0][2] = 6;
  d.matrix[1][0] = 2;
  d.matrix[1][1] = 4;
  d.matrix[1][2] = 6;
  d.matrix[2][0] = 2;
  d.matrix[2][1] = 4;
  d.matrix[2][2] = 6;
  int res = s21_mult_number(&a, b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(mul_matrix) {
  matrix_t a, b, c, d;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 4, &b);
  s21_create_matrix(2, 4, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  b.matrix[0][0] = 3;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 1;
  b.matrix[0][3] = 1;
  b.matrix[1][0] = 3;
  b.matrix[1][1] = 2;
  b.matrix[1][2] = 1;
  b.matrix[1][3] = 1;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 2;
  b.matrix[2][2] = 1;
  b.matrix[2][3] = 1;
  d.matrix[0][0] = 18;
  d.matrix[0][1] = 12;
  d.matrix[0][2] = 6;
  d.matrix[0][3] = 6;
  d.matrix[1][0] = 18;
  d.matrix[1][1] = 12;
  d.matrix[1][2] = 6;
  d.matrix[1][3] = 6;
  int res = s21_mult_matrix(&a, &b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(trans_test) {
  matrix_t a, c, d;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  d.matrix[0][0] = 1;
  d.matrix[0][1] = 1;
  d.matrix[1][0] = 2;
  d.matrix[1][1] = 2;
  d.matrix[2][0] = 3;
  d.matrix[2][1] = 3;
  int res = s21_transpose(&a, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(inv_test) {
  matrix_t a, c, d;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  d.matrix[0][0] = -1.0 / 6;
  d.matrix[0][1] = 0;
  d.matrix[0][2] = 1.0 / 6;
  d.matrix[1][0] = -1.0 / 3;
  d.matrix[1][1] = 1.0 / 3;
  d.matrix[1][2] = 0;
  d.matrix[2][0] = 11.0 / 18;
  d.matrix[2][1] = -2.0 / 9;
  d.matrix[2][2] = -1.0 / 18;
  int res = s21_inverse_matrix(&a, &c);
  printf("matrix_c:\n");
  matrix_print(&c);
  printf("matrix_d:\n");
  matrix_print(&d);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(eq_test) {
  matrix_t a, c;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &c);
  a.matrix[0][0] = NAN;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0;
  c.matrix[0][0] = NAN;
  c.matrix[0][1] = 1;
  c.matrix[1][0] = 0;
  c.matrix[1][1] = 0;
  int res = s21_eq_matrix(&a, &c);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_test) {
  matrix_t a;
  double b;
  s21_create_matrix(5, 5, &a);
  a.matrix[0][0] = -1;
  a.matrix[0][1] = 20;
  a.matrix[1][1] = 40;
  a.matrix[1][3] = -2;
  a.matrix[2][1] = 5;
  a.matrix[2][2] = -45;
  a.matrix[3][3] = 60;
  a.matrix[3][4] = 6;
  a.matrix[4][3] = 8;
  s21_determinant(&a, &b);
  ck_assert_double_eq_tol(b, -86400, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(subnormal) {
  matrix_t a = {0, 2, 3}, b = {0, 0, 0}, c, d = {0, 2, 2};
  double i = 0;
  int res = s21_sum_matrix(&a, &b, &c);
  ck_assert_int_eq(res, 1);
  res = s21_sum_matrix(&a, &b, NULL);
  ck_assert_int_eq(res, 1);
  res = s21_sum_matrix(&a, &d, &c);
  ck_assert_int_eq(res, 1);
  res = s21_sub_matrix(&a, &b, &c);
  ck_assert_int_eq(res, 1);
  res = s21_sub_matrix(&a, &b, NULL);
  ck_assert_int_eq(res, 1);
  res = s21_sub_matrix(&a, &d, &c);
  ck_assert_int_eq(res, 1);
  res = s21_mult_number(&a, i, NULL);
  ck_assert_int_eq(res, 1);
  res = s21_mult_number(&b, i, &c);
  ck_assert_int_eq(res, 1);
  res = s21_mult_matrix(&a, &b, &c);
  ck_assert_int_eq(res, 1);
  res = s21_mult_matrix(NULL, &d, &c);
  ck_assert_int_eq(res, 1);
  res = s21_mult_matrix(&a, &d, &c);
  ck_assert_int_eq(res, 1);
  res = s21_transpose(&a, NULL);
  ck_assert_int_eq(res, 1);
  res = s21_transpose(NULL, &c);
  ck_assert_int_eq(res, 1);
  res = s21_inverse_matrix(&a, NULL);
  ck_assert_int_eq(res, 1);
  res = s21_inverse_matrix(&a, &c);
  ck_assert_int_eq(res, 1);
  res = s21_determinant(&a, NULL);
  ck_assert_int_eq(res, 1);
  res = s21_determinant(&a, &i);
  ck_assert_int_eq(res, 1);
  res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(res, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, add_test);
  tcase_add_test(tc1_1, sub_test);
  tcase_add_test(tc1_1, mul_num);
  tcase_add_test(tc1_1, mul_matrix);
  tcase_add_test(tc1_1, trans_test);
  tcase_add_test(tc1_1, inv_test);
  tcase_add_test(tc1_1, eq_test);
  tcase_add_test(tc1_1, det_test);
  tcase_add_test(tc1_1, subnormal);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}