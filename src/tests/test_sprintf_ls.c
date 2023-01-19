#include "unit_test.h"

START_TEST(simple_ls) {
  char str1[100];
  char str2[100];
  wchar_t tmp[] = L"abcd";
  char format[] = "!%ls!";
  sprintf(str1, format, tmp);
  s21_sprintf(str2, format, tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_ls_custom_width) {
  char str1[100];
  char str2[100];
  wchar_t tmp[] = L"abcd";
  char format[] = "!%*ls!";
  sprintf(str1, format, 15, tmp);
  s21_sprintf(str2, format, 15, tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_ls_with_flags1) {
  char str1[100];
  char str2[100];
  wchar_t tmp[] = L"abcd";
  char format[] = "!%11ls!";
  sprintf(str1, format, tmp);
  s21_sprintf(str2, format, tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_ls_with_flags2) {
  char str1[100];
  char str2[100];
  wchar_t tmp[] = L"abcd";
  char format[] = "!%-11ls!";
  sprintf(str1, format, tmp);
  s21_sprintf(str2, format, tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_ls_with_flags3) {
  char str1[100];
  char str2[100];
  wchar_t tmp[] = L"abcdaaaaaaaaaaaaaaa";
  char format[] = "!%11ls!";
  sprintf(str1, format, tmp);
  s21_sprintf(str2, format, tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_ls_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_ls");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_ls);
  tcase_add_test(tc_core, simple_ls_custom_width);
  tcase_add_test(tc_core, simple_ls_with_flags1);
  tcase_add_test(tc_core, simple_ls_with_flags2);
  tcase_add_test(tc_core, simple_ls_with_flags3);

  suite_add_tcase(s, tc_core);
  return s;
}
