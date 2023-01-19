#include "unit_test.h"

START_TEST(floats1) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "0.00001 -4123123 4. .";
  const char fstr[] = "%lf %lf %lf %lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(a1, a2, 1e-7);
  ck_assert_double_eq_tol(b1, b2, 1e-7);
  ck_assert_double_eq_tol(c1, c2, 1e-7);
  ck_assert_double_eq_tol(d1, d2, 1e-7);
}
END_TEST

START_TEST(floats2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = ". . . .";
  const char fstr[] = "%f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(a1, a2, 1e-7);
  ck_assert_double_eq_tol(b1, b2, 1e-7);
  ck_assert_double_eq_tol(c1, c2, 1e-7);
  ck_assert_double_eq_tol(d1, d2, 1e-7);
}
END_TEST

START_TEST(floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[] = "%*f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(e1) {
  float b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  double d1 = 0, d2 = 0;
  const char str[] = "15 12e3 12 e";
  const char fstr[] = "%*f %e %lf %f";

  int16_t res1 = s21_sscanf(str, fstr, &b1, &d1, &c1);
  int16_t res2 = sscanf(str, fstr, &b2, &d2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_double_eq_tol(d1, d2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(e2) {
  float c1 = 0, c2 = 0;
  double d1 = 0, d2 = 0;
  long double a1 = 0, a2 = 0;
  const char str[] = "-.5e 12e3 12 e";
  const char fstr[] = "%3Le %lf %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &d1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &d2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_double_eq_tol(d1, d2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(e3) {
  float b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  double d1 = 0, d2 = 0;
  const char str[] = "-.5e1 12e3 12 e";
  const char fstr[] = "%*e %le %e %1e";

  int16_t res1 = s21_sscanf(str, fstr, &d1, &c1, &b1);
  int16_t res2 = sscanf(str, fstr, &d2, &c2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(d1, d2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
}
END_TEST

START_TEST(simple_e) {
  double a1 = 0, a2 = 0;
  const char str[] = "-.031";
  const char fstr[] = "%7le";

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(a1, a2, 1e-7);
}
END_TEST
/*
START_TEST(e_with_point1) {
  float f1 = 0, f2 = 0;
  double a1 = 0, a2 = 0;
  long double b1 = 0, b2 = 0;
  char k1 = 0, k2 = 0;
  const char str[] = "15E.2 -15-3";
  const char fstr[] = "%e%c %LE %lG";

  int16_t res1 = s21_sscanf(str, fstr, &f1, &k1, &b1, &a1);
  int16_t res2 = sscanf(str, fstr, &f2, &k2, &b2, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(f1, f2, 1e-7);
  ck_assert_int_eq(k1, k2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_double_eq_tol(a1, a2, 1e-7);
}
END_TEST
*/
START_TEST(e_with_point2) {
  float f1 = 0, f2 = 0;
  double a1 = 0, a2 = 0;
  long double b1 = 0, b2 = 0;
  char k1 = 0, k2 = 0;
  const char str[] = "15E-2 -15-3";
  const char fstr[] = "%e %c %LE %lG";

  int16_t res1 = s21_sscanf(str, fstr, &f1, &k1, &b1, &a1);
  int16_t res2 = sscanf(str, fstr, &f2, &k2, &b2, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(f1, f2, 1e-7);
  ck_assert_int_eq(k1, k2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_double_eq_tol(a1, a2, 1e-7);
}
END_TEST

Suite* s21_sscanf_e_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sscanf_e");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, floats1);
  tcase_add_test(tc_core, floats2);
  tcase_add_test(tc_core, floats3);
  tcase_add_test(tc_core, e1);
  tcase_add_test(tc_core, e2);
  tcase_add_test(tc_core, e3);
  tcase_add_test(tc_core, simple_e);
  // tcase_add_test(tc_core, e_with_point1);
  tcase_add_test(tc_core, e_with_point2);

  suite_add_tcase(s, tc_core);
  return s;
}
