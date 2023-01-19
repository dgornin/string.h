#include "unit_test.h"

START_TEST(simple_x) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_n) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%x!\n";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_flags1) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%-x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_flags4) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%020x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_flags5) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%020x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_flags6) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%-020x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_flags9) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!% 20x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

END_TEST

START_TEST(simple_x_with_castom_width) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%*x!";
  sprintf(str1, tmp, 25, num);
  s21_sprintf(str2, tmp, 25, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_castom_length) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%0*hx!";
  sprintf(str1, tmp, 25, num);
  s21_sprintf(str2, tmp, 25, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_castom_length2) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%0*lx!";
  sprintf(str1, tmp, 25, num);
  s21_sprintf(str2, tmp, 25, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_xrecision) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%.25x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_xrecision_minus) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%.25x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_castom_xrecision) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%.*x!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_with_castom_xrecision_and_flags) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  char tmp[] = "!%25.*x!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_wiht_hash1) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%#x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_wiht_hash2) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%#.25x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_wiht_hash3) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%#25x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_wiht_hash4) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%-#25x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_wiht_hash5) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%-#.25x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_wiht_hash6) {
  char str1[100];
  char str2[100];
  unsigned long num = 1024;
  ;
  char tmp[] = "!%-#x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_x_zero_precision_zero_number) {
  char str1[100];
  char str2[100];
  unsigned long num = 0;
  ;
  char tmp[] = "!%#.0x!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_x_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_x");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_x);
  tcase_add_test(tc_core, simple_x_with_n);
  tcase_add_test(tc_core, simple_x_with_flags1);
  tcase_add_test(tc_core, simple_x_with_flags4);
  tcase_add_test(tc_core, simple_x_with_flags5);
  tcase_add_test(tc_core, simple_x_with_flags6);
  tcase_add_test(tc_core, simple_x_with_flags9);
  tcase_add_test(tc_core, simple_x_with_castom_width);
  tcase_add_test(tc_core, simple_x_with_castom_length);
  tcase_add_test(tc_core, simple_x_with_castom_length2);
  tcase_add_test(tc_core, simple_x_with_xrecision);
  tcase_add_test(tc_core, simple_x_with_xrecision_minus);
  tcase_add_test(tc_core, simple_x_with_castom_xrecision);
  tcase_add_test(tc_core, simple_x_with_castom_xrecision_and_flags);
  tcase_add_test(tc_core, simple_x_wiht_hash1);
  tcase_add_test(tc_core, simple_x_wiht_hash2);
  tcase_add_test(tc_core, simple_x_wiht_hash3);
  tcase_add_test(tc_core, simple_x_wiht_hash4);
  tcase_add_test(tc_core, simple_x_wiht_hash5);
  tcase_add_test(tc_core, simple_x_wiht_hash6);
  tcase_add_test(tc_core, simple_x_zero_precision_zero_number);

  suite_add_tcase(s, tc_core);
  return s;
}
