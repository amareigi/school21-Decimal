#include "s21_decimal.h"
#define S21_MASK_BIT (1 << bit % 32)
#define S21_MASK_SIGN 0x80000000
#define S21_OLOLONG_BIG ((sizeof(s21_decimal_big) / sizeof(unsigned) - 1) * 32)

void set_sign_big(s21_decimal_big *number, int sign) {
  if (sign != get_sign_big(*number)) {
    unsigned int mask = 0;
    mask = 1U << 31;
    number->bits[7] ^= mask;
  }
}

int get_sign_big(s21_decimal_big number) {
  return ((number.bits[7] & (S21_MASK_SIGN)) == 0) ? FALSE : TRUE;
}

int get_bit_big(s21_decimal_big number, int bit) {
  return ((number.bits[bit / 32] & S21_MASK_BIT) == 0) ? FALSE : TRUE;
}

int get_scale_big(s21_decimal_big number) {
  int scale = 0;
  for (int i = 0, shift = 16; shift <= 23; ++i, ++shift) {
    unsigned int mask = 0;
    mask = 1U << shift;
    int bit = ((number.bits[7] & mask) == mask);
    scale += bit * pow(2, i);
  }
  return scale;
}

void set_bit_big(s21_decimal_big *number, int bit, int sign) {
  sign == 0 ? (number->bits[bit / 32] &= ~S21_MASK_BIT)
            : (number->bits[bit / 32] |= (S21_MASK_BIT));
}

void set_scale_big(s21_decimal_big *number, int scale) {
  for (int shift = 16; shift <= 23; ++shift) {
    unsigned int mask = 0;
    mask = 1U << shift;
    if (scale > 0 && scale % 2 == 1) {
      number->bits[7] |= mask;
    } else {
      number->bits[7] &= ~mask;
    }
    scale /= 2;
  }
}

int shift_left_big(s21_decimal_big *number) {
  int is_overflow = get_bit_big(*number, 223);
  for (int i = 223; i >= 0; i--) {
    if (i != 0) {
      set_bit_big(number, i, get_bit_big(*number, i - 1));
    } else {
      set_bit_big(number, i, 0);
    }
  }
  return is_overflow;
}

int low_scale_big(s21_decimal_big *value_1, s21_decimal_big *value_2) {
  int zero_scale = FALSE;
  int scl1 = get_scale_big(*value_1);
  int scl2 = get_scale_big(*value_2);
  if (scl1 == 0 || scl2 == 0) {
    zero_scale = TRUE;
  } else {
    s21_decimal_big div_10 = {{10, 0, 0, 0, 0, 0, 0, 0}};
    div_simple_big(*value_1, div_10, value_1);
    div_simple_big(*value_2, div_10, value_2);
    scl1--;
    scl2--;
    set_scale_big(value_1, scl1);
    set_scale_big(value_2, scl2);
  }
  return zero_scale;
}

void normalize_big(s21_decimal_big *value_1, s21_decimal_big *value_2) {
  int scl1 = get_scale_big(*value_1);
  int scl2 = get_scale_big(*value_2);
  int sign1 = get_sign_big(*value_1);
  int sign2 = get_sign_big(*value_2);
  s21_decimal_big tmp_1 = *value_1;
  s21_decimal_big tmp_2 = *value_2;
  s21_decimal_big div_10 = {{10, 0, 0, 0, 0, 0, 0, 0}};

  if (scl1 != scl2) {
    while (scl1 != scl2) {
      int overflow = 0;
      if (scl1 > scl2) {
        overflow = mult_10_big(tmp_2, &tmp_2);
        if (overflow) break;
        *value_2 = tmp_2;
        scl2++;
      } else {
        overflow = mult_10_big(tmp_1, &tmp_1);
        if (overflow) break;
        *value_1 = tmp_1;
        scl1++;
      }
    }

    int tail = 0;
    int not_even;
    s21_decimal_big remainder;
    int target_scale = (scl1 > scl2) ? scl2 : scl1;
    while (scl1 != scl2) {
      if (scl1 > scl2) {
        scl1--;
        not_even = get_bit_big(tmp_1, 0);
        remainder = div_simple_big(tmp_1, div_10, &tmp_1);
        if (scl1 == target_scale) {
          if (is_greater_simple_big(
                  remainder, (s21_decimal_big){{5, 0, 0, 0, 0, 0, 0, 0}})) {
            add_simple_big(tmp_1, (s21_decimal_big){{1, 0, 0, 0, 0, 0, 0, 0}},
                           &tmp_1);
          } else if ((is_equal_simple_big(
                         remainder,
                         (s21_decimal_big){{5, 0, 0, 0, 0, 0, 0, 0}})) &&
                     not_even && tail) {
            add_simple_big(tmp_1, (s21_decimal_big){{1, 0, 0, 0, 0, 0, 0, 0}},
                           &tmp_1);
          }
        }
        if (is_greater_simple_big(remainder,
                                  (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}}))
          tail = 1;
        *value_1 = tmp_1;
      } else {
        scl2--;
        not_even = get_bit_big(tmp_2, 0);
        remainder = div_simple_big(tmp_2, div_10, &tmp_2);
        if (scl2 == target_scale) {
          if (is_greater_simple_big(
                  remainder, (s21_decimal_big){{5, 0, 0, 0, 0, 0, 0, 0}})) {
            add_simple_big(tmp_2, (s21_decimal_big){{1, 0, 0, 0, 0, 0, 0, 0}},
                           &tmp_2);
          } else if ((is_equal_simple_big(
                         remainder,
                         (s21_decimal_big){{5, 0, 0, 0, 0, 0, 0, 0}})) &&
                     not_even && tail) {
            add_simple_big(tmp_2, (s21_decimal_big){{1, 0, 0, 0, 0, 0, 0, 0}},
                           &tmp_2);
          }
        }
        if (is_greater_simple_big(remainder,
                                  (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}}))
          tail = 1;
        *value_2 = tmp_2;
      }
    }
    set_scale_big(value_1, scl1);
    set_scale_big(value_2, scl2);
    set_sign_big(value_1, sign1);
    set_sign_big(value_2, sign2);
  }
}

