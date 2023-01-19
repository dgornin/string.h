#include "s21_string.h"

#if defined __APPLE__ && defined __MACH__

const char *const s21_errlist[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full",
};

#define UNKNOWN_ERROR_MSG "Unknown error: %d"

#elif defined __linux__

const char *const s21_errlist[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#define UNKNOWN_ERROR_MSG "Unknown error %d"

#endif

const int s21_nerr = sizeof(s21_errlist) / sizeof(s21_errlist[0]);

#define ERROR_BUFFER_SIZE 500
char error_buffer[ERROR_BUFFER_SIZE];

void *s21_memchr(const void *str, int c, s21_size_t n) {
  /* This function returns a pointer to the matching byte
  or s21_NULL if the character does not occur in the given
  memory area. */
  void *tmp = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (((unsigned char *)str)[i] == c) {
      tmp = (unsigned char *)str + i;
      break;
    }
  }
  return tmp;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  /* This function returns an integer less than, equal to, or
  greater than zero if the first n bytes of str1 is found,
  respectively, to be less than, to match, or be greater
  than the first n bytes of str2. */
  int tmp = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i]) {
      tmp = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
      break;
    }
  }
  return tmp;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  /* This function copies n characters from memory area src
  to memory area dest. The memory areas must not overlap. */
  for (s21_size_t i = 0; i < n; i++) {
    ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
  }
  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  /* This function copies n characters from memory area src
  to memory area dest. The memory areas may overlap. */
  unsigned char *tmp = (unsigned char *)malloc(n * sizeof(unsigned char));
  for (s21_size_t i = 0; i < n; i++) {
    tmp[i] = ((unsigned char *)src)[i];
  }
  for (s21_size_t i = 0; i < n; i++) {
    ((unsigned char *)dest)[i] = tmp[i];
  }
  free(tmp);
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  /* This function fills the first n bytes of the memory
  area pointed to by str with the constant byte c. */
  for (s21_size_t i = 0; i < n; i++) {
    ((unsigned char *)str)[i] = c;
  }
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  int k = s21_strlen(dest);
  int i = 0;
  for (; src[i] != '\0'; i++) {
    dest[k] = src[i];
    k++;
  }
  dest[k] = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int k = s21_strlen(dest);
  for (int i = 0; n-- && src[i] != '\0'; i++) dest[k++] = src[i];
  dest[k] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *p = s21_NULL;
  int flag = 1;
  int i = 0;
  while (str[i] != '\0' && flag) {
    if (str[i] == c) {
      p = (char *)str + i;
      flag = 0;
    }
    i++;
  }
  if (str[i] == c) p = (char *)str + i;
  return p;
}

int s21_strcmp(const char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) i++;
  return str1[i] - str2[i];
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  if (n > 0) {
    s21_size_t i = 0;
    do {
      diff = str1[i] - str2[i];
    } while (!diff && str1[i] && str2[i] && ++i < n);
  }
  return diff;
}

char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  for (; src[i] != '\0'; i++) dest[i] = src[i];
  dest[i] = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (n > 0) {
    s21_size_t i = 0;
    do {
      dest[i] = src[i];
    } while (src[i] && ++i < n);
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int flag = 0;
  for (int i = 0; !flag && str1[i] != '\0'; i++) {
    for (int j = 0; !flag && str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) flag = 1;
    }
    if (!flag) {
      len++;
    }
  }
  return len;
}

char *s21_strerror(int errnum) {
  if (errnum >= 0 && errnum < s21_nerr) {
    s21_strncpy(error_buffer, s21_errlist[errnum], ERROR_BUFFER_SIZE);
  } else {
    s21_sprintf(error_buffer, UNKNOWN_ERROR_MSG, errnum);
  }
  return error_buffer;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *temp = s21_NULL;
  int flag = 1;
  for (int i = 0; flag && str1[i] != '\0'; i++) {
    for (int j = 0; flag && str2[j] != '\0'; j++)
      if (str1[i] == str2[j]) {
        temp = (char *)str1 + i;
        flag = 0;
      }
  }
  return temp;
}

