#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) {
    return ERROR_CONVERT;
  }
  *dst = (s21_decimal){{0, 0, 0, 0}};
  int sign = (src >= 0) ? 0 : 1;
  src = (src >= 0) ? src : -src;
  for (int i = 0; i < 96; i++) {
    set_bit(dst, i, src % 2);
    src /= 2;
  }

  set_sign(dst, sign);
  return OK;
}
