#include <stdio.h>
#include <stdlib.h>

#include "tests/unit_test.h"

void run_testcase(Suite* testcase);
void run_all_tests(void);

int main(void) {
  run_all_tests();
  return 0;
}

void run_testcase(Suite* testcase) {
  SRunner* sr;
  static int test_number = 1;
  if (test_number > 0) {
    printf("TEST CASE %d\n", test_number++);
  }

  sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_all_tests(void) {
  Suite* list_cases[] = {
      s21_memchr_suite(),    s21_memcmp_suite(),    s21_memcpy_suite(),
      s21_memmove_suite(),   s21_memset_suite(),    s21_strcat_suite(),
      s21_strncat_suite(),   s21_strchr_suite(),    s21_strcmp_suite(),
      s21_strncmp_suite(),   s21_strcpy_suite(),    s21_strncpy_suite(),
      s21_strcspn_suite(),   s21_strerror_suite(),  s21_strlen_suite(),
      s21_strpbrk_suite(),   s21_strrchr_suite(),   s21_strspn_suite(),
      s21_strstr_suite(),    s21_strtok_suite(),    s21_to_upper_suite(),
      s21_to_lower_suite(),  s21_insert_suite(),    s21_trim_suite(),
      s21_print_d_suite(),   s21_print_c_suite(),   s21_print_lc_suite(),
      s21_print_n_suite(),   s21_print_pr_suite(),  s21_print_s_suite(),
      s21_print_ls_suite(),  s21_print_i_suite(),   s21_print_p_suite(),
      s21_print_x_suite(),   s21_print_xb_suite(),  s21_print_f_suite(),
      s21_print_e_suite(),   s21_print_eb_suite(),  s21_print_u_suite(),
      s21_print_g_suite(),   s21_print_o_suite(),   s21_print_gb_suite(),
      s21_sscanf_d_suite(),  s21_sscanf_i_suite(),  s21_sscanf_c_suite(),
      s21_sscanf_s_suite(),  s21_sscanf_n_suite(),  s21_sscanf_u_suite(),
      s21_sscanf_xb_suite(), s21_sscanf_x_suite(),  s21_sscanf_f_suite(),
      s21_sscanf_e_suite(),  s21_sscanf_eb_suite(), s21_sscanf_g_suite(),
      s21_sscanf_gb_suite(), s21_sscanf_o_suite(),  s21_sscanf_p_suite(),
      s21_sscanf_pr_suite(),
  };

  for (int i = 0; i < (int)(sizeof(list_cases) / sizeof(Suite*)); i++) {
    run_testcase(list_cases[i]);
  }
}
