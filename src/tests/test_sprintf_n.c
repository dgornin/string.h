#include "unit_test.h"

START_TEST(simple_n) {
  char str1[100];
  char str2[100];
  int n1;
  int n2;
  sprintf(str1, "!%n!", &n1);
  s21_sprintf(str2, "!%n!", &n2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(simple_n_with_end) {
  char str1[100];
  char str2[100];
  int n1;
  int n2;
  sprintf(str1, "!!!%n", &n1);
  s21_sprintf(str2, "!!!%n", &n2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(simple_n_with_more_char) {
  char str1[100];
  char str2[100];
  int n1;
  int n2;
  sprintf(str1, "!fmewfewfewfewf%n!", &n1);
  s21_sprintf(str2, "!fmewfewfewfewf%n!", &n2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(simple_n_with_zero) {
  char str1[100];
  char str2[100];
  int n1;
  int n2;
  sprintf(str1, "%n!", &n1);
  s21_sprintf(str2, "%n!", &n2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite* s21_print_n_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_n");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_n);
  tcase_add_test(tc_core, simple_n_with_end);
  tcase_add_test(tc_core, simple_n_with_more_char);
  tcase_add_test(tc_core, simple_n_with_zero);

  suite_add_tcase(s, tc_core);
  return s;
}
