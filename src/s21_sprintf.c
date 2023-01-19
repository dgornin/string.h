#include "s21_sprintf.h"

s21_size_t print_number_signed(char *str, long number, int precision) {
  char tmp[100] = "";
  char num_chars[] = "0123456789abcdef";
  s21_size_t i = 0;
  int minus_f = 0;
  if (number < 0) {
    number = -number;
    minus_f = 1;
  }
  do {
    tmp[i++] = num_chars[number % 10];
    number /= 10;
  } while (number > 0);
  int zero_c = precision - i;
  for (int j = 0; j < zero_c; j++) tmp[i++] = '0';
  if (minus_f) tmp[i++] = '-';
  for (int j = i - 1; j >= 0; j--) {
    str[i - 1 - j] = tmp[j];
  }
  return i;
}

s21_size_t print_number_unsigned(char *str, int num_sys, unsigned long number,
                                 int precision, int is_upper) {
  char tmp[100] = "";
  char num_chars[] = "0123456789abcdef";
  if (is_upper) s21_strcpy(num_chars, "0123456789ABCDEF");
  s21_size_t i = 0;
  do {
    tmp[i++] = num_chars[number % num_sys];
    number /= num_sys;
  } while (number > 0);
  int zero_c = precision - i;
  for (int j = 0; j < zero_c; j++) tmp[i++] = '0';
  for (int j = i - 1; j >= 0; j--) {
    str[i - 1 - j] = tmp[j];
  }
  return i;
}

s21_size_t print_number_float(char *str, long double number, int precision,
                              int keep_same_exp, int *degree) {
  char num_chars[] = "0123456789";
  s21_size_t i = 0;
  if (number < 0) {
    number = -number;
    str[i++] = '-';
  }
  s21_size_t start = i;
  int all_nines = 1;
  if (number == 0.0) {
    all_nines = 0;
    str[i++] = '0';
  } else {
    do {
      int height = (int)trunc(log10(number));
      int symbol = (int)trunc(number / pow(10, height));
      str[i++] = num_chars[symbol % 10];
      if (symbol % 10 != 9) {
        all_nines = 0;
      }
      number -= symbol * pow(10, height);
    } while (number >= 1.0f);
  }
  if (precision < 0) {
    precision = 6;
  }
  s21_size_t dot_pos = 0;
  if (precision > 0) {
    dot_pos = i;
    str[i++] = '.';
    for (int j = -1; j >= -precision; j--) {
      int symbol = (int)trunc(number / pow(10, j));
      str[i++] = num_chars[symbol % 10];
      number -= symbol * pow(10, j);
      if (symbol % 10 != 9) {
        all_nines = 0;
      }
    }
  }
  double next_digit = trunc(number * pow(10, precision + 1));
  if (next_digit >= 5.0) {
    if (all_nines) {
      *degree += 1;
      str[start] = '1';
      for (s21_size_t j = start + 1; j < i + 1; j++) {
        str[j] = '0';
      }
      if (!keep_same_exp) {
        str[i++] = '0';
      }
      if (dot_pos) {
        if (keep_same_exp) {
          str[dot_pos] = '.';
        } else {
          str[dot_pos + 1] = '.';
        }
      }
    } else {
      int stop = 0;
      for (s21_size_t j = i - 1; !stop && j >= start; j--) {
        if (str[j] != '.') {
          str[j] = (str[j] - '0' + 1) % 10 + '0';
          if (str[j] != '0') {
            stop = 1;
          }
        }
      }
    }
  }
  str[i] = '\0';

  return i;
}

int get_degree(long double number) {
  int ret = 0;
  if (number < 0) {
    number = -number;
  }
  while (number >= 10.0) {
    ret++;
    number /= 10;
  }
  while (number < 1.0 && number > 0.0) {
    ret--;
    number *= 10;
  }
  return ret;
}

s21_size_t print_number_float_e(char *buf, char e_letter, long double number,
                                int precision) {
  int degree = get_degree(number);
  number /= pow(10, degree);
  s21_size_t buf_s = print_number_float(buf, number, precision, 1, &degree);
  buf[buf_s++] = e_letter;
  if (degree < 0) {
    buf[buf_s++] = '-';
    degree = -degree;
  } else {
    buf[buf_s++] = '+';
  }
  if (degree < 10) {
    buf[buf_s++] = '0';
  }
  buf_s += print_number_signed(buf + buf_s, degree, 1);
  buf[buf_s] = '\0';
  return buf_s;
}

