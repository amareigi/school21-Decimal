#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = (s21_decimal){{0, 0, 0, 0}};
  int response = 0;
  if (is_equal_simple(value_2, (s21_decimal){{0, 0, 0, 0}})) {
    response = 3;
    return response;
  }
  s21_decimal_big res_big = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_big value_1_big = from_decimal_to_big(value_1);
  s21_decimal_big value_2_big = from_decimal_to_big(value_2);
  s21_decimal_big pre_frac = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_big fraction = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_big integral = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_big remainder =
      div_simple_big(value_1_big, value_2_big, &integral);

  int scl3 = 0;
  while ((is_greater_simple_big(remainder,
                                (s21_decimal_big){{0, 0, 0, 0, 0, 0, 0, 0}})) &&
         scl3 <= 30) {
    scl3++;
    mult_10_big(remainder, &remainder);
    remainder = div_simple_big(remainder, value_2_big, &pre_frac);
    set_scale_big(&pre_frac, scl3);
    s21_add_big(fraction, pre_frac, &fraction);
  }

  s21_add_big(integral, fraction, &res_big);

  int overflow = 0;
  int scl1 = get_scale_big(value_1_big);
  int scl2 = get_scale_big(value_2_big);
  scl3 = get_scale_big(res_big);
  scl3 = scl1 - scl2 + scl3;
  if (scl3 < 0) {
    while (scl3 < 0) {
      overflow += mult_10_big(res_big, &res_big);
      scl3++;
    }
  }

  set_scale_big(&res_big, scl3);
  round_banker_big(&res_big);
  overflow += from_big_to_decimal(res_big, result);

  if (get_sign(value_1) == get_sign(value_2))
    set_sign(result, 0);
  else
    set_sign(result, 1);
  if (overflow) response = get_sign(*result) ? 2 : 1;
  return response;
}