#include "s21_decimal.h"
int add_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int overflow = FALSE;
  s21_decimal tmp = {{0, 0, 0, 0}};
  for (int i = 0; i < 96; i++) {
    int sum = 0;
    int bit_dec1 = get_bit(value_1, i);
    int bit_dec2 = get_bit(value_2, i);
    sum = bit_dec1 + bit_dec2 + overflow;
    overflow = FALSE;
    if (sum > 1) {
      overflow = TRUE;
      sum %= 2;
    }
    set_bit(&tmp, i, sum);
  }
  if (!overflow) {
    *result = tmp;
  }
  return overflow;
}

int sub_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int debt = FALSE;
  for (int i = 0; i < 96; i++) {
    int bit_dec1 = get_bit(value_1, i);
    int bit_dec2 = get_bit(value_2, i);
    if (debt == TRUE) {
      if (bit_dec1) {
        bit_dec1 = 0;
        debt = FALSE;
      } else {
        bit_dec1 = 1;
      }
    }
    int res = bit_dec1 - bit_dec2;
    if (res == -1) {
      set_bit(result, i, 1);
      debt = TRUE;
    } else {
      set_bit(result, i, res);
    }
  }
  return debt;
}

s21_decimal div_simple(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result) {
  *result = (s21_decimal){{0, 0, 0, 0}};
  s21_decimal remainder = value_1;
  set_scale(&remainder, 0);
  s21_decimal tmp_2 = value_2;
  s21_decimal prev_tmp;

  while (is_greater_or_equal_simple(remainder, value_2)) {
    int q = 0;
    while (is_less_or_equal_simple(tmp_2, remainder)) {
      prev_tmp = tmp_2;
      q++;
      if (shift_left(&tmp_2)) break;
    }
    sub_simple(remainder, prev_tmp, &remainder);
    tmp_2 = value_2;
    --q;
    s21_decimal sh_series = {{1, 0, 0, 0}};
    for (int i = 0; i < q; i++) {
      shift_left(&sh_series);
    }
    add_simple(*result, sh_series, result);
  }
  return remainder;
}

int mult_10(s21_decimal value_1, s21_decimal *result) {
  int overflow = FALSE;
  s21_decimal tmp_1 = value_1;
  s21_decimal tmp_2 = value_1;
  overflow += shift_left(&tmp_1);
  overflow += shift_left(&tmp_1);
  overflow += shift_left(&tmp_1);
  overflow += shift_left(&tmp_2);
  overflow += add_simple(tmp_1, tmp_2, result);
  set_sign(result, get_sign(value_1));
  overflow = overflow ? TRUE : FALSE;
  return overflow;
}

int is_equal_simple(s21_decimal value_1, s21_decimal value_2) {
  int is_equal = TRUE;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(value_1, i) != get_bit(value_2, i)) {
      is_equal = FALSE;
      break;
    }
  }
  return is_equal;
}

int is_greater_simple(s21_decimal value_1, s21_decimal value_2) {
  int is_greater = FALSE;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(value_1, i) != get_bit(value_2, i)) {
      if (get_bit(value_1, i)) is_greater = TRUE;
      break;
    }
  }
  return is_greater;
}

int is_greater_or_equal_simple(s21_decimal dec1, s21_decimal dec2) {
  return is_greater_simple(dec1, dec2) || is_equal_simple(dec1, dec2);
}

int is_less_simple(s21_decimal dec1, s21_decimal dec2) {
  return !is_greater_or_equal_simple(dec1, dec2);
}

int is_less_or_equal_simple(s21_decimal dec1, s21_decimal dec2) {
  return is_less_simple(dec1, dec2) || is_equal_simple(dec1, dec2);
}
int s21_null_check_bits(s21_decimal value) {
  int res = 0;
  for (unsigned i = 96; i < 112; i++) {
    unsigned res1 = get_bit(value, i);
    res = res1 + res;
  }
  for (unsigned i = 120; i < 127; i++) {
    unsigned res1 = get_bit(value, i);
    res = res1 + res;
  }
  if (get_sign(value) == 1) {
    res *= -1;
  }
  return res == 0 ? OK : res < 0 ? NUMBER_MIN_INF : NUMBER_MAX_INF;
}

int validity_check(s21_decimal value_1, s21_decimal value_2) {
  int error = OK;
  int null_check_one = s21_null_check_bits(value_1);
  int null_check_two = s21_null_check_bits(value_2);
  if (null_check_one != OK) error = null_check_one;
  if (null_check_two != OK) error = null_check_two;

  return error;
}