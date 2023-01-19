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

START_TEST(floats4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[] = "%*f %f %f %3f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(floats5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "-53.1 !+4.1135 +-411231.333 +2.0001";
  const char fstr[] = "%*f !%f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(floats6) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "-. !+4.a1135 +-411231.333 +2.0001";
  const char fstr[] = "%2f !%3f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(floats7) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "+.3 -2 !+ +-411231.333 +2.0001";
  const char fstr[] = "%*f %2f !%1f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(floats8) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "e3123 -2 !+ +-411231.333 +2.0001";
  const char fstr[] = "%*f %2f !%1f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(floats9) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "e-3312 -2 !+ +-411231.333 +2.0001";
  const char fstr[] = "%*f %2f !%1f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq_tol(c1, c2, 1e-7);
}
END_TEST

START_TEST(floats10) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "3e12 3e-31 2e+13 3e123";
  const char fstr[] = "%*f %lf %lf %lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq_tol(a1, a2, 1e-7);
  ck_assert_float_eq_tol(b1, b2, 1e-7);
  ck_assert_float_eq(c1, c2);
}
END_TEST

Suite* s21_sscanf_f_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sscanf_f");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, floats1);
  tcase_add_test(tc_core, floats2);
  tcase_add_test(tc_core, floats3);
  tcase_add_test(tc_core, floats4);
  tcase_add_test(tc_core, floats5);
  tcase_add_test(tc_core, floats6);
  tcase_add_test(tc_core, floats7);
  tcase_add_test(tc_core, floats8);
  tcase_add_test(tc_core, floats9);
  tcase_add_test(tc_core, floats10);

  suite_add_tcase(s, tc_core);
  return s;
}
