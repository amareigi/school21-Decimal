#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int code = OK;
  if (result == NULL) return ERROR_CONVERT;
  *result = (s21_decimal){{0, 0, 0, 0}};
  int sign = get_sign(value);
  int degree = get_scale(value);
  if (degree == 0) {
    *result = value;
    return OK;
  }
  int degree_end = degree;
  int quant_null = 1;
  while (degree--) {
    quant_null *= 10;
  }
  s21_decimal ten = {{0, 0, 0, 0}};
  s21_decimal a_remainder = {{0, 0, 0, 0}};

  code = s21_from_int_to_decimal(quant_null, &ten);
  div_simple(value, ten, &a_remainder);
  s21_decimal remainder = value;
  for (int i = 0; i < 128; i++) {
    set_bit(&ten, i, 0);
  }
  s21_from_int_to_decimal(10, &ten);
  s21_decimal one = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(1, &one);
  s21_decimal big = {{0, 0, 0, 0}};
  while (degree_end-- > 0) {
    big = div_simple(remainder, ten, &remainder);
  }
  int big_int = 0;
  s21_from_decimal_to_int(big, &big_int);
  if (abs(big_int) >= 5) {
    add_simple(remainder, one, &remainder);
  }

  *result = remainder;
  if (result->bits[0] > 0) set_sign(result, sign);
  return code;
}