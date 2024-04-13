#include "s21_decimal.h"

int add_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                   s21_decimal_big *result) {
  int overflow = FALSE;
  s21_decimal_big tmp = {{0, 0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 223; i++) {
    int sum = 0;
    int bit_dec1 = get_bit_big(value_1, i);
    int bit_dec2 = get_bit_big(value_2, i);
    sum = bit_dec1 + bit_dec2 + overflow;
    overflow = 0;
    if (sum > 1) {
      overflow = 1;
      sum %= 2;
    }
    set_bit_big(&tmp, i, sum);
  }
  if (!overflow) {
    *result = tmp;
  }
  return overflow;
}
int is_greater_or_equal_simple_big(s21_decimal_big dec1, s21_decimal_big dec2) {
  return is_greater_simple_big(dec1, dec2) || is_equal_simple_big(dec1, dec2);
}
int is_less_or_equal_simple_big(s21_decimal_big dec1, s21_decimal_big dec2) {
  return is_less_simple_big(dec1, dec2) || is_equal_simple_big(dec1, dec2);
}
int is_less_simple_big(s21_decimal_big dec1, s21_decimal_big dec2) {
  return !is_greater_or_equal_simple_big(dec1, dec2);
}

int s21_add_big(s21_decimal_big value_1, s21_decimal_big value_2,
                s21_decimal_big *result) {
  normalize_big(&value_1, &value_2);
  *result = (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}};
  if (get_sign_big(value_1) == get_sign_big(value_2)) {
    int overflow = FALSE;
    int zero_scale = FALSE;
    do {
      overflow = add_simple_big(value_1, value_2, result);
      if (overflow) zero_scale = low_scale_big(&value_1, &value_2);
    } while (overflow && !zero_scale);
    if (overflow && !get_sign_big(value_1)) return 1;
    if (overflow && get_sign_big(value_1)) return 2;
    set_sign_big(result, get_sign_big(value_1));
  } else {
    if (is_equal_simple_big(value_1, value_2)) {
      *result = (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}};
    } else if (is_greater_simple_big(value_1, value_2)) {
      sub_simple_big(value_1, value_2, result);
      set_sign_big(result, get_sign_big(value_1));
    } else {
      sub_simple_big(value_2, value_1, result);
      set_sign_big(result, get_sign_big(value_2));
    }
  }
  set_scale_big(result, get_scale_big(value_1));
  return OK;
}

int sub_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                   s21_decimal_big *result) {
  int debt = FALSE;
  for (int i = 0; i < 224; i++) {
    int bit_dec1 = get_bit_big(value_1, i);
    int bit_dec2 = get_bit_big(value_2, i);
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
      set_bit_big(result, i, 1);
      debt = TRUE;
    } else {
      set_bit_big(result, i, res);
    }
  }
  return debt;
}

s21_decimal_big div_simple_big(s21_decimal_big value_1, s21_decimal_big value_2,
                               s21_decimal_big *result) {
  *result = (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_big remainder = value_1;
  set_scale_big(&remainder, 0);
  s21_decimal_big tmp_2 = value_2;
  s21_decimal_big prev_tmp;

  while (is_greater_or_equal_simple_big(remainder, value_2)) {
    int q = 0;
    while (is_less_or_equal_simple_big(tmp_2, remainder)) {
      prev_tmp = tmp_2;
      q++;
      if (shift_left_big(&tmp_2)) break;
    }
    sub_simple_big(remainder, prev_tmp, &remainder);
    tmp_2 = value_2;
    --q;
    s21_decimal_big sh_series = {{1, 0, 0, 0, 0, 0, 0, 0}};
    for (int i = 0; i < q; i++) {
      shift_left_big(&sh_series);
    }
    add_simple_big(*result, sh_series, result);
  }
  return remainder;
}

int mult_10_big(s21_decimal_big value_1, s21_decimal_big *result) {
  int overflow = 0;
  s21_decimal_big tmp_1 = value_1;
  s21_decimal_big tmp_2 = value_1;
  overflow += shift_left_big(&tmp_1);
  overflow += shift_left_big(&tmp_1);
  overflow += shift_left_big(&tmp_1);
  overflow += shift_left_big(&tmp_2);
  overflow += add_simple_big(tmp_1, tmp_2, result);
  set_sign_big(result, get_sign_big(value_1));
  overflow = overflow ? TRUE : FALSE;
  return overflow;
}

int is_equal_simple_big(s21_decimal_big value_1, s21_decimal_big value_2) {
  int is_equal = TRUE;
  for (int i = 223; i >= 0; i--) {
    if (get_bit_big(value_1, i) != get_bit_big(value_2, i)) {
      is_equal = FALSE;
      break;
    }
  }
  return is_equal;
}

int is_greater_simple_big(s21_decimal_big value_1, s21_decimal_big value_2) {
  int is_greater = FALSE;
  for (int i = 223; i >= 0; i--) {
    if (get_bit_big(value_1, i) != get_bit_big(value_2, i)) {
      if (get_bit_big(value_1, i)) is_greater = TRUE;
      break;
    }
  }
  return is_greater;
}