int round_banker_big(s21_decimal_big *result) {
  int code = OK;
  int scale = get_scale_big(*result);
  int sign = get_sign_big(*result);
  if (!scale) return code;
  s21_decimal_big temp_ost = {{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
  s21_decimal_big temp_null = {{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
  s21_decimal_big ten = {{0xA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};  // 10
  int is_greater = FALSE;
  int tale = 0;
  while (!is_greater && scale >= 0) {
    is_greater = TRUE;
    for (int i = 96; i < 224; i++) {
      if (get_bit_big(*result, i)) {
        is_greater = FALSE;
        break;
      }
    }

    if (is_greater_simple_big(temp_ost, temp_null))
      tale++;  // если есть хвост и он не 0
    if (!is_greater) {
      temp_ost = div_simple_big(*result, ten, result);
      scale--;
    }
    if (scale > 28 && is_greater) {
      temp_ost = div_simple_big(*result, ten, result);
      scale--;
      is_greater = FALSE;
    }
  }
  if (!is_greater && scale == 0) {
    code = ERROR_CONVERT;
    return code;
  }
  s21_decimal_big five_mask = {{0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
  s21_decimal_big one = {{0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};

  if (is_equal_simple_big(temp_ost, five_mask)) {
    if (get_bit_big(*result, 0) || tale > 1)
      add_simple_big(*result, one, result);
  } else if (is_greater_simple_big(temp_ost, five_mask))
    add_simple_big(*result, one, result);
  s21_decimal_big val = *result;
  while (!get_bit_big(*result, 0) && scale > 0) {
    s21_decimal_big tmp = div_simple_big(val, ten, &val);
    if (is_equal_simple_big(tmp, temp_null)) {
      scale--;
      for (int i = 0; i < 8; i++) {
        result->bits[i] = val.bits[i];
      }
    } else
      break;
  }
  set_scale_big(result, scale);
  set_sign_big(result, sign);
  return code;
}

// int s21_truncate_big(s21_decimal_big value, s21_decimal_big *result) {
//   int sign = get_sign_big(value);
//   int scale = get_scale_big(value);
//   int code = OK;
//   if (scale == 0) {
//     *result = value;
//     return OK;
//   }
//   s21_decimal_big temp = {{0, 0, 0, 0, 0, 0, 0, 0}};
//   code = s21_from_int_to_decimal_big(10, &temp);
//   int i = 0;
//   *result = value;
//   while (i < scale) {
//     div_simple_big(*result, temp, result);
//     i++;
//   }
//   if (result->bits[0]) set_sign_big(result, sign);
//   return scale > 28 ? NUMBER_MIN_INF : code;
// }
// int s21_from_int_to_decimal_big(int src, s21_decimal_big *dst) {
//   if (dst == NULL) {
//     return ERROR_CONVERT;
//   }
//   *dst = (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}};
//   int sign = (src >= 0) ? 0 : 1;
//   src = (src >= 0) ? src : -src;
//   for (int i = 0; i < 224; i++) {
//     set_bit_big(dst, i, src % 2);
//     src /= 2;
//   }
//   set_sign_big(dst, sign);
//   return OK;
// }
void sum_bit_big(s21_decimal_big res, s21_decimal_big *result) {
  unsigned i = 0;
  int con = 0;

  while (i < S21_OLOLONG_BIG) {
    int tmp = 0;
    int x = get_bit_big(*result, i);
    int y = get_bit_big(res, i);
    tmp = x + y + con;
    if (tmp > 1) {
      con = 1;
      tmp %= 2;
    } else
      con = 0;
    set_bit_big(result, i, tmp);
    i++;
  }
}