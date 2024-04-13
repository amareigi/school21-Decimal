#include "s21_decimal.h"
int s21_negate(s21_decimal value, s21_decimal *result) {
  int code = ERROR_CONVERT;
  if (result != NULL) {
    code = OK;
    *result = value;
    set_sign(result, !get_sign(value));
  }
  return code;
}