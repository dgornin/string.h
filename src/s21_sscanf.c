#include "s21_sscanf.h"

int s21_sscanf(const char* str, const char* format, ...) {
  char* string = (char*)str;
  int argno = 0;
  if (*str) {
    va_list ap;
    va_start(ap, format);

    token tokens[BUFF_SIZE] = {0};
    int tokens_n = 0;

    char* format_string = (char*)format;

    tokenize(format_string, tokens, &tokens_n);

    scan(tokens, tokens_n, string, &argno, ap);

    va_end(ap);

  } else {
    argno = -1;
  }
  return argno;
}

void scan(token* tokens, int tokens_n, char* string, int* argno, va_list ap) {
  int flag = 1;
  s21_size_t string_len = s21_strlen(string);
  for (int i = 0; i < tokens_n && flag; i++) {
    while (flag && tokens[i].str != s21_NULL && tokens[i].len_str != 0 &&
           *string != '\0') {
      if (!check_spaces(*string)) {
        if (*string == *(tokens[i].str)) {
          string++;
          tokens[i].str++;
          tokens[i].len_str--;
          while (check_spaces(*string)) {
            string++;
          }
        } else {
          flag = 0;
        }
      } else {
        string++;
      }
    }
    if (flag) {
      while ((check_spaces(*string) &&
              (tokens[i].was_space == 1 || !(tokens[i].type == 'c'))) ||
             (*string == '%' && tokens[i].skip_percent == 1)) {
        string++;
      }
      if (tokens[i].type != 0) {
        handle_decimal(tokens, i, &string, ap, argno, &flag);
        handle_i(tokens, i, &string, ap, argno, &flag);
        handle_unsigned(tokens, i, &string, ap, argno, &flag);
        handle_hex(tokens, i, &string, ap, argno, &flag);
        handle_o(tokens, i, &string, ap, argno, &flag);
        handle_char(tokens, i, &string, ap, argno);
        handle_string(tokens, i, &string, ap, argno, &flag);
        handle_pointer(tokens, i, &string, ap, argno, &flag);
        handle_n(tokens, i, &string, ap, string_len);
        handle_float(tokens, i, &string, ap, argno, &flag);
      }
    }
  }
}

void handle_decimal(token* tokens, int i, char** string, va_list ap, int* argno,
                    int* flag) {
  if (tokens[i].type == 'd') {
    *flag = if_valid_decimal(*string, tokens[i].width);
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
      read_number(tokens[i], string, ap, 10);
    }
  }
}

void handle_i(token* tokens, int i, char** string, va_list ap, int* argno,
              int* flag) {
  if (tokens[i].type == 'i') {
    int base = 0;
    *flag = check_if_valid_i(*string, tokens[i].width, &base);
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
      read_number(tokens[i], string, ap, base);
    }
  }
}

void handle_unsigned(token* tokens, int i, char** string, va_list ap,
                     int* argno, int* flag) {
  if (tokens[i].type == 'u') {
    *flag = if_valid_decimal(*string, tokens[i].width);
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
      read_number_unsigned(tokens[i], string, ap, 10);
    }
  }
}

void handle_hex(token* tokens, int i, char** string, va_list ap, int* argno,
                int* flag) {
  if (tokens[i].type == 'x' || tokens[i].type == 'X') {
    *flag = if_valid_hex(*string, tokens[i].width);
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
      read_number_unsigned(tokens[i], string, ap, 16);
    }
  }
}

void handle_o(token* const tokens, int i, char** string, va_list ap, int* argno,
              int* flag) {
  if (tokens[i].type == 'o') {
    *flag = if_valid_octal(*string, tokens[i].width);
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
      read_number_unsigned(tokens[i], string, ap, 8);
    }
  }
}

void handle_char(token* tokens, int i, char** string, va_list ap, int* argno) {
  if (tokens[i].type == 'c') {
    if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
    if (tokens[i].width_type == WIDTH_STAR) {
      (*string)++;
    } else if (tokens[i].width_type == WIDTH_NUMBER) {
      if (tokens[i].width == 0) {
        tokens[i].width = 1;
      }
      if (tokens[i].length_type == LENGTH_NONE) {
        char* arg = va_arg(ap, char*);
        s21_strncpy(arg, *string, tokens[i].width);
        arg[tokens[i].width] = '\0';
        (*string) += tokens[i].width;
      } else if (tokens[i].length_type == LENGTH_l) {
        wchar_t* arg = va_arg(ap, wchar_t*);
        mbstowcs(arg, *string, tokens[i].width);
        arg[tokens[i].width] = '\0';
        (*string) += tokens[i].width;
      }
    } else {
      if (tokens[i].length_type == LENGTH_NONE) {
        char* arg = va_arg(ap, char*);
        *arg = **string;
        (*string)++;
      } else if (tokens[i].length_type == LENGTH_l) {
        wchar_t* arg = va_arg(ap, wchar_t*);
        mbstowcs(arg, *string, 1);
        (*string)++;
      }
    }
  }
}

