#include "s21_decimal.h"

// int s21_is_equal(s21_decimal value1, s21_decimal value2) {
//   int code = TRUE;
//   if (get_scale(value1) != get_scale(value2)) {
//     normalize(&value1, &value2);
//   }
//   if (get_sign(value1) != get_sign(value2))
//     code = FALSE;
//   if (!is_equal_simple(value1, value2))
//     code = FALSE;

//   return code;
// }

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int is_equal = 1;
  s21_decimal zero = {{0, 0, 0, 0}};
  if ((is_equal_simple(value_1, zero))) {
    set_sign(&value_1, 0);
  }
  if ((is_equal_simple(value_2, zero))) {
    set_sign(&value_2, 0);
  }

  if (get_scale(value_1) != get_scale(value_2)) {
    normalize(&value_1, &value_2);
  }
  if (get_sign(value_1) != get_sign(value_2)) {
    is_equal = 0;
  } else {
    for (int i = 95; i >= 0; i--) {
      if (get_bit(value_1, i) != get_bit(value_2, i)) {
        is_equal = 0;
        break;
      }
    }
  }
  return is_equal;
}