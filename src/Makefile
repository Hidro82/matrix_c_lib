CC = gcc
# OBJECTS =
# SOURSES = 
# ASAN = -fsanitize=address
FLAGC = -c
FLAGO = -o
GCOVFLAGS = -lcheck -lgcov -coverage
GCOVFLAGSLIN = --coverage
ERRFLAGS = -Werror -Wextra -Wall -std=c11
s21_matrix_C = s21_*.c
s21_matrix_O = obj/s21_*.o
s21_matrix_GCDA = covers/s21_*.gcda
TEST_C = Tests/tests.c
TEST_O = Tests/obj/tests.o
#MAIN_C = Tests/main.c
#MAIN_O = Tests/obj/main.o

all: clean s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(ASAN) $(ERRFLAGS) $(FLAGC) $(s21_matrix_C)
	mv s21_*.o obj
	ar rc s21_matrix.a $(s21_matrix_O)
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(ASAN) $(ERRFLAGS) $(FLAGC) $(TEST_C) $(MAIN_C)
	mv tests.o Tests/obj
	ar rc Tests/tests.a $(TEST_O)
	ranlib Tests/tests.a
	$(CC) $(ASAN) $(ERRFLAGS) $(GCOVFLAGS) $(FLAGO) matrix_test s21_matrix.a Tests/tests.a $(s21_matrix_C) $(MAIN_O) -lcheck
	./matrix_test

gcov_report: test
	mv *.gcda covers
	mv *.gcno covers
	gcov $(s21_matrix_GCDA)
	gcovr
	gcovr --html-details html/coverage.html
	open html/coverage.html
	mv *.gcov covers

check: s21_matrix.a
	@cppcheck *.h *.c
#	@cp ../materials/linters/CPPLINT.cfg ./
#	@python3 ../materials/linters/cpplint.py --extension=c $(s21_matrix_C) s21_matrix.h $(TEST_C) $(MAIN_C) Tests/tests.h
	@$(CC) *.c $(TEST_C) $(MAIN_C) -lcheck -lm
	@valgrind --leak-check=full ./a.out
#	@rm CPPLINT.cfg
	CK_FORK=no leaks --atExit -- ./matrix_test
#	mv *.gcda covers

clean:
	rm -rf a.out *.gcda *.gcno *.gcov ./covers/*.gcno html/*.css ./matrix_test ./obj/*.o ./*.a ./Tests/obj/*.o ./Tests/*.a ./html/coverage*.html ./covers/*.gcov ./covers/*.gcda ./CPPLINT*

rebuild:
	$(MAKE) clean
	$(MAKE) all