void handle_string(token* tokens, int i, char** string, va_list ap, int* argno,
                   int* flag) {
  if (tokens[i].type == 's') {
    if (**string == '\0') *flag = 0;
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) (*argno)++;
      if (tokens[i].width_type == WIDTH_STAR) {
        // skip string
        while (**string != '\0' && !check_spaces(**string)) {
          (*string)++;
        }
      } else {
        if (tokens[i].length_type == LENGTH_NONE) {
          char* arg = va_arg(ap, char*);
          unsigned int j = 0;
          while ((j < tokens[i].width || tokens[i].width_type == WIDTH_NONE) &&
                 **string != '\0' && !check_spaces(**string)) {
            arg[j] = **string;
            j++;
            (*string)++;
          }
          arg[j] = '\0';
        } else if (tokens[i].length_type == LENGTH_l) {
          wchar_t* arg = va_arg(ap, wchar_t*);
          unsigned int j = 0;
          while ((j < tokens[i].width || tokens[i].width_type == WIDTH_NONE) &&
                 !check_spaces(**string) && **string != '\0') {
            mbstowcs(&arg[j], *string, 1);
            j++;
            (*string)++;
          }
          arg[j] = '\0';
        }
      }
      while (**string == ' ') {
        (*string)++;
      }
    }
  }
}

void handle_n(token* tokens, int i, char** string, va_list ap,
              s21_size_t string_len) {
  if (tokens[i].type == 'n') {
    int* arg = va_arg(ap, int*);
    s21_size_t cur_len = s21_strlen(*string);
    *arg = string_len - cur_len;
  }
}

void handle_pointer(token* tokens, int i, char** string, va_list ap, int* argno,
                    int* flag) {
  if (tokens[i].type == 'p') {
    *flag = if_valid_hex(*string, tokens[i].width);
    if (*flag) {
      if (tokens[i].width_type != WIDTH_STAR) {
        (*argno)++;
      }
      if (tokens[i].width_type == WIDTH_STAR) {
        // skip pointer
        skip_hex_num(string, 0);
      } else {
        // add 0x to string and then read_number_unsigned
        char* tmp = (char*)malloc((s21_strlen(*string) + 3) * sizeof(char));
        tmp[0] = '0';
        tmp[1] = 'x';
        tmp[2] = '\0';
        s21_strcpy(tmp + 2, *string);
        read_number_unsigned(tokens[i], string, ap, 16);
        free(tmp);
      }
    }
  }
}

void handle_float(token* tokens, int i, char** string, va_list ap, int* argno,
                  int* flag) {
  if (s21_strchr(float_flags, tokens[i].type) != s21_NULL) {
    *flag = if_valid_float(*string, tokens[i].width);
    if (*flag) {
      if (tokens[i].width_type == WIDTH_STAR) {
        *string = skip_float(*string, tokens[i].width);
      } else {
        (*argno)++;
        void* arg = va_arg(ap, void*);
        char* tmp = s21_NULL;
        if (tokens[i].width_type == WIDTH_NUMBER) {
          tmp = (char*)malloc((tokens[i].width + 1) * sizeof(char));
          s21_strncpy(tmp, *string,
                      tokens[i].width > s21_strlen(*string)
                          ? s21_strlen(*string)
                          : tokens[i].width);
          tmp[tokens[i].width > s21_strlen(*string) ? s21_strlen(*string)
                                                    : tokens[i].width] = '\0';
        } else {
          tmp = (char*)malloc((s21_strlen(*string) + 1) * sizeof(char));
          s21_strcpy(tmp, *string);
        }
        if (tokens[i].length_type == LENGTH_L)
          *((long double*)arg) = (long double)s21_atold(tmp);
        else if (tokens[i].length_type == LENGTH_l)
          *((double*)arg) = (double)s21_atold(tmp);
        else
          *((float*)arg) = (float)s21_atold(tmp);
        if (tmp) free(tmp);
        *string = skip_float(*string, tokens[i].width);
      }
    }
  }
}

