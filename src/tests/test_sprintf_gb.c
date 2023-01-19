#include "unit_test.h"

START_TEST(simple_f) {
  char str1[100];
  char str2[100];
  double d = 1.0;
  char format[] = "!%G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_Lf) {
  char str1[100];
  char str2[100];
  long double d = 1.0;
  char format[] = "!%LG!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(negative_f) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!%G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(equal_precision) {
  char str1[100];
  char str2[100];
  double d = 1.312;
  char format[] = "!%.3G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(more_precision) {
  char str1[100];
  char str2[100];
  double d = 1.312;
  char format[] = "!%.6G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision) {
  char str1[100];
  char str2[100];
  double d = 1.312;
  char format[] = "!%.0G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_and_precision) {
  char str1[100];
  char str2[100];
  double d = 1.312;
  char format[] = "!%3.2G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_and_precision_with_big_number) {
  char str1[100];
  char str2[100];
  double d = 1244121.312;
  char format[] = "!%3.2G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(only_width_with_small) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!%3G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flag_plus) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!%+G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flag_space) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!% G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!%30G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_zero) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!%030G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_plus) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!%+30G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_plus_minus) {
  char str1[100];
  char str2[100];
  double d = 1.00000001;
  char format[] = "!%+-30G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_zero_minus_neg) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!%-030G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_neg) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!%30G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_zero_neg) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!%030G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_plus_neg) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!%+30G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_space_neg) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!% G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_width_space_plus) {
  char str1[100];
  char str2[100];
  double d = -1.00000001;
  char format[] = "!% +G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(round_precision) {
  char str1[100];
  char str2[100];
  double d = 3.1235;
  char format[] = "!%.3G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(round_with_nine) {
  char str1[100];
  char str2[100];
  double d = 3.1299;
  char format[] = "!%.3G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(round_all_nines) {
  char str1[100];
  char str2[100];
  double d = 9.9999;
  char format[] = "!%.3G!";
  sprintf(str1, format, d);
  s21_sprintf(str2, format, d);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite* s21_print_gb_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_gb");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_f);
  tcase_add_test(tc_core, simple_Lf);
  tcase_add_test(tc_core, negative_f);
  tcase_add_test(tc_core, equal_precision);
  tcase_add_test(tc_core, more_precision);
  tcase_add_test(tc_core, zero_precision);
  tcase_add_test(tc_core, width_and_precision);
  tcase_add_test(tc_core, width_and_precision_with_big_number);
  tcase_add_test(tc_core, only_width_with_small);
  tcase_add_test(tc_core, flag_plus);
  tcase_add_test(tc_core, flag_space);
  tcase_add_test(tc_core, big_width);
  tcase_add_test(tc_core, big_width_zero);
  tcase_add_test(tc_core, big_width_plus);
  tcase_add_test(tc_core, big_width_plus_minus);
  tcase_add_test(tc_core, big_width_zero_minus_neg);
  tcase_add_test(tc_core, big_width_neg);
  tcase_add_test(tc_core, big_width_zero_neg);
  tcase_add_test(tc_core, big_width_plus_neg);
  tcase_add_test(tc_core, big_width_space_neg);
  tcase_add_test(tc_core, big_width_space_plus);
  tcase_add_test(tc_core, round_precision);
  tcase_add_test(tc_core, round_with_nine);
  tcase_add_test(tc_core, round_all_nines);

  suite_add_tcase(s, tc_core);
  return s;
}
