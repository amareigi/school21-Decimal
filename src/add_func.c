#include "s21_decimal.h"
#define S21_MASK_BIT (1 << bit % 32)

int get_bit(s21_decimal number, int bit) {
  return ((number.bits[bit / 32] & S21_MASK_BIT) == 0) ? FALSE : TRUE;
}
void set_bit(s21_decimal *number, int bit, int sign) {
  sign == 0 ? (number->bits[bit / 32] &= ~S21_MASK_BIT)
            : (number->bits[bit / 32] |= (S21_MASK_BIT));
}
int get_sign(s21_decimal number) {
  int getBit = 0;
  unsigned int mask = 0;
  mask = 1U << 31;
  unsigned int currentBite = number.bits[3];

  if ((currentBite & mask) == mask) {
    getBit = 1;
  }
  return getBit;
}

void set_sign(s21_decimal *number, int value) {
  if (value != get_sign(*number)) {
    unsigned int mask = 0;
    mask = 1U << 31;
    number->bits[3] ^= mask;
  }
}

int get_scale(s21_decimal number) {
  int scale = 0;
  for (int i = 0, shift = 16; shift <= 23; ++i, ++shift) {
    unsigned int mask = 0;
    mask = 1U << shift;
    int bit = ((number.bits[3] & mask) == mask);
    scale += bit * pow(2, i);
  }
  return scale;
}

void set_scale(s21_decimal *number, int scale) {
  for (int shift = 16; shift <= 23; ++shift) {
    unsigned int mask = 0;
    mask = 1U << shift;
    if (scale > 0 && scale % 2 == 1) {
      number->bits[3] |= mask;
    } else {
      number->bits[3] &= ~mask;
    }
    scale /= 2;
  }
}

void set_binary_number(s21_decimal *number, const char *string_number) {
  for (int i = 0; i < 96; i++) {
    set_bit(number, i, string_number[95 - i] - '0');
  }
}

// char *show_bstr(int n, char *bstr) {
//   for (int i = 32 - 1; i >= 0; i--, n >>= 1) bstr[i] = (1 & n) + '0';
//   bstr[32] = '\0';

//   int i = 0;
//   while (bstr[i]) {
//     putchar(bstr[i]);
//     ++i;
//     if (i % 8 == 0 && bstr[i]) putchar(' ');
//   }
//   putchar('\n');

//   return bstr;
// }

int shift_left(s21_decimal *number) {
  int is_overflow = get_bit(*number, 95);
  for (int i = 95; i >= 0; i--) {
    if (i != 0) {
      set_bit(number, i, get_bit(*number, i - 1));
    } else {
      set_bit(number, i, 0);
    }
  }
  return is_overflow;
}

// int shift_right(s21_decimal *number) {
//   int is_overflow = get_bit(*number, 1);
//   for (int i = 0; i < 96; i++) {
//     if (i != 95) {
//       set_bit(number, i, get_bit(*number, i + 1));
//     } else {
//       set_bit(number, i, 0);
//     }
//   }
//   return is_overflow;
// }

void normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int scl1 = get_scale(*value_1);
  int scl2 = get_scale(*value_2);
  int sign1 = get_sign(*value_1);
  int sign2 = get_sign(*value_2);
  s21_decimal tmp_1 = *value_1;
  s21_decimal tmp_2 = *value_2;
  s21_decimal div_10 = {{10, 0, 0, 0}};

  if (scl1 != scl2) {
    while (scl1 != scl2) {
      int overflow = 0;
      if (scl1 > scl2) {
        overflow = mult_10(tmp_2, &tmp_2);
        if (overflow) break;
        *value_2 = tmp_2;
        scl2++;
      } else {
        overflow = mult_10(tmp_1, &tmp_1);
        if (overflow) break;
        *value_1 = tmp_1;
        scl1++;
      }
    }

    int tail = 0;
    int not_even;
    s21_decimal remainder;
    int target_scale = (scl1 > scl2) ? scl2 : scl1;
    while (scl1 != scl2) {
      if (scl1 > scl2) {
        scl1--;
        not_even = get_bit(tmp_1, 0);
        remainder = div_simple(tmp_1, div_10, &tmp_1);
        if (scl1 == target_scale) {
          if (is_greater_simple(remainder, (s21_decimal){{5, 0, 0, 0}})) {
            add_simple(tmp_1, (s21_decimal){{1, 0, 0, 0}}, &tmp_1);
          } else if ((is_equal_simple(remainder,
                                      (s21_decimal){{5, 0, 0, 0}})) &&
                     not_even && tail) {
            add_simple(tmp_1, (s21_decimal){{1, 0, 0, 0}}, &tmp_1);
          }
        }
        if (is_greater_simple(remainder, (s21_decimal){{0, 0, 0, 0}})) tail = 1;
        *value_1 = tmp_1;
      } else {
        scl2--;
        not_even = get_bit(tmp_2, 0);
        remainder = div_simple(tmp_2, div_10, &tmp_2);
        if (scl2 == target_scale) {
          if (is_greater_simple(remainder, (s21_decimal){{5, 0, 0, 0}})) {
            add_simple(tmp_2, (s21_decimal){{1, 0, 0, 0}}, &tmp_2);
          } else if ((is_equal_simple(remainder,
                                      (s21_decimal){{5, 0, 0, 0}})) &&
                     not_even && tail) {
            add_simple(tmp_2, (s21_decimal){{1, 0, 0, 0}}, &tmp_2);
          }
        }
        if (is_greater_simple(remainder, (s21_decimal){{0, 0, 0, 0}})) tail = 1;
        *value_2 = tmp_2;
      }
    }
    set_scale(value_1, scl1);
    set_scale(value_2, scl2);
    set_sign(value_1, sign1);
    set_sign(value_2, sign2);
  }
}

int low_scale(s21_decimal *value_1, s21_decimal *value_2) {
  int zero_scale = 0;
  int scl1 = get_scale(*value_1);
  int scl2 = get_scale(*value_2);
  if (scl1 == 0 || scl2 == 0) {
    zero_scale = 1;
  } else {
    s21_decimal div_10 = {{10, 0, 0, 0}};
    div_simple(*value_1, div_10, value_1);
    div_simple(*value_2, div_10, value_2);
    scl1--;
    scl2--;
    set_scale(value_1, scl1);
    set_scale(value_2, scl2);
  }
  return zero_scale;
}

s21_decimal_big from_decimal_to_big(s21_decimal value) {
  s21_decimal_big result = {{0, 0, 0, 0, 0, 0, 0, 0}};
  result.bits[0] = value.bits[0];
  result.bits[1] = value.bits[1];
  result.bits[2] = value.bits[2];
  result.bits[7] = value.bits[3];
  return result;
}

int from_big_to_decimal(s21_decimal_big value, s21_decimal *result) {
  *result = (s21_decimal){{0, 0, 0, 0}};
  int overflow = FALSE;
  if (((value.bits[3])) || (value.bits[4]) || (value.bits[5]) ||
      (value.bits[6])) {
    overflow = TRUE;
  } else {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[7];
  }
  if (overflow && get_sign_big(value)) {
    overflow = NUMBER_MIN_INF;
  }
  return overflow;
}
int convert_to_int(s21_decimal value) {
  int decimal_number = 0;
  int sign = get_sign(value);
  for (unsigned i = 0; i < 96; i++) {
    int res = get_bit(value, i);
    decimal_number += res * pow(2, i);
  }
  return sign == 0 ? decimal_number : -decimal_number;
}