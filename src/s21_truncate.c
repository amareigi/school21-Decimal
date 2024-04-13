#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int code = OK;
  if (result == NULL) return ERROR_CONVERT;
  *result = (s21_decimal){{0, 0, 0, 0}};
  int sign = get_sign(value);    // знак
  int scale = get_scale(value);  // степень
  if (scale == 0) {
    *result = value;
    return code;
  }
  s21_decimal temp = {{0, 0, 0, 0}};
  code = s21_from_int_to_decimal(10, &temp);
  int i = 0;
  *result = value;
  while (i < scale) {
    div_simple(*result, temp, result);
    i++;
  }
  if (result->bits[0]) set_sign(result, sign);
  return code;
}