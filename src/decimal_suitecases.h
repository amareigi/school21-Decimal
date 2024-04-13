#ifndef S_SRC_DECIMAL_SUITECASES_H_
#define S_SRC_DECIMAL_SUITECASES_H_

#include "s21_decimal.h"
#include <check.h>

Suite *suite_s21_add(void);
Suite *suite_s21_sub(void);
Suite *suite_s21_div(void);
Suite *suite_s21_from_int_to_decimal(void);
Suite *suite_s21_from_decimal_to_int(void);
Suite *suite_s21_mul(void);
Suite *suite_s21_mul2(void);
Suite *suite_s21_round(void);
Suite *suite_s21_truncate(void);
Suite *suite_s21_floor(void);
Suite *suite_s21_negate(void);
Suite *suite_s21_negate2(void);
Suite *suite_s21_is_equal(void);
Suite *suite_s21_is_equal2(void);
Suite *suite_s21_is_not_equal(void);
Suite *suite_s21_is_not_equal2(void);
Suite *suite_s21_is_greater(void);
Suite *suite_s21_is_greater2(void);
Suite *suite_s21_is_greater_or_equal(void);
Suite *suite_s21_is_greater_or_equal2(void);
Suite *suite_s21_is_less(void);
Suite *suite_s21_is_less2(void);
Suite *suite_s21_is_less_or_equal(void);
Suite *suite_s21_is_less_or_equal2(void);
Suite *suite_s21_from_float_to_decimal(void);
Suite *suite_s21_from_decimal_to_float(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
