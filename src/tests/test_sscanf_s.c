#include "unit_test.h"

START_TEST(strings1) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings2) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings3) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings4) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings5) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings6) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings7) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "abc   def\n \t \n \r \t\f\v\r123  -   456";
  const char fstr[] = "%s%s%s - %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

START_TEST(strings8) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "abc\r\tdef\v\n \t \nabc\r \t\f\v\r123\f  -   456";
  const char fstr[] = "%s%s%*s%s - %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

START_TEST(strings9) {
  wchar_t s1[100] = {'\0'};
  wchar_t s2[100] = {'\0'};
  wchar_t s3[100] = {'\0'};
  wchar_t s4[100] = {'\0'};
  wchar_t s5[100] = {'\0'};
  wchar_t s6[100] = {'\0'};
  wchar_t s7[100] = {'\0'};
  wchar_t s8[100] = {'\0'};

  const char str[] = "abc\r\tdef\v\n \t \nabc\r \t\f\v\r123\f  -   456";
  const char fstr[] = "%ls%ls%*s%ls - %ls";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);
  ck_assert_mem_eq(s1, s5, sizeof(wchar_t) * 100);
  ck_assert_mem_eq(s2, s6, sizeof(wchar_t) * 100);
  ck_assert_mem_eq(s3, s7, sizeof(wchar_t) * 100);
  ck_assert_mem_eq(s4, s8, sizeof(wchar_t) * 100);
}

START_TEST(string10) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};
  char s5[100] = {'\0'};
  char s6[100] = {'\0'};
  char s7[100] = {'\0'};
  char s8[100] = {'\0'};

  const char str[] = "  abc  def 123  -   456";
  const char fstr[] = "%3s%2s%100s %*s - %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

START_TEST(string11) {
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  char s3[100] = {'\0'};
  char s4[100] = {'\0'};

  const char str[] = "456";
  const char fstr[] = "%s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2);
  int16_t res2 = sscanf(str, fstr, s3, s4);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s3);
  ck_assert_str_eq(s2, s4);
}

Suite* s21_sscanf_s_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sscanf_s");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, strings1);
  tcase_add_test(tc_core, strings2);
  tcase_add_test(tc_core, strings3);
  tcase_add_test(tc_core, strings4);
  tcase_add_test(tc_core, strings5);
  tcase_add_test(tc_core, strings6);
  tcase_add_test(tc_core, strings7);
  tcase_add_test(tc_core, strings8);
  tcase_add_test(tc_core, strings9);
  tcase_add_test(tc_core, string10);
  tcase_add_test(tc_core, string11);

  suite_add_tcase(s, tc_core);
  return s;
}
