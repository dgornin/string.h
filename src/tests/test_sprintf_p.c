#include "unit_test.h"

START_TEST(simple_p) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  ;
  char tmp[] = "!%p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_n) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%p!\n";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_flags1) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%-p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_flags4) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%020p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_flags5) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%020p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_flags6) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%-020p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_flags9) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!% 20p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

END_TEST

START_TEST(simple_p_with_castom_width) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%*p!";
  sprintf(str1, tmp, 25, num);
  s21_sprintf(str2, tmp, 25, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_castom_length) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%0*hp!";
  sprintf(str1, tmp, 25, num);
  s21_sprintf(str2, tmp, 25, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_castom_length2) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%0*lp!";
  sprintf(str1, tmp, 25, num);
  s21_sprintf(str2, tmp, 25, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_precision) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%.25p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_precision_minus) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%.25p!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_castom_precision) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%.*p!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_p_with_castom_precision_and_flags) {
  char str1[100];
  char str2[100];
  char num[] = "abc";
  char tmp[] = "!%25.*p!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_p_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_p");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_p);
  tcase_add_test(tc_core, simple_p_with_n);
  tcase_add_test(tc_core, simple_p_with_flags1);
  tcase_add_test(tc_core, simple_p_with_flags4);
  tcase_add_test(tc_core, simple_p_with_flags5);
  tcase_add_test(tc_core, simple_p_with_flags6);
  tcase_add_test(tc_core, simple_p_with_flags9);
  tcase_add_test(tc_core, simple_p_with_castom_width);
  tcase_add_test(tc_core, simple_p_with_castom_length);
  tcase_add_test(tc_core, simple_p_with_castom_length2);
  tcase_add_test(tc_core, simple_p_with_precision);
  tcase_add_test(tc_core, simple_p_with_precision_minus);
  tcase_add_test(tc_core, simple_p_with_castom_precision);
  tcase_add_test(tc_core, simple_p_with_castom_precision_and_flags);

  suite_add_tcase(s, tc_core);
  return s;
}