void read_number_unsigned(token token, char** string, va_list ap, int base) {
  if (token.width_type == WIDTH_STAR) {
    skip_num(string, base, BUFF_SIZE);
  } else {
    if (token.length_type == LENGTH_NONE) {
      if (token.width_type == WIDTH_NUMBER) {
        unsigned int* arg = va_arg(ap, unsigned int*);
        char* tmp = (char*)malloc((token.width + 1) * sizeof(char));
        s21_strncpy(tmp, *string, token.width);
        tmp[token.width] = '\0';
        *arg = s21_strtol(tmp, base);
        free(tmp);
        skip_num(string, base, token.width);
      } else {
        unsigned int* arg = va_arg(ap, unsigned int*);
        *arg = s21_strtol(*string, base);
        skip_num(string, base, BUFF_SIZE);
      }
    } else if (token.length_type == LENGTH_l) {
      if (token.width_type == WIDTH_NUMBER) {
        unsigned long* arg = va_arg(ap, unsigned long*);
        char* tmp = (char*)malloc((token.width + 1) * sizeof(char));
        s21_strncpy(tmp, *string, token.width);
        tmp[token.width] = '\0';
        *arg = s21_strtol(tmp, base);
        free(tmp);
        skip_num(string, base, token.width);
      } else {
        unsigned long* arg = va_arg(ap, unsigned long*);
        *arg = s21_strtol(*string, base);
        skip_num(string, base, BUFF_SIZE);
      }
    } else if (token.length_type == LENGTH_h) {
      if (token.width_type == WIDTH_NUMBER) {
        unsigned short* arg = va_arg(ap, unsigned short*);
        char* tmp = (char*)malloc((token.width + 1) * sizeof(char));
        s21_strncpy(tmp, *string, token.width);
        tmp[token.width] = '\0';
        *arg = s21_strtol(tmp, base);
        free(tmp);
        skip_num(string, base, token.width);
      } else {
        unsigned short* arg = va_arg(ap, unsigned short*);
        *arg = s21_strtol(*string, base);
        skip_num(string, base, BUFF_SIZE);
      }
    }
  }
}

void read_number(token token, char** string, va_list ap, int base) {
  if (token.width_type == WIDTH_STAR) {
    skip_num(string, base, BUFF_SIZE);
  } else {
    if (token.length_type == LENGTH_NONE) {
      if (token.width_type == WIDTH_NUMBER) {
        int* arg = va_arg(ap, int*);
        char* tmp = (char*)malloc((token.width + 1) * sizeof(char));
        s21_strncpy(tmp, *string, token.width);
        tmp[token.width] = '\0';
        *arg = s21_strtol(tmp, base);
        free(tmp);
        skip_num(string, base, token.width);
      } else {
        int* arg = va_arg(ap, int*);
        *arg = s21_strtol(*string, base);
        skip_num(string, base, BUFF_SIZE);
      }
    } else if (token.length_type == LENGTH_l) {
      if (token.width_type == WIDTH_NUMBER) {
        long* arg = va_arg(ap, long*);
        char* tmp = (char*)malloc((token.width + 1) * sizeof(char));
        s21_strncpy(tmp, *string, token.width);
        tmp[token.width] = '\0';
        *arg = s21_strtol(tmp, base);
        free(tmp);
        skip_num(string, base, token.width);
      } else {
        long* arg = va_arg(ap, long*);
        *arg = s21_strtol(*string, base);
        skip_num(string, base, BUFF_SIZE);
      }
    } else if (token.length_type == LENGTH_h) {
      if (token.width_type == WIDTH_NUMBER) {
        short* arg = va_arg(ap, short*);
        char* tmp = (char*)malloc((token.width + 1) * sizeof(char));
        s21_strncpy(tmp, *string, token.width);
        tmp[token.width] = '\0';
        *arg = s21_strtol(tmp, base);
        free(tmp);
        skip_num(string, base, token.width);
      } else {
        short* arg = va_arg(ap, short*);
        *arg = s21_strtol(*string, base);
        skip_num(string, base, BUFF_SIZE);
      }
    }
  }
}

void skip_num(char** string, int base, int width) {
  if (base == 10) {
    skip_decimal_num(string, width);
  } else if (base == 16) {
    skip_hex_num(string, width);
  } else if (base == 8) {
    skip_octal_num(string, width);
  }
}

