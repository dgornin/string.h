#include "unit_test.h"

START_TEST(simple_u) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_zero_precision_only_dot) {
  char str1[100];
  char str2[100];
  unsigned int num = 0;
  char tmp[] = "!%.u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_n) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%u!\n";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags1) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%-u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags2) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%-+u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags3) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%-+u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags4) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%010u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags5) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%010u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags6) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%-010u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags7) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!% -010u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags8) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!% +010u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags9) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!% 10u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags10) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!% u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_flags11) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!% -10u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_castom_width) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%+*u!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_castom_width2) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%+*u!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_castom_length) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%0*hu!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_castom_length2) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%0*lu!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_precision) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%.11u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_precision_minus) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%.11u!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_castom_precision) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%.*u!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_u_with_castom_precision_and_flags) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%+25.*u!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(flag_mix) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%-+ *.*u!";
  sprintf(str1, tmp, 25, 20, num);
  s21_sprintf(str2, tmp, 25, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_u_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_u");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_u);
  tcase_add_test(tc_core, simple_u_zero_precision_only_dot);
  tcase_add_test(tc_core, simple_u_with_n);
  tcase_add_test(tc_core, simple_u_with_flags1);
  tcase_add_test(tc_core, simple_u_with_flags2);
  tcase_add_test(tc_core, simple_u_with_flags3);
  tcase_add_test(tc_core, simple_u_with_flags4);
  tcase_add_test(tc_core, simple_u_with_flags5);
  tcase_add_test(tc_core, simple_u_with_flags6);
  tcase_add_test(tc_core, simple_u_with_flags7);
  tcase_add_test(tc_core, simple_u_with_flags8);
  tcase_add_test(tc_core, simple_u_with_flags9);
  tcase_add_test(tc_core, simple_u_with_flags10);
  tcase_add_test(tc_core, simple_u_with_flags11);
  tcase_add_test(tc_core, simple_u_with_castom_width);
  tcase_add_test(tc_core, simple_u_with_castom_width2);
  tcase_add_test(tc_core, simple_u_with_castom_length);
  tcase_add_test(tc_core, simple_u_with_castom_length2);
  tcase_add_test(tc_core, simple_u_with_precision);
  tcase_add_test(tc_core, simple_u_with_precision_minus);
  tcase_add_test(tc_core, simple_u_with_castom_precision);
  tcase_add_test(tc_core, simple_u_with_castom_precision_and_flags);
  tcase_add_test(tc_core, flag_mix);

  suite_add_tcase(s, tc_core);
  return s;
}
