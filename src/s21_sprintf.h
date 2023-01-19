#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <wchar.h>

#include "s21_string.h"

enum {
  PLUS_FLAG = 0b00001,   // '+'
  MINUS_FLAG = 0b00010,  // '-'
  SPACE_FLAG = 0b00100,  // ' '
  HASH_FLAG = 0b01000,   // '#'
  ZERO_FLAG = 0b10000    // '0'
};

s21_size_t print_number_signed(char *str, long number, int precision);
s21_size_t print_number_unsigned(char *str, int num_sys, unsigned long number,
                                 int precision, int is_upper);
s21_size_t print_number_float(char *str, long double number, int precision,
                              int keep_same_exp, int *degree);
int get_degree(long double number);
s21_size_t print_number_float_e(char *buf, char e_letter, long double number,
                                int precision);
void apply_width(char *str, s21_size_t *prev_str_len, char *buf,
                 s21_size_t buf_s, int flags, int width);
int str_to_int_with_index(const char *str, int *i);
void parse_flags(const char *format, s21_size_t *prev_i, int *flags, int *width,
                 int *precision, char *length);
int print_str_from_wstr(char *str, wchar_t *wstr);

#endif  // S21_SPRINTF_H