void skip_hex_num(char** string, int width) {
  int pre_flag = 0;
  if (width == 0) width--;
  if ((**string == '+' || **string == '-') && width != 1) {
    if ((*(*string + 1) >= '0' && *(*string + 1) <= '9') ||
        (*(*string + 1) >= 'a' && *(*string + 1) <= 'f') ||
        (*(*string + 1) >= 'A' && *(*string + 1) <= 'F')) {
      (*string)++;
      width--;
    }
  }
  if (**string == '0' && width != 0) {
    (*string)++;
    pre_flag = 1;
  }
  if ((**string == 'x' || **string == 'X') && width != 1 && pre_flag) {
    if ((*(*string + 1) >= '0' && *(*string + 1) <= '9') ||
        (*(*string + 1) >= 'a' && *(*string + 1) <= 'f') ||
        (*(*string + 1) >= 'A' && *(*string + 1) <= 'F')) {
      (*string) += 2;
      width -= 2;
    }
  }
  while (((**string >= '0' && **string <= '9') ||
          (**string >= 'a' && **string <= 'f') ||
          (**string >= 'A' && **string <= 'F')) &&
         width != 0) {
    (*string)++;
    width--;
  }
}

void skip_octal_num(char** string, int width) {
  if ((**string == '+' || **string == '-') && width != 1) {
    if (*(*string + 1) >= '0' && *(*string + 1) <= '7') {
      (*string) += 2;
      width -= 2;
    }
  }
  while ((**string >= '0' && **string <= '7') && width != 0) {
    (*string)++;
    width--;
  }
}

void skip_decimal_num(char** string, int width) {
  if ((**string == '+' || **string == '-') && width != 1) {
    if (*(*string + 1) >= '0' && *(*string + 1) <= '9') {
      (*string) += 2;
      width -= 2;
    }
  }
  while ((**string >= '0' && **string <= '9') && width != 0) {
    (*string)++;
    width--;
  }
}

void tokenize(char* format_string, token* tokens, int* tokens_count) {
  int i = 0;                            // index for format_string
  int j = 0;                            // index for tokens
  int len = s21_strlen(format_string);  // TO CHANGE
  while (i < len) {
    if (format_string[i] == '%') {
      i++;
      if (format_string[i] == '*') {
        tokens[j].width_type = WIDTH_STAR;
        tokens[j].width = 0;
        i++;
      } else if (format_string[i] >= '0' && format_string[i] <= '9') {
        tokens[j].width_type = WIDTH_NUMBER;
        tokens[j].width = 0;
        while (format_string[i] >= '0' && format_string[i] <= '9') {
          tokens[j].width = tokens[j].width * 10 + (format_string[i] - '0');
          i++;
        }
      } else {
        tokens[j].width_type = WIDTH_NONE;
        tokens[j].width = 0;
      }

      tokens[j].length_type = parse_length(format_string, &i);

      if (format_string[i] == '%') {
        tokens[j].skip_percent = 1;
        i++;
      } else {
        tokens[j].type = format_string[i];
        i++;
        j++;
      }
    } else {
      skip_spaces(format_string, &i, tokens, j);
      if (tokens[j].type == 0 && format_string[i] != '%') {
        tokens[j].str = &format_string[i];
        tokens[j].len_str = 1;
        i++;

        tokens[j].was_space = 0;

        while (format_string[i] != '%' && i < len) {
          if (check_spaces(format_string[i])) {
            skip_spaces(format_string, &i, tokens, j);
            break;
          }
          tokens[j].len_str++;
          i++;
        }
      }
    }
  }
  *tokens_count = j;
}

int parse_length(char* format_string, int* i) {
  int length = 0;
  if (format_string[*i] == 'h') {
    length = LENGTH_h;
    (*i)++;
  } else if (format_string[*i] == 'l') {
    length = LENGTH_l;
    (*i)++;
  } else if (format_string[*i] == 'L') {
    length = LENGTH_L;
    (*i)++;
  } else {
    length = LENGTH_NONE;
  }
  return length;
}

int check_if_valid_i(char* str, int width, int* base) {
  int flag = 1;
  if (*str == '0') {
    if (*(str + 1) == 'x' || *(str + 1) == 'X') {
      flag = if_valid_hex(str, width);
      *base = 16;
    } else {
      flag = if_valid_octal(str, width);
      *base = 8;
    }
  } else {
    flag = if_valid_decimal(str, width);
    *base = 10;
  }
  return flag;
}

