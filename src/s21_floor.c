#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return ERROR_CONVERT;
  *result = (s21_decimal){{0, 0, 0, 0}};
  int code = OK;
  int sign = get_sign(value);
  int scale = get_scale(value);
  if (!scale) {
    *result = value;
    return code;
  }
  s21_decimal one = {{1, 0, 0, 0}};
  code = s21_truncate(value, result);
  if (sign) {
    add_simple(*result, one, result);
    set_sign(result, sign);
  }

  return code;
}