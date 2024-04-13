#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) {
    return ERROR_CONVERT;
  }

  int scl = get_scale(src);
  while (scl > 0) {
    div_simple(src, (s21_decimal){{10, 0, 0, 0}}, &src);
    scl--;
  }
  s21_decimal max_int = {{1073741823, 0, 0, 0}};
  s21_decimal min_int = {{1073741824, 0, 0, 0}};
  if (get_sign(src)) {
    if (is_greater_simple(src, min_int)) {
      return 1;
    }
  } else {
    if (is_greater_simple(src, max_int)) {
      return 1;
    }
  }

  int sign = (get_sign(src)) ? -1 : 1;
  *dst = src.bits[0] * sign;
  return 0;
}
