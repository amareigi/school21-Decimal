#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  normalize(&value_1, &value_2);
  *result = (s21_decimal){{0, 0, 0, 0}};
  if (get_sign(value_1) != get_sign(value_2)) {
    int overflow = 0;
    int zero_scale = 0;
    do {
      overflow = add_simple(value_1, value_2, result);
      if (overflow) zero_scale = low_scale(&value_1, &value_2);
    } while (overflow && !zero_scale);
    if (overflow && !get_sign(value_1)) return 1;
    if (overflow && get_sign(value_1)) return 2;
    set_sign(result, get_sign(value_1));
  } else {
    if (is_equal_simple(value_1, value_2)) {
      *result = (s21_decimal){{0, 0, 0, 0}};
    } else if (is_greater_simple(value_1, value_2)) {
      sub_simple(value_1, value_2, result);
      set_sign(result, get_sign(value_1));
    } else {
      sub_simple(value_2, value_1, result);
      set_sign(result, (get_sign(value_2) ? 0 : 1));
    }
  }
  set_scale(result, get_scale(value_1));
  return 0;
}
