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
                        //  printf("\n");
                        //  for (int i = 127; i >= 0; i--) {
                        //    printf("%d", get_bit(dec1, i));
                        //  }
                        //  printf("\n");
                        //  for (int i = 127; i >= 0; i--) {
                        //    printf("%d", get_bit(dec2, i));
                        //  }
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
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
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

//самые большие отрицательные, с разными степенями
START_TEST(test_less13) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

//первое больше
START_TEST(test_less14) {
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

//первое больше
START_TEST(test_less15) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

//второе больше
START_TEST(test_less16) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 109);  // 35/10^109
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TRUE);
}
END_TEST

//одинаковые
START_TEST(test_less17) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^56
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

//нули с офигеть какой большой степенью (Одинаковые)
START_TEST(test_less18) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

//нули положительный и отрицательный (первое больше)
START_TEST(test_less19) {
  // положительный ноль
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // отрицательный
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 16);
  set_sign(&dec2, 1);
  set_scale(&dec2, 16);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

//нули положительный и отрицательный (первое больше)
START_TEST(test_less20) {
  // отрицательный ноль
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // положительный ноль
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 16);
  set_sign(&dec2, 0);
  set_scale(&dec2, 16);
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, FALSE);
}
END_TEST

Suite *suite_s21_is_less(void) {
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
  tcase_add_test(tc, test_less13);
  tcase_add_test(tc, test_less14);
  tcase_add_test(tc, test_less15);
  tcase_add_test(tc, test_less16);
  tcase_add_test(tc, test_less17);
  tcase_add_test(tc, test_less18);
  tcase_add_test(tc, test_less19);
  tcase_add_test(tc, test_less20);

  suite_add_tcase(s, tc);
  return s;
}
