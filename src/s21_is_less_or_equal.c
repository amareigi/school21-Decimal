#include "s21_decimal.h"

// returns:
// 1 - is less or equal
// 0 - is not less/equal

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}

// int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {
//   int code = FALSE;
//   if (s21_is_less(value1, value2))
//     code = TRUE;
//   if (s21_is_equal(value1, value2))
//     code = TRUE;
//   return code;
// }