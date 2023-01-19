#include "unit_test.h"

START_TEST(spec_i_int1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 -600 +700";
  const char fstr[] = "%li %li %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700 111";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int3) {
  long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700+400";
  const char fstr[] = "%li%c%li%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0xFFF 0xA123123 0x123123 0x0";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(simple_hex_i) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  const char str[] = "00 0b";
  const char fstr[] = "%hi %hi";
  uint32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  uint32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(simple_hex_i2) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  const char str[] = "X5 0b";
  const char fstr[] = "%hi %hi";
  uint32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  uint32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(simple_octal_i) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  const char str[] = "\t 015 -13";
  const char fstr[] = "%hi %1hi";
  uint32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  uint32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(simple_octal_i2) {
  short int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  const char str[] = "\t 015 -13";
  const char fstr[] = "%hi %1hi";
  uint32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  uint32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

Suite* s21_sscanf_i_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sscanf_i");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, spec_i_int1);
  tcase_add_test(tc_core, spec_i_int2);
  tcase_add_test(tc_core, spec_i_int3);
  tcase_add_test(tc_core, spec_i_int4);
  tcase_add_test(tc_core, spec_i_hex1);
  tcase_add_test(tc_core, spec_i_hex2);
  tcase_add_test(tc_core, spec_i_oct1);
  tcase_add_test(tc_core, spec_i_oct2);
  tcase_add_test(tc_core, simple_hex_i);
  tcase_add_test(tc_core, simple_hex_i2);
  tcase_add_test(tc_core, simple_octal_i);
  tcase_add_test(tc_core, simple_octal_i2);

  suite_add_tcase(s, tc_core);
  return s;
}