char *s21_strrchr(const char *str, int c) {
  char *temp = s21_NULL;
  int i = 0;
  do {
    if (str[i] == c) temp = (char *)str + i;
  } while (str[i++] != '\0');
  return temp;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int flag = 1;
  for (int i = 0; flag && str1[i] != '\0'; i++) {
    flag = 0;
    for (int j = 0; !flag && str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        len++;
        flag = 1;
      }
    }
  }
  return len;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle) {
    const char *ptr2 = needle;
    while (*haystack && *ptr2) {
      const char *ptr1 = haystack;
      ptr2 = needle;
      while (*ptr1 && *ptr2 && *ptr1 == *ptr2) {
        ptr1++;
        ptr2++;
      }
      if (*ptr2) {
        haystack++;
      }
    }
    if (!*haystack) {
      haystack = s21_NULL;
    }
  }
  return (char *)haystack;
}

char *s21_strtok(char *str, const char *delim) {
  static char *input = s21_NULL;
  char *ret = s21_NULL;
  if (str != s21_NULL) {
    input = str;
  }
  if (input != s21_NULL) {
    s21_size_t delim_len = s21_strlen(delim);
    int stop = 0;
    while (!stop && *input) {
      int is_found_delim = 0;
      for (s21_size_t i = 0; !is_found_delim && *input && i < delim_len; i++) {
        if (*input == delim[i]) {
          is_found_delim = 1;
        }
      }
      if (!is_found_delim) {
        stop = 1;
      } else {
        input++;
      }
    }
    stop = 0;
    if (*input) {
      ret = input;
    }
    while (!stop && *input) {
      int is_found_delim = 0;
      for (s21_size_t i = 0; !is_found_delim && *input && i < delim_len; i++) {
        if (*input == delim[i]) {
          is_found_delim = 1;
          stop = 1;
          *input = '\0';
        }
      }
      input++;
    }
    if (!*input) {
      input = s21_NULL;
    }
  }
  return ret;
}

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *new_str = (char *)malloc((len + 1) * sizeof(char));
  for (s21_size_t i = 0; i < len + 1; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_str[i] = str[i] - 32;
    } else {
      new_str[i] = str[i];
    }
  }
  return new_str;
}

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *new_str = (char *)malloc((len + 1) * sizeof(char));
  for (s21_size_t i = 0; i < len + 1; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      new_str[i] = str[i] + 32;
    } else {
      new_str[i] = str[i];
    }
  }
  return new_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_len = s21_strlen(src), str_len = s21_strlen(str);
  char *ans = s21_NULL;
  if (start_index <= src_len) {
    ans = (char *)malloc((src_len + str_len + 1) * sizeof(char));
    s21_size_t ans_n = 0;
    for (s21_size_t i = 0; i < start_index; i++) ans[ans_n++] = src[i];
    for (s21_size_t i = 0; i < str_len; i++) ans[ans_n++] = str[i];
    for (s21_size_t i = start_index; i < src_len + 1; i++)
      ans[ans_n++] = src[i];
  }
  return ans;
}

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t src_len = s21_strlen(src), trim_chars_len = s21_strlen(trim_chars);
  int start = 0;
  int end = src_len - 1;
  for (s21_size_t i = 0; i < src_len; i++) {
    int is_trim = 0;
    for (s21_size_t j = 0; !is_trim && j < trim_chars_len; j++) {
      if (src[i] == trim_chars[j]) is_trim = 1;
    }
    if (is_trim)
      start++;
    else
      i = src_len;
  }
  for (int i = end; i >= 0; i--) {
    int is_trim = 0;
    for (s21_size_t j = 0; !is_trim && j < trim_chars_len; j++) {
      if (src[i] == trim_chars[j]) is_trim = 1;
    }
    if (is_trim)
      end--;
    else
      i = 0;
  }
  char *ans = s21_NULL;
  if (end >= 0) {
    ans = (char *)malloc((end - start + 2) * sizeof(char));
    s21_size_t ans_n = 0;
    for (int i = start; i < end + 1; i++) ans[ans_n++] = src[i];
    ans[ans_n] = '\0';
  } else {
    ans = (char *)malloc(sizeof(char));
    ans[0] = '\0';
  }
  return ans;
}
