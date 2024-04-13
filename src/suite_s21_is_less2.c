#include "decimal_suitecases.h"
#include "s21_decimal.h"

START_TEST(test_less0) {
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
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
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
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 0);  // 35/10^1
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_less3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  //
                        //   for (int i = 127; i >= 0; i--) {
                        //     printf("%d", get_bit(dec2, i));
                        //   }
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 5);  // 35/10^1
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 20);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 20);  //
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_less6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 0);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  //
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 1);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  //
                        //   printf("\n");
                        //   for (int i = 127; i >= 0; i--) {
                        //     printf("%d", get_bit(dec1, i));
                        //   }
                        //   printf("\n");
                        //   for (int i = 127; i >= 0; i--) {
                        //     printf("%d", get_bit(dec2, i));
                        //   }
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less8) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_less9) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 1);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

START_TEST(test_less10) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{2, 0, 0, 0}};
  set_sign(&dec2, 1);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less11) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 0);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

START_TEST(test_less12) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 0);
  s21_decimal dec2 = {{2, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

Suite *suite_s21_is_less2(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_is_less");
  tc = tcase_create("case_s21_is_less");

  tcase_add_test(tc, test_less0);
  tcase_add_test(tc, test_less1);
  tcase_add_test(tc, test_less2);
  tcase_add_test(tc, test_less3);
  tcase_add_test(tc, test_less4);
  tcase_add_test(tc, test_less5);
  tcase_add_test(tc, test_less6);
  tcase_add_test(tc, test_less7);
  tcase_add_test(tc, test_less8);
  tcase_add_test(tc, test_less9);
  tcase_add_test(tc, test_less10);
  tcase_add_test(tc, test_less11);
  tcase_add_test(tc, test_less12);

  suite_add_tcase(s, tc);
  return s;
}
