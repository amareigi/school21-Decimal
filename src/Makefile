CC = gcc
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
s21_DECIMAL_C = s21_*.c
s21_DECIMAL_O = s21_*.o
ADD_C = add_*.c 
ADD_O = add_*.o 
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit



all: clean gcov_report

s21_decimal.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_DECIMAL_C) $(ADD_C) 
	ar rc s21_decimal.a $(s21_DECIMAL_O) $(ADD_O) -lm
	ranlib s21_decimal.a

test: s21_decimal.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c
# $(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_DECIMAL_C) main.o $(ADD_O $(SUITE_CASES_O) $(FLAG_TESTS) $(ASAN)
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_DECIMAL_C) main.o $(ADD_O) $(SUITE_CASES_O) $(FLAG_TESTS)
	./tests

valgrind_test: s21_decimal.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c -g
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_DECIMAL_C) main.o $(ADD_O) $(SUITE_CASES_O) $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./tests

gcov_report: test
	gcovr --html-details -o report.html

cpp_check:
	cppcheck --enable=all --force *.h *.c

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c
	clang-format -i *.c
	rm -rf .clang-format

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
