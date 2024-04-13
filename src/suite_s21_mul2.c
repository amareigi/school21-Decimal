#include "decimal_suitecases.h"
#include "s21_decimal.h"

START_TEST(mul2_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000001111101";  //
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 125
  set_scale(&dec1, 3);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000100";  // 4
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 4
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5

  int response = s21_mul(dec1, dec2, &res);
  ;
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }

  ck_assert_int_eq(0, get_sign(res));  // 5
  ck_assert_int_eq(1, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "001101011101101001010111111100100110011110010011000000111111011100011010"
      "101010101010101010101011";  // 16666666666666666666666666667
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 16666666666666666666666666667
  set_scale(&dec1, 5);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3
  set_scale(&dec2, 5);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "101000011000111100000111110101110011011010111001000010111110010101010000"
      "000000000000000000000001";  // 50000000000000000000000000001

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 50000000000000000000000000001
  ck_assert_int_eq(10, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "001101011101101001010111111100100110011110010011000000111111011100011010"
      "101010101010101010101011";  // 16666666666666666666666666667
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 16666666666666666666666666667
  set_scale(&dec1, 5);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 3
  set_scale(&dec2, 5);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "101000011000111100000111110101110011011010111001000010111110010101010000"
      "000000000000000000000001";  // 50000000000000000000000000001

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(1, get_sign(res));  // 50000000000000000000000000001
  ck_assert_int_eq(10, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000001111101";  //
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  // -125
  set_scale(&dec1, 3);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000100";  // 4
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // -4
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5

  int response = s21_mul(dec1, dec2, &res);
  ;
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }

  ck_assert_int_eq(0, get_sign(res));  // 5
  ck_assert_int_eq(1, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000010101100010101000100110010100001010010110111000000001100101100000101"
      "010101010101010101010101";  // 3333333333333333333333333333
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "001000000100111111001110010111100011111000100101000000100110000100001111"
      "111111111111111111111111";  // 9999999999999999999999999999

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(1, get_sign(res));  // 9999999999999999999999999999
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "001000000100111111001110010111100011111000100101000000100110000100001111"
      "111111111111111111111111";  // 9999999999999999999999999999
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 9999999999999999999999999999
  set_scale(&dec2, 28);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111110111";  // 79228162514264337593543950327

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 1
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 2);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 5
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 2

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 2
  ck_assert_int_eq(3, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_12) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000010101100010101000100110010100001010010110111000000001100101100000101"
      "010101010101010101010101";  // 3333333333333333333333333333
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "001000000100111111001110010111100011111000100101000000100110000100001111"
      "111111111111111111111111";  // 9999999999999999999999999999

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 9999999999999999999999999999
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 1
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000001010";  // 10
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 10
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 0

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_15) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950335
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000001010";  // 10
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 10
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 0

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(1, get_sign(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(mul2_16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000001010";  // 10
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 0
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(2, response);
}
END_TEST

START_TEST(mul2_17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950335
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000001010";  // 10
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 10
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_mul(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(0, get_sign(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(1, response);
}
END_TEST

Suite *suite_s21_mul2(void) {
  Suite *s = suite_create("mul2");
  TCase *tc = tcase_create("mul2");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, mul2_1);
  tcase_add_test(tc, mul2_2);
  tcase_add_test(tc, mul2_3);
  tcase_add_test(tc, mul2_4);
  tcase_add_test(tc, mul2_5);
  tcase_add_test(tc, mul2_6);
  tcase_add_test(tc, mul2_8);
  tcase_add_test(tc, mul2_12);
  tcase_add_test(tc, mul2_13);
  tcase_add_test(tc, mul2_14);
  tcase_add_test(tc, mul2_15);
  tcase_add_test(tc, mul2_16);
  tcase_add_test(tc, mul2_17);
  return s;
}
