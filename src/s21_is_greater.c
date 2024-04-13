#include "s21_decimal.h"

// returns:
// 1 - is greater
// 0 - is not greater

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !(s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2));
}

// int s21_is_greater(s21_decimal value1, s21_decimal value2) {
//   int code = TRUE;
//   if (get_scale(value1) != get_scale(value2)) {
//     normalize(&value1, &value2);
//   }
//   if (is_equal_simple(value1, value2)) {
//     code = FALSE;
//   } else if (get_sign(value1) > get_sign(value2)) {
//     code = FALSE;
//   } else if (get_sign(value1) < get_sign(value2)) {
//     code = TRUE;
//   } else {
//     if (get_sign(value1) == 1)
//       code = !is_greater_simple(value1, value2);
//     else
//       code = is_greater_simple(value1, value2);
//   }
//   return code;
// }