#include "unit_test.h"

START_TEST(upeer_hex_base_version) {
  uint32_t a1 = 0, a2 = 0;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_short) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_longlong) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upper_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(simple_hex_test1) {
  uint32_t a1 = 0, a2 = 0;
  const char str[] = " \n +";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(simple_hex_test2) {
  uint32_t a1 = 0, a2 = 0;
  const char str[] = " \n +l";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(simple_hex_test3) {
  uint32_t a1 = 0, a2 = 0;
  const char str[] = " \n\t\r\t 0";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(simple_hex_test4) {
  uint32_t a1 = 0, a2 = 0;
  char c1 = 0, c2 = 0;
  const char str[] = " \n\t\r\t +l";
  const char fstr[] = "%1X%c";
  uint32_t res1 = s21_sscanf(str, fstr, &a1, &c1);
  uint32_t res2 = sscanf(str, fstr, &a2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

// START_TEST(simple_hex_test5) {
//   uint32_t a1 = 0, a2 = 0;
//   char c1 = 0, c2 = 0;
//   const char str[] = " \n\t\r\t 0xXc";
//   const char fstr[] = "%X%c";
//   uint32_t res1 = s21_sscanf(str, fstr, &a1, &c1);
//   uint32_t res2 = sscanf(str, fstr, &a2, &c2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(a1, a2);
//   ck_assert_int_eq(c1, c2);
// }
// END_TEST

START_TEST(simple_hex_test6) {
  uint32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  const char str[] = "0xXC 0xFF 15";
  const char fstr[] = "%*X %X %X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  uint32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

Suite* s21_sscanf_xb_suite(void) {
  Suite* s;
  TCase* tc_core;

  s = suite_create("s21_sscanf_xb");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, upeer_hex_base_version);
  tcase_add_test(tc_core, upeer_hex_overflow);
  tcase_add_test(tc_core, upeer_hex_0x);
  tcase_add_test(tc_core, upeer_hex_0X);
  tcase_add_test(tc_core, upeer_hex_empty);
  tcase_add_test(tc_core, upeer_hex_fail);
  tcase_add_test(tc_core, upeer_hex_spaces_tabs_sns);
  tcase_add_test(tc_core, upeer_hex_short);
  tcase_add_test(tc_core, upeer_hex_long);
  tcase_add_test(tc_core, upeer_hex_longlong);
  tcase_add_test(tc_core, upeer_hex_2x);
  tcase_add_test(tc_core, upeer_hex_star);
  tcase_add_test(tc_core, upeer_hex_nohex);
  tcase_add_test(tc_core, upeer_hex_lower);
  tcase_add_test(tc_core, upeer_hex_sign);
  tcase_add_test(tc_core, upper_hex_len);
  tcase_add_test(tc_core, simple_hex_test1);
  tcase_add_test(tc_core, simple_hex_test2);
  tcase_add_test(tc_core, simple_hex_test3);
  tcase_add_test(tc_core, simple_hex_test4);
  //  tcase_add_test(tc_core, simple_hex_test5);
  tcase_add_test(tc_core, simple_hex_test6);

  suite_add_tcase(s, tc_core);
  return s;
}
