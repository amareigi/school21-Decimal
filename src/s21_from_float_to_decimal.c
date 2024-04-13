#include "s21_decimal.h"
// добавить флаг -lm при компиляции самой библиотеки, а не только при тестах

unsigned int get_float_sign(const float *src) {
  float value = *src;
  return value < 0.0f ? 1 : 0;
}

int get_float_exponent(const float *src) {
  fti tmp;
  tmp.fl = *src;
  return ((tmp.d & ~0x80000000) >> 23) - 127;
  // 0x80000000 в двоичном 1 а дальше нули, тут инвертируется, так что первый 0,
  // дальше все 1, в результате
  //  & обнуляем знак, >> 23 сдвигаем експоненту, зануляя мантису
  //  -127 так как експонента хранится как код со сдвигом
}

int check_num_small(float src) {
  return (fabsf(src) < 1e-28 && fabsf(src) > 0) || fabsf(src) > 7.922816E+28
             ? FALSE
             : TRUE;
}

double find_significant_digit(float src, int *scale, int *tmp_scale) {
  double tmp = 0;
  tmp = (double)fabs(src);
  int seven_digit_max = 9999999;
  while (((int)tmp / seven_digit_max != 0) && ((int)tmp != seven_digit_max)) {
    tmp = tmp / 10;
    (*tmp_scale)++;
  }
  int six_digit_max = 999999;
  //пока 7 цифр не найдём, или не закончится точность децимала
  while (*scale < 28 && ((int)tmp / six_digit_max == 0) &&
         ((int)tmp != six_digit_max)) {
    tmp = tmp * 10;
    (*scale)++;
  }
  if ((int)tmp != seven_digit_max) {
    tmp = round(tmp);
  }
  return tmp;
}
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = 1;
  if (dst == NULL || isnan(src) != 0 ||
      isinf(src) != 0)  //проверка входных параметров
    return err;
  int scale, tmp_scale;
  *dst = (s21_decimal){{0, 0, 0, 0}};
  unsigned int sign = get_float_sign(&src);
  scale = 0;
  tmp_scale = 0;
  if (check_num_small(src) && src != 0) {
    double tmp = find_significant_digit(src, &scale, &tmp_scale);
    fti mantissa;
    mantissa.fl = tmp;
    int exponent = get_float_exponent(&mantissa.fl);
    dst->bits[0] |= 1 << exponent;
    for (int i = exponent - 1, j = 22; j >= 0; i--, j--) {
      if (mantissa.d & 1 << j) dst->bits[0] |= 1 << i;
    }
    while (tmp_scale > 0) {
      tmp_scale--;
      mult_10(*dst, dst);
    }
    dst->bits[3] = (sign << 31) | (scale << 16);
    err = 0;
  }
  if (src == 0) {
    err = 0;
  }
  return err;
}
