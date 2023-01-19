#include "str_to_num.h"

long s21_strtol(const char* str, int radix) {
  int sign = 1, i = 0;
  long int res = 0;
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }
  if (str[i] == '0' && radix == 16) {
    if (str[i + 1]) {
      if (str[i + 1] == 'x' || str[i + 1] == 'X') i += 2;
    }
  }
  while (str[i]) {
    if ((!(str[i] >= '0' && str[i] <= radix + 47 && radix <= 10)) &&
        (!(((str[i] >= '0' && str[i] < '9') ||
            (str[i] >= 'A' && str[i] <= radix + 54) ||
            (str[i] >= 'a' && str[i] <= radix + 86)) &&
           radix > 10 && radix < 37))) {
      break;
    } else {
      if (str[i] >= 'A' && str[i] <= 'Z')
        res = res * radix + (str[i] - 'A' + 10);
      else if (str[i] >= 'a' && str[i] <= 'z')
        res = res * radix + (str[i] - 'a' + 10);
      else
        res = res * radix + str[i] - '0';
      i++;
    }
  }
  return res * sign;
}

long double s21_atold(char* str) {
  int sign = 1, i = 0;
  long double inc = 0.1L, res = 0.L;
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }
  while (str[i] != '.') {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      break;
    } else {
      res = res * 10.L + str[i] - '0';
      i++;
    }
  }
  if (str[i] == '.') i++;
  while (str[i]) {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      break;
    } else {
      res = res + (str[i] - '0') * inc;
      inc /= 10.L;
      i++;
    }
  }
  inc = 10.L;
  if (str[i] == 'e' || str[i] == 'E') {
    i++;
    if (str[i] == '-') {
      inc = 0.1L;
      i++;
    } else if (str[i] == '+') {
      inc = 10.L;
      i++;
    }
    int count = 0;
    while (str[i] >= '0' && str[i] <= '9') {
      count = count * 10.L + str[i] - '0';
      i++;
    }

    while (count) {
      res *= inc;
      count--;
    }
  }
  return res * sign;
}
