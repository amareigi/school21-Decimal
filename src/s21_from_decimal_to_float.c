#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = TRUE;
  if (dst != NULL) {
    double tmp = 0;
    int scale = 0;
    for (int i = 0; i < 96; i++) {
      if (get_bit(src, i)) tmp += pow(2, i);
    }
    scale = get_scale(src);
    if (scale > 0) {
      for (int i = scale; i > 0; i--) {
        tmp /= 10.0;
      }
    }
    *dst = (float)tmp;
    if (get_sign(src)) {
      *dst *= -1;
    } else {
      *dst *= 1;
    }
    err = FALSE;
  }
  return err;
}
