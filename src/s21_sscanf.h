#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"
#include "str_to_num.h"

#define float_flags "eEfgG"
#define BUFF_SIZE 512

typedef enum width_type { WIDTH_NONE, WIDTH_STAR, WIDTH_NUMBER } width_type;

typedef enum length_type {
  LENGTH_NONE,
  LENGTH_h,  // short int or unsigned short int
  LENGTH_l,  // long int or unsigned long int
  LENGTH_L   // long double
} length_type;

// __prev_string__%[*][width][length]specifier
typedef struct token {
  char* str;                // prev string
  size_t len_str;           // length of prev string
  int was_space;            // 1 if prev string was ended with space
  width_type width_type;    // * or number
  unsigned int width;       // number
  length_type length_type;  // h, l, L
  int type;                 // specifier
  int skip_percent;         // 1 if % was skipped
} token;

void tokenize(char* format_string, token* tokens, int* tokens_count);
int parse_length(char* format_string, int* i);
void print_token(token* t);
void skip_spaces(char* format_string, int* i, token* tokens, int j);
char* skip_int(char* str);
char* skip_float(char* str, int width);
void scan(token* tokens, int tokens_n, char* string, int* argno, va_list ap);
int check_if_valid_i(char* str, int width, int* base);
int check_spaces(char c);
int if_valid_float(char* str, int width);
int if_valid_octal(char* str, int width);
int if_valid_hex(char* str, int width);
int if_valid_decimal(char* str, int width);
void read_number_unsigned(token token, char** string, va_list ap, int base);
void read_number(token token, char** string, va_list ap, int base);
void skip_num(char** string, int base, int width);
void skip_decimal_num(char** string, int width);
void skip_hex_num(char** string, int width);
void skip_octal_num(char** string, int width);
void handle_decimal(token* tokens, int i, char** string, va_list ap, int* argno,
                    int* flag);
void handle_i(token* tokens, int i, char** string, va_list ap, int* argno,
              int* flag);
void handle_unsigned(token* tokens, int i, char** string, va_list ap,
                     int* argno, int* flag);
void handle_hex(token* tokens, int i, char** string, va_list ap, int* argno,
                int* flag);
void handle_o(token* tokens, int i, char** string, va_list ap, int* argno,
              int* flag);
void handle_char(token* tokens, int i, char** string, va_list ap, int* argno);
void handle_string(token* tokens, int i, char** string, va_list ap, int* argno,
                   int* flag);
void handle_pointer(token* tokens, int i, char** string, va_list ap, int* argno,
                    int* flag);
void handle_n(token* tokens, int i, char** string, va_list ap,
              s21_size_t string_len);
void handle_float(token* tokens, int i, char** string, va_list ap, int* argno,
                  int* flag);

#endif  // S21_SSCANF_H
