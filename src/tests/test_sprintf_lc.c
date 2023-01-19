#include "unit_test.h"

START_TEST(simple_lc) {
  char str1[100];
  char str2[100];
  wchar_t c = L'a';
  char format[] = "!%lc!";
  sprintf(str1, format, c);
  s21_sprintf(str2, format, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_lc_with_flag1) {
  char str1[100];
  char str2[100];
  wchar_t c = L'a';
  char format[] = "!%-10lc!";
  sprintf(str1, format, c);
  s21_sprintf(str2, format, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_lc_with_flag2) {
  char str1[100];
  char str2[100];
  wchar_t c = L'a';
  char format[] = "!%10lc!";
  sprintf(str1, format, c);
  s21_sprintf(str2, format, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_lc_with_flag3) {
  char str1[100];
  char str2[100];
  wchar_t c = L'a';
  char format[] = "!% 10lc!";
  sprintf(str1, format, c);
  s21_sprintf(str2, format, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_lc_with_castom_width) {
  char str1[100];
  char str2[100];
  wchar_t c = L'a';
  char format[] = "!%*lc!";
  sprintf(str1, format, 10, c);
  s21_sprintf(str2, format, 10, c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_lc_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_lc");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_lc);
  tcase_add_test(tc_core, simple_lc_with_flag1);
  tcase_add_test(tc_core, simple_lc_with_flag2);
  tcase_add_test(tc_core, simple_lc_with_flag3);
  tcase_add_test(tc_core, simple_lc_with_castom_width);

  suite_add_tcase(s, tc_core);
  return s;
}