int if_valid_decimal(char* str, int width) {
  int flag = 1;
  if (width == 0) width--;
  if (*str == '+' || *str == '-') {
    if (width == 1)
      flag = 0;
    else if (!(*(str + 1) >= '0' && *(str + 1) <= '9'))
      flag = 0;
  } else if (!(*(str) >= '0' && *(str) <= '9'))
    flag = 0;
  return flag;
}

int if_valid_float(char* str, int width) {
  int flag = 1;
  if (width == 0) width--;
  if (width == 1 && (*str == '-' || *str == '+'))
    flag = 0;
  else if ((*str == '-' || *str == '+') && (width > 1 || width < 0) &&
           (!(*(str + 1) >= '0' && *(str + 1) <= '9') && !(*(str + 1) == '.')))
    flag = 0;
  else if ((*str == '-' || *str == '+') && (*(str + 1) == '.')) {
    if (width == 2) flag = 0;
    if (*(str + 2)) {
      if (!(*(str + 2) >= '0' && *(str + 2) <= '9')) flag = 0;
    } else
      flag = 0;
  } else if (*str == '.' && width == 1)
    flag = 0;
  else if (*str == '.' && (width > 1 || width < 0) &&
           !(*(str + 1) >= '0' && *(str + 1) <= '9'))
    flag = 0;
  else if (!(*str >= '0' && *str <= '9') && !(*str == '.') && !(*str == '-') &&
           !(*str == '+'))
    flag = 0;
  else if ((*str == '+' && *(str + 1) == '-') ||
           (*str == '-' && *(str + 1) == '+'))
    flag = 0;
  return flag;
}

int if_valid_hex(char* str, int width) {
  int flag = 1;
  if (width == 0) width--;
  if (*str == '-' || *str == '+') {
    if (width == 1)
      flag = 0;
    else if (!((*(str + 1) >= '0' && *(str + 1) <= '9') ||
               (*(str + 1) >= 'A' && *(str + 1) <= 'F') ||
               (*(str + 1) >= 'a' && *(str + 1) <= 'f')))
      flag = 0;
  } else if (!((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'F') ||
               (*str >= 'a' && *str <= 'f')))
    flag = 0;
  return flag;
}

int if_valid_octal(char* str, int width) {
  int flag = 1;
  if (width == 0) width--;
  if (*str == '-' || *str == '+') {
    if (width == 1)
      flag = 0;
    else if (!(*(str + 1) >= '0' && *(str + 1) <= '7'))
      flag = 0;
  } else if (!(*str >= '0' && *str <= '7'))
    flag = 0;
  return flag;
}

char* skip_float(char* str, int width) {
  int flag = 0, point_flag = 0;
  if (width == 0) width--;
  if ((*str == '+' || *str == '-') && width != 1) {
    if (*(str + 1) >= '0' && *(str + 1) <= '9') {
      width -= 2;
      str += 2;
    } else if (*(str + 1) == '.' && width != 2) {
      if (*(str + 2)) {
        if (*(str + 2) >= '0' && *(str + 2) <= '9') {
          width -= 2;
          str += 2;
          point_flag = 1;
        }
      }
    }
  }
  while (*str >= '0' && *str <= '9' && width != 0) {  // skip digits
    str++;
    flag = 1;
    width--;
  }
  if (*str == '.' && !point_flag && width != 0) {
    if (flag == 1)
      str++;
    else if (*(str + 1) >= '0' && *(str + 1) <= '9' && width != 1)
      str++;
    width--;
  }
  while (*str >= '0' && *str <= '9' && width != 0) {  // skip digits
    str++;
    flag = 1;
    width--;
  }
  if ((*str == 'e' || *str == 'E') && flag && width != 1 && width != 0) {
    if (*(str + 1) >= '0' && *(str + 1) <= '9') {
      str += 2;
      width -= 2;
    } else if ((*(str + 1) == '-' || *(str + 1) == '+') && width != 2) {
      if (*(str + 2)) {
        if (*(str + 2) >= '0' && *(str + 2) <= '9') {
          str += 3;
          width -= 3;
        }
      }
    }
  }
  while (*str >= '0' && *str <= '9' && width != 0) {  // skip digits
    str++;
    width--;
  }
  return str;
}

void skip_spaces(char* format_string, int* i, token* tokens, int j) {
  while (check_spaces(format_string[*i])) {
    (*i)++;
    tokens[j].was_space = 1;
  }
}

int check_spaces(char c) {
  int ret = 0;
  if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
      c == '\r') {
    ret = 1;
  }
  return ret;
}
