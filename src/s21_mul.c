#include "s21_decimal.h"

#define S21_OLOLONG_BIG ((sizeof(s21_decimal_big) / sizeof(unsigned) - 1) * 32)

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = (s21_decimal){{0, 0, 0, 0}};
  int error = validity_check(value_1, value_2);
  if (error != OK) return error;
  unsigned i = 0;

  s21_decimal_big big_result = {{0}};
  s21_decimal_big big_val1 = from_decimal_to_big(value_1);
  s21_decimal_big big_val2 = from_decimal_to_big(value_2);

  while (i < S21_OLOLONG_BIG) {
    if (get_bit_big(big_val2, i) == 1) {
      s21_decimal_big res = big_val1;
      unsigned tmp = 0;
      while (tmp < i) {
        shift_left_big(&res);
        tmp++;
      }
      sum_bit_big(res, &big_result);
    }
    i++;
  }
  big_result.bits[255 / 32] ^= big_val1.bits[255 / 32];
  big_result.bits[255 / 32] ^= big_val2.bits[255 / 32];
  int scale = get_scale_big(big_val1) + get_scale_big(big_val2);
  set_scale_big(&big_result, scale);
  round_banker_big(&big_result);
  error = from_big_to_decimal(big_result, result);
  return error;
}
