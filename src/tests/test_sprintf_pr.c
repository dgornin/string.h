#include "unit_test.h"

START_TEST(simple_pr) {
  char str1[100];
  char str2[100];
  sprintf(str1, "!%%!");
  s21_sprintf(str2, "!%%!");
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_pr_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_pr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_pr);

  suite_add_tcase(s, tc_core);
  return s;
}
