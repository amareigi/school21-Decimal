
#include "decimal_suitecases.h"
#include "s21_decimal.h"

START_TEST(test_negate0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 3
  int code = s21_negate(dec1, &res);
  //   printf("\n");
  //   printf("%s", string_number_res);
  //   printf("\n");
  //   for (int i = 127; i >= 0; i--) {
  //     printf("%d", get_bit(res, i));
  //   };
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(res, i));
  }
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_negate1) {
  // степень20
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000001010000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";
  int code = s21_negate(decimal1, &result);
  set_scale(&decimal1, 20);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(result, i));
  }
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_negate2) {
  // степень20
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000001010000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";
  int code = s21_negate(decimal1, &result);
  set_scale(&decimal1, 20);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(result, i));
  }
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_negate3) {
  // степень20
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";
  set_sign(&decimal1, 1);
  int code = s21_negate(decimal1, &result);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(result, i));
  }
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_negate4) {
  // степень20
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";
  set_sign(&decimal1, 1);
  int code = s21_negate(decimal1, &result);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(result, i));
  }
  ck_assert_int_eq(code, OK);
}
END_TEST

Suite *suite_s21_negate2(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_negate2");
  tc = tcase_create("case_s21_negate2");

  tcase_add_test(tc, test_negate0);
  tcase_add_test(tc, test_negate1);
  tcase_add_test(tc, test_negate2);
  tcase_add_test(tc, test_negate3);
  tcase_add_test(tc, test_negate4);

  suite_add_tcase(s, tc);
  return s;
}
