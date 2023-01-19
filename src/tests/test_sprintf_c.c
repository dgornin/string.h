#include "unit_test.h"

START_TEST(simple_c) {
  char str1[100];
  char str2[100];
  char c = 'a';
  char tmp[] = "!%c!";
  sprintf(str1, tmp, c);
  s21_sprintf(str2, tmp, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_c_with_flag1) {
  char str1[100];
  char str2[100];
  char c = 'a';
  char tmp[] = "!%-10c!";
  sprintf(str1, tmp, c);
  s21_sprintf(str2, tmp, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_c_with_flag2) {
  char str1[100];
  char str2[100];
  char c = 'a';
  char tmp[] = "!%10c!";
  sprintf(str1, tmp, c);
  s21_sprintf(str2, tmp, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_c_with_flag3) {
  char str1[100];
  char str2[100];
  char c = 'a';
  char tmp[] = "!% 10c!";
  sprintf(str1, tmp, c);
  s21_sprintf(str2, tmp, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_c_with_castom_width) {
  char str1[100];
  char str2[100];
  char c = 'a';
  char tmp[] = "!%*c!";
  sprintf(str1, tmp, 10, c);
  s21_sprintf(str2, tmp, 10, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_c_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_c");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_c);
  tcase_add_test(tc_core, simple_c_with_flag1);
  tcase_add_test(tc_core, simple_c_with_flag2);
  tcase_add_test(tc_core, simple_c_with_flag3);
  tcase_add_test(tc_core, simple_c_with_castom_width);

  suite_add_tcase(s, tc_core);
  return s;
}
