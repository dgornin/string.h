#include "unit_test.h"

START_TEST(perc1) {
  int32_t a1, a2;
  int32_t b1 = 80, b2 = 33;
  int32_t c1 = 55, c2 = 33;
  const char str[] = "12 % 13 % 14";
  const char fstr[] = "%d %% %d %% %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(perc2) {
  int32_t a1, a2;
  int32_t b1 = 80, b2 = 33;
  int32_t c1 = 55, c2 = 33;
  const char str[] = "12%13%14";
  const char fstr[] = "%d%%%d%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(perc3) {
  int32_t a1 = 1234, a2 = 33333;

  const char str[] = "%%%16";
  const char fstr[] = "%%%%%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(perc4) {
  const char str[] = "%%%";
  const char fstr[] = "%%%%%%";
  int32_t res1 = s21_sscanf(str, fstr);
  int32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(perc5) {
  int32_t a1 = 1234, a2 = 33333;
  int32_t b1 = 1234, b2 = 33333;

  const char str[] = "%%123%888";
  const char fstr[] = "%%%%%d%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

Suite* s21_sscanf_pr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sscanf_pr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, perc1);
  tcase_add_test(tc_core, perc2);
  tcase_add_test(tc_core, perc3);
  tcase_add_test(tc_core, perc4);
  tcase_add_test(tc_core, perc5);

  suite_add_tcase(s, tc_core);
  return s;
}