void apply_width(char *str, s21_size_t *prev_str_len, char *buf,
                 s21_size_t buf_s, int flags, int width) {
  int str_len = *prev_str_len;
  int zero_c = width - buf_s;
  int plus_s = 0;
  if (flags & PLUS_FLAG) {  // +
    if (buf[0] != '-') {
      if (zero_c > 0 && !(flags & MINUS_FLAG)) {
        plus_s = 1;
        zero_c--;
      } else {
        str[str_len++] = '+';
        zero_c--;
      }
    }
  }
  if ((flags & SPACE_FLAG) && !(flags & PLUS_FLAG)) {  // ' '
    if (buf[0] != '-') {
      str[str_len++] = ' ';
      zero_c--;
    }
  }
  if (zero_c > 0) {
    if (flags & MINUS_FLAG) {  // -
      s21_memcpy(str + str_len, buf, buf_s);
      str_len += buf_s;
      for (int j = 0; j < zero_c; j++) str[str_len++] = ' ';
    } else {
      char del = ' ';
      char *tm = buf;
      if (flags & ZERO_FLAG) del = '0';
      if (buf[0] == '-' && (flags & ZERO_FLAG)) {
        str[str_len++] = '-';
        buf_s--;
        tm++;
      }
      for (int j = 0; j < zero_c; j++) str[str_len++] = del;
      if (plus_s) str[str_len++] = '+';
      str[str_len] = '\0';
      s21_memcpy(str + str_len, tm, buf_s);
      str_len += buf_s;
    }
  } else {
    s21_memcpy(str + str_len, buf, buf_s);
    str_len += buf_s;
  }
  *prev_str_len = str_len;
}

int str_to_int_with_index(const char *str, int *i) {
  int ret = 0;
  while (str[*i] >= '0' && str[*i] <= '9') {
    ret = ret * 10 + str[(*i)++] - '0';
  }
  return ret;
}

void parse_flags(const char *format, s21_size_t *prev_i, int *flags, int *width,
                 int *precision, char *length) {
  int i = *prev_i;
  i++;
  while (format[i] == '+' || format[i] == '-' || format[i] == ' ' ||
         format[i] == '#' || format[i] == '0') {
    switch (format[i]) {  // Флаги
      case '+': {
        i++;
        *flags |= PLUS_FLAG;
        break;
      }
      case '-': {
        i++;
        *flags |= MINUS_FLAG;
        break;
      }
      case ' ': {
        i++;
        *flags |= SPACE_FLAG;
        break;
      }
      case '#': {
        i++;
        *flags |= HASH_FLAG;
        break;
      }
      case '0': {
        i++;
        *flags |= ZERO_FLAG;
        break;
      }
    }
  }
  if (format[i] >= '0' && format[i] <= '9') {  // Ширина
    *width = str_to_int_with_index(format, &i);
  } else if (format[i] == '*') {
    i++;
    *width = -1;
  }
  if (format[i] == '.') {  // Точность
    i++;
    if (format[i] >= '0' && format[i] <= '9') {
      *precision = str_to_int_with_index(format, &i);
    } else if (format[i] == '*') {
      *precision = -1;
      i++;
    } else {
      *precision = 0;
    }
  }
  switch (format[i]) {  // Длина
    case 'h': {
      *length = 'h';
      i++;
      break;
    }
    case 'l': {
      *length = 'l';
      i++;
      break;
    }
    case 'L': {
      *length = 'L';
      i++;
      break;
    }
  }
  *prev_i = i;
}

