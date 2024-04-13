#include "decimal_suitecases.h"
#include "s21_decimal.h"

START_TEST(test_equal0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 0);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_equal1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 0);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_equal2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 25);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_equal3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000110011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 25);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_equal4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 26);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_equal5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 25);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_equal6) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^1
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_equal7) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^1
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_equal8) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^1
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

Suite *suite_s21_is_not_equal2(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_not_equal2");
  tc = tcase_create("case_s21_not_equal2");

  tcase_add_test(tc, test_equal0);
  tcase_add_test(tc, test_equal1);
  tcase_add_test(tc, test_equal2);
  tcase_add_test(tc, test_equal3);
  tcase_add_test(tc, test_equal4);
  tcase_add_test(tc, test_equal5);
  tcase_add_test(tc, test_equal6);
  tcase_add_test(tc, test_equal7);
  tcase_add_test(tc, test_equal8);

  suite_add_tcase(s, tc);
  return s;
}
