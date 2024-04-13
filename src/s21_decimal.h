#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include "s21_decimal.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum error_arithmetic {
  TEST_ARITHMETIC_OK,
  TEST_ARITHMETIC_BIG,
  TEST_ARITHMETIC_SMALL,
  TEST_ARITHMETIC_ZERO_DIV
} Arithmetic;

typedef enum error_bull { FALSE, TRUE } Bool;

typedef enum error_convert {
  OK,
  ERROR_CONVERT,
  NUMBER_MAX_INF = 1,
  NUMBER_MIN_INF
} Convert;
typedef struct {
  unsigned int bits[4];
} s21_decimal;
typedef union fti {
  float fl;
  unsigned int d;
} fti;
typedef struct {
  unsigned int bits[8];
} s21_decimal_big;

// s21_functions
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal_big div_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                               s21_decimal_big *result);
s21_decimal_big from_decimal_to_big(s21_decimal value);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

// other functions
int get_bit(s21_decimal number, int bit);
int get_sign(s21_decimal number);
void set_bit(s21_decimal *number, int bit, int value);
void set_sign(s21_decimal *number, int value);
int get_scale(s21_decimal number);
void set_scale(s21_decimal *number, int scale);
int shift_left(s21_decimal *number);
int shift_right(s21_decimal *number);
void set_binary_number(s21_decimal *number, const char *string_number);
char *show_bstr(int n, char *bstr);
void normalize(s21_decimal *value_1, s21_decimal *value_2);
int low_scale(s21_decimal *value_1, s21_decimal *value_2);
int add_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int sub_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal div_simple(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
int mult_10(s21_decimal value_1, s21_decimal *result);
int is_equal_simple(s21_decimal value_1, s21_decimal value_2);
int is_greater_simple(s21_decimal value_1, s21_decimal value_2);
int is_greater_or_equal_simple(s21_decimal dec1, s21_decimal dec2);
int is_less_simple(s21_decimal dec1, s21_decimal dec2);
int is_less_or_equal_simple(s21_decimal dec1, s21_decimal dec2);
void sum_bit(s21_decimal res, s21_decimal *result);
int validity_check(s21_decimal value_1, s21_decimal value_2);
int s21_null_check_bits(s21_decimal value);
int convert_to_int(s21_decimal value); // кажется не использую

// big functions
void set_sign_big(s21_decimal_big *number, int sign);
int get_sign_big(s21_decimal_big number);
int get_bit_big(s21_decimal_big number, int bit);
int get_scale_big(s21_decimal_big number);
void set_bit_big(s21_decimal_big *number, int bit, int sign);
void set_scale_big(s21_decimal_big *number, int scale);
int is_equal_simple_big(s21_decimal_big value_1, s21_decimal_big value_2);
int is_greater_simple_big(s21_decimal_big value_1, s21_decimal_big value_2);
int add_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                   s21_decimal_big *result);
int is_greater_or_equal_simple_big(s21_decimal_big dec1, s21_decimal_big dec2);
int is_less_or_equal_simple_big(s21_decimal_big dec1, s21_decimal_big dec2);
int is_less_simple_big(s21_decimal_big dec1, s21_decimal_big dec2);
int shift_left_big(s21_decimal_big *number);
int sub_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                   s21_decimal_big *result);
int from_big_to_decimal(s21_decimal_big value, s21_decimal *result);
int mult_10_big(s21_decimal_big value_1, s21_decimal_big *result);
int s21_add_big(s21_decimal_big value_1, s21_decimal_big value_2,
                s21_decimal_big *result);
void normalize_big(s21_decimal_big *value_1, s21_decimal_big *value_2);
int low_scale_big(s21_decimal_big *value_1, s21_decimal_big *value_2);
int round_banker_big(s21_decimal_big *result);
s21_decimal_big div_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                               s21_decimal_big *result);
s21_decimal_big from_decimal_to_big(s21_decimal value);
void sum_bit_big(s21_decimal_big res, s21_decimal_big *result);

#endif
