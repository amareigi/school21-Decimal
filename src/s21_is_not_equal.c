#include "s21_decimal.h"

// returns:
// 1-not equal
// 0-equals

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}