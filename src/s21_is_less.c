#include "s21_decimal.h"

// returns:
// 1 - is less
// 0 - is not less

// int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
//   int is_less = 1;
//   if (get_scale(value_1) != get_scale(value_2)) {
//     normalize(&value_1, &value_2);
//   }
//   // если равны, то вовзращаем 0
//   if (s21_is_equal(value_1, value_2)) {
//     is_less = 0;
//   }
//   // если первое число-отрицательное, а второе положительное, то возвращаем 1
//   else if (get_sign(value_1) && (!get_sign(value_2))) {
//     is_less = 1;
//   }
//   // если value_1 - положительное, то возвращаем 0, так как оно больше
//   else if ((!get_sign(value_1)) && get_sign(value_2)) {
//     is_less = 0;
//   }
//   // если оба отрицательные, то сравниваем без учета знака
//   else if (get_sign(value_1) && get_sign(value_2)) {
//     for (int i = 95; i >= 0; i--) {
//       if (get_bit(value_1, i) != get_bit(value_2, i)) {
//         // если первое ноль, то второе больше
//         if (get_bit(value_1, i)) {
//           is_less = 1;
//           break;
//         } else {
//           is_less = 0;
//           break;
//         }
//       }
//     }
//   }
//   // оба положительные
//   else {
//     for (int i = 95; i >= 0; i--) {
//       if (get_bit(value_1, i) != get_bit(value_2, i)) {
//         // если не равны, проверяем бит первого значения, если 0 - то ставим
//         1 if (!get_bit(value_1, i)) {
//           is_less = 1;
//           break;
//         } else {
//           is_less = 0;
//           break;
//         }
//       }
//     }
//   }
//   return is_less;
// }

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  int code = TRUE;
  s21_decimal zero = {{0, 0, 0, 0}};
  if ((is_equal_simple(value1, zero))) {
    set_sign(&value1, 0);
  }
  if ((is_equal_simple(value2, zero))) {
    set_sign(&value2, 0);
  }

  if (get_scale(value1) != get_scale(value2)) {
    normalize(&value1, &value2);
  }
  if (is_equal_simple(value1, value2) &&
      (get_sign(value1) == get_sign(value2))) {
    code = FALSE;
  } else if (get_sign(value1) < get_sign(value2)) {
    code = FALSE;
  } else if (get_sign(value1) > get_sign(value2)) {
    code = TRUE;
  } else {
    if (get_sign(value1) == 1)
      code = is_greater_simple(value1, value2);
    else
      code = !is_greater_simple(value1, value2);
  }
  return code;
}