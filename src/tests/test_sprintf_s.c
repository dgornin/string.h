#include "unit_test.h"

START_TEST(simple_s) {
  char str1[100];
  char str2[100];
  char tmp[] = "abcd";
  sprintf(str1, "!%s!", tmp);
  s21_sprintf(str2, "!%s!", tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_s_custom_width) {
  char str1[100];
  char str2[100];
  char tmp[] = "abcd";
  sprintf(str1, "!%*s!", 15, tmp);
  s21_sprintf(str2, "!%*s!", 15, tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_s_with_flags1) {
  char str1[100];
  char str2[100];
  char tmp[] = "abcd";
  sprintf(str1, "!%11s!", tmp);
  s21_sprintf(str2, "!%11s!", tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_s_with_flags2) {
  char str1[100];
  char str2[100];
  char tmp[] = "abcd";
  sprintf(str1, "!%-11s!", tmp);
  s21_sprintf(str2, "!%-11s!", tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_s_with_flags3) {
  char str1[100];
  char str2[100];
  char tmp[] = "abcdaaaaaaaaaaaaaaa";
  sprintf(str1, "!%11s!", tmp);
  s21_sprintf(str2, "!%11s!", tmp);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_s_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_s");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_s);
  tcase_add_test(tc_core, simple_s_custom_width);
  tcase_add_test(tc_core, simple_s_with_flags1);
  tcase_add_test(tc_core, simple_s_with_flags2);
  tcase_add_test(tc_core, simple_s_with_flags3);

  suite_add_tcase(s, tc_core);
  return s;
}