int print_str_from_wstr(char *str, wchar_t *wstr) {
  int i = 0;
  int j = 0;
  int count = 0;
  do {
    i += count;
    count = wcrtomb(&str[i], wstr[j++], NULL);
  } while (str[i]);
  return i;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  s21_size_t format_len = s21_strlen(format), str_len = 0;
  int error = 0;
  *str = '\0';
  for (s21_size_t i = 0; !error && i < format_len; i++) {
    if (format[i] == '%') {
      int flags = 0;
      char length = 0;
      int width = 0, precision = -2;
      char buf[1024] = "";
      int buf_s = 0;
      parse_flags(format, &i, &flags, &width, &precision, &length);
      if (width == -1) width = va_arg(ap, int);
      if (precision == -1) precision = va_arg(ap, int);
      switch (format[i]) {  // Спецификаторы
        case 'c': {         // done
          char tmp_buf[9] = {0};
          int tmp_buf_s = 0;
          if (length == 'l') {
            wchar_t arg[2] = {0};
            arg[0] = va_arg(ap, wchar_t);
            tmp_buf_s = print_str_from_wstr(tmp_buf, arg);
          } else {
            tmp_buf[0] = va_arg(ap, int);
            tmp_buf_s = 1;
          }
          int zero_c = width - tmp_buf_s;
          char del = ' ';
          if (flags & ZERO_FLAG) del = '0';
          if (zero_c > 0 && !(flags & MINUS_FLAG)) {
            for (int j = 0; j < zero_c; j++) str[str_len++] = del;
            for (int j = 0; j < tmp_buf_s; j++) str[str_len++] = tmp_buf[j];
          } else if (flags & MINUS_FLAG) {
            for (int j = 0; j < tmp_buf_s; j++) str[str_len++] = tmp_buf[j];
            for (int j = 0; j < zero_c; j++) str[str_len++] = del;
          } else {
            for (int j = 0; j < tmp_buf_s; j++) str[str_len++] = tmp_buf[j];
          }
          break;
        }
        case 'i':    // done
        case 'd': {  // done
          long number;
          if (length == 'h') {
            number = (short)va_arg(ap, int);
          } else if (length == 'l') {
            number = va_arg(ap, long);
          } else {
            number = va_arg(ap, int);
          }
          if (precision || number) {
            buf_s = print_number_signed(buf, number, precision);
          } else {
            buf_s = 0;
          }
          buf[buf_s] = '\0';
          apply_width(str, &str_len, buf, buf_s, flags, width);
          break;
        }
        case 'e':
        case 'E': {
          long double number;
          if (length == 'L') {
            number = va_arg(ap, long double);
          } else {
            number = va_arg(ap, double);
          }
          buf_s = print_number_float_e(buf, format[i], number, precision);
          apply_width(str, &str_len, buf, buf_s, flags, width);
          break;
        }
        case 'f': {
          long double number;
          if (length == 'L') {
            number = va_arg(ap, long double);
          } else {
            number = va_arg(ap, double);
          }
          int trash_var = 0;
          buf_s = print_number_float(buf, number, precision, 0, &trash_var);
          apply_width(str, &str_len, buf, buf_s, flags, width);
          break;
        }
        case 'g':
        case 'G': {
          long double number;
          if (length == 'L') {
            number = va_arg(ap, long double);
          } else {
            number = va_arg(ap, double);
          }
          int degree = 0;
          int new_precision =
              precision - (int)trunc(log10(number > 0 ? number : -number) + 1);
          if (new_precision < 0) {
            new_precision = precision;
          }
          buf_s = print_number_float(buf, number, new_precision, 0, &degree);
          if (s21_strchr(buf, '.')) {
            while (buf[buf_s - 1] == '0') {
              buf_s--;
            }
            if (buf[buf_s - 1] == '.') {
              buf_s--;
            }
            buf[buf_s] = '\0';
          }
          char tmp_buf[1024];
          char e_letter;
          if (format[i] == 'G') {
            e_letter = 'E';
          } else {
            e_letter = 'e';
          }
          int tmp_buf_s =
              print_number_float_e(tmp_buf, e_letter, number, precision - 1);
          if (tmp_buf_s < buf_s) {
            apply_width(str, &str_len, tmp_buf, tmp_buf_s, flags, width);
          } else {
            apply_width(str, &str_len, buf, buf_s, flags, width);
          }
          break;
        }
        case 'o': {
          unsigned long number;
          if (length == 'h') {
            number = (unsigned short)va_arg(ap, unsigned int);
          } else if (length == 'l') {
            number = va_arg(ap, unsigned long);
          } else {
            number = va_arg(ap, unsigned int);
          }
          buf_s = print_number_unsigned(buf, 8, number, precision, 0);
          int zero_c = width - buf_s;
          if (!(buf[0] == '0' && !(flags & HASH_FLAG) && precision == 0)) {
            if (buf[0] == '0') flags &= ~HASH_FLAG;
            if (flags & HASH_FLAG) zero_c -= 1;
            if (zero_c > 0) {
              if (flags & MINUS_FLAG) {  // -
                if (flags & HASH_FLAG) str[str_len++] = '0';
                s21_memcpy(str + str_len, buf, buf_s);
                str_len += buf_s;
                for (int j = 0; j < zero_c; j++) str[str_len++] = ' ';
              } else {
                char del = ' ';
                if (flags & ZERO_FLAG) del = '0';
                for (int j = 0; j < zero_c; j++) str[str_len++] = del;
                if (flags & HASH_FLAG) str[str_len++] = '0';
                s21_memcpy(str + str_len, buf, buf_s);
                str_len += buf_s;
              }
            } else {
              if (flags & HASH_FLAG) str[str_len++] = '0';
              s21_memcpy(str + str_len, buf, buf_s);
              str_len += buf_s;
            }
          }
          break;
        }
        case 's': {  // done
          char *arg = s21_NULL;
          int arg_n = 0;
          int set_free = 0;
          if (length == 'l') {
            arg_n = print_str_from_wstr(&str[str_len], va_arg(ap, wchar_t *));
            arg = (char *)malloc(arg_n + 1);
            s21_strcpy(arg, &str[str_len]);
            set_free = 1;
            str[str_len] = '\0';
          } else {
            arg = va_arg(ap, char *);
            arg_n = s21_strlen(arg);
          }
          int zero_c = width - arg_n;
          char del = ' ';
          if (flags & ZERO_FLAG) del = '0';
          if (zero_c > 0 && !(flags & MINUS_FLAG)) {
            for (int j = 0; j < zero_c; j++) str[str_len++] = del;
            s21_memcpy(str + str_len, arg, arg_n);
            str_len += arg_n;
          } else if (flags & MINUS_FLAG) {
            s21_memcpy(str + str_len, arg, arg_n);
            str_len += arg_n;
            for (int j = 0; j < zero_c; j++) str[str_len++] = del;
          } else {
            s21_memcpy(str + str_len, arg, arg_n);
            str_len += arg_n;
          }
          if (set_free) free(arg);
          break;
        }
        case 'u': {
          unsigned long number;
          if (length == 'h') {
            number = (unsigned short)va_arg(ap, unsigned int);
          } else if (length == 'l') {
            number = va_arg(ap, unsigned long);
          } else {
            number = va_arg(ap, unsigned int);
          }
          if (flags & SPACE_FLAG) flags &= ~SPACE_FLAG;
          if (flags & PLUS_FLAG) flags &= ~PLUS_FLAG;
          if (precision || number) {
            buf_s = print_number_unsigned(buf, 10, number, precision, 0);
          } else {
            buf_s = 0;
          }
          buf[buf_s] = '\0';
          apply_width(str, &str_len, buf, buf_s, flags, width);
          break;
        }
        case 'X':    // done
        case 'x':    // done
        case 'p': {  // done
          unsigned long number;
          if (format[i] == 'x') {
            if (length == 'l')
              number = va_arg(ap, unsigned long);
            else
              number = va_arg(ap, unsigned);
          } else if (format[i] == 'X') {
            if (length == 'l')
              number = va_arg(ap, unsigned long);
            else
              number = va_arg(ap, unsigned);
          } else {
            number = (unsigned long)va_arg(ap, void *);
          }
          if (precision || number) {
            buf_s = print_number_unsigned(buf, 16, number, precision,
                                          format[i] == 'X' ? 1 : 0);
          } else {
            buf_s = 0;
          }
          buf[buf_s] = '\0';
          int zero_c = width - buf_s;
          if (buf_s > 0) {
            if ((flags & HASH_FLAG) || format[i] == 'p') {
              zero_c -= 2;
            }
            if ((flags & SPACE_FLAG) && !(flags & PLUS_FLAG)) {  // ' '
              if (buf[0] != '-') {
                str[str_len++] = ' ';
                zero_c--;
              }
            }
            if (zero_c > 0) {
              if (flags & MINUS_FLAG) {  // -
                if ((flags & HASH_FLAG) || format[i] == 'p') {
                  str[str_len++] = '0';
                  if (format[i] == 'X')
                    str[str_len++] = 'X';
                  else
                    str[str_len++] = 'x';
                }
                s21_memcpy(str + str_len, buf, buf_s);
                str_len += buf_s;
                for (int j = 0; j < zero_c; j++) str[str_len++] = ' ';
              } else {
                char del = ' ';
                char *tm = buf;
                if (flags & ZERO_FLAG) del = '0';
                if (del == '0') {
                  if ((flags & HASH_FLAG) || format[i] == 'p') {
                    str[str_len++] = '0';
                    if (format[i] == 'X')
                      str[str_len++] = 'X';
                    else
                      str[str_len++] = 'x';
                  }
                  for (int j = 0; j < zero_c; j++) str[str_len++] = del;
                } else {
                  for (int j = 0; j < zero_c; j++) str[str_len++] = del;
                  if ((flags & HASH_FLAG) || format[i] == 'p') {
                    str[str_len++] = '0';
                    if (format[i] == 'X')
                      str[str_len++] = 'X';
                    else
                      str[str_len++] = 'x';
                  }
                }
                str[str_len] = '\0';
                s21_memcpy(str + str_len, tm, buf_s);
                str_len += buf_s;
              }
            } else {
              if ((flags & HASH_FLAG) || format[i] == 'p') {
                str[str_len++] = '0';
                if (format[i] == 'X')
                  str[str_len++] = 'X';
                else
                  str[str_len++] = 'x';
              }
              s21_memcpy(str + str_len, buf, buf_s);
              str_len += buf_s;
            }
          }
          break;
        }
        case 'n': {  // done
          int *arg = va_arg(ap, int *);
          *arg = str_len;
          break;
        }
        case '%': {  // done
          str[str_len++] = '%';
          break;
        }
        default: {
          error = 1;
        }
      }
    } else {
      str[str_len++] = format[i];
    }
  }
  str[str_len] = '\0';
  va_end(ap);
  return (int)str_len;
}
