#include "unit_test.h"

START_TEST(simple_d) {
  char str1[100];
  char str2[100];
  int num = 1024;
  char tmp[] = "!%d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_n) {
  char str1[100];
  char str2[100];
  int num = 1024;
  char tmp[] = "!%d!\n";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags1) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!%-d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags2) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!%-+d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags3) {
  char str1[100];
  char str2[100];
  int num = 1024;
  char tmp[] = "!%-+d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags4) {
  char str1[100];
  char str2[100];
  int num = 1024;
  char tmp[] = "!%010d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags5) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!%010d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags6) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!%-010d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags7) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!% -010d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags8) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!% +010d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags9) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!% 10d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags10) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!% d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_flags11) {
  char str1[100];
  char str2[100];
  int num = 1024;
  char tmp[] = "!% -10d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_castom_width) {
  char str1[100];
  char str2[100];
  int num = 1024;
  char tmp[] = "!%+*d!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_castom_width2) {
  char str1[100];
  char str2[100];
  int num = -1024;
  char tmp[] = "!%+*d!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_castom_length) {
  char str1[100];
  char str2[100];
  unsigned int num = 1024;
  char tmp[] = "!%0*hd!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_castom_length2) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%0*ld!";
  sprintf(str1, tmp, 11, num);
  s21_sprintf(str2, tmp, 11, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_precision) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%.11d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_precision_minus) {
  char str1[100];
  char str2[100];
  unsigned long int num = -1024;
  char tmp[] = "!%.11d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_castom_precision) {
  char str1[100];
  char str2[100];
  unsigned long int num = -1024;
  char tmp[] = "!%.*d!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_with_castom_precision_and_flags) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%+25.*d!";
  sprintf(str1, tmp, 20, num);
  s21_sprintf(str2, tmp, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(flag_mix) {
  char str1[100];
  char str2[100];
  unsigned long int num = 1024;
  char tmp[] = "!%-+ *.*d!";
  sprintf(str1, tmp, 25, 20, num);
  s21_sprintf(str2, tmp, 25, 20, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(simple_d_zero_precision_zero_number) {
  char str1[100];
  char str2[100];
  unsigned long int num = 0;
  char tmp[] = "!%.d!";
  sprintf(str1, tmp, num);
  s21_sprintf(str2, tmp, num);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* s21_print_d_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_print_d");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, simple_d);
  tcase_add_test(tc_core, simple_d_with_n);
  tcase_add_test(tc_core, simple_d_with_flags1);
  tcase_add_test(tc_core, simple_d_with_flags2);
  tcase_add_test(tc_core, simple_d_with_flags3);
  tcase_add_test(tc_core, simple_d_with_flags4);
  tcase_add_test(tc_core, simple_d_with_flags5);
  tcase_add_test(tc_core, simple_d_with_flags6);
  tcase_add_test(tc_core, simple_d_with_flags7);
  tcase_add_test(tc_core, simple_d_with_flags8);
  tcase_add_test(tc_core, simple_d_with_flags9);
  tcase_add_test(tc_core, simple_d_with_flags10);
  tcase_add_test(tc_core, simple_d_with_flags11);
  tcase_add_test(tc_core, simple_d_with_castom_width);
  tcase_add_test(tc_core, simple_d_with_castom_width2);
  tcase_add_test(tc_core, simple_d_with_castom_length);
  tcase_add_test(tc_core, simple_d_with_castom_length2);
  tcase_add_test(tc_core, simple_d_with_precision);
  tcase_add_test(tc_core, simple_d_with_precision_minus);
  tcase_add_test(tc_core, simple_d_with_castom_precision);
  tcase_add_test(tc_core, simple_d_with_castom_precision_and_flags);
  tcase_add_test(tc_core, flag_mix);
  tcase_add_test(tc_core, simple_d_zero_precision_zero_number);

  suite_add_tcase(s, tc_core);
  return s;
}
