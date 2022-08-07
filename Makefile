CC = gcc
# OBJECTS =
# SOURSES = 
GCOVFLAGS = -lcheck -lgcov -coverage
GCOVFLAGSLIN = -lcheck -lgcov -coverage -lm
CFLAGS = -Werror -Wextra -Wall -std=c11


all: clean s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(CFLAGS) -g -c *.c
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a
test: s21_matrix.a
	gcc $(GCOVFLAGSLIN) -g -c *.c ./Tests/s21_tests.c
	gcc $(GCOVFLAGSLIN) -fsanitize=address *.o -o matrix_test
	./matrix_test
gcov_report: s21_matrix.a test
	gcovr .
	gcovr . --html-details coverage.html
	open coverage.html
check: s21_matrix.a
	@cppcheck *.h *.c
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	@$(CC) *.c s21_tests.c -lcheck -lm
	@valgrind --leak-check=full ./a.out
	@rm CPPLINT.cfg
clean:
	rm -rf ./*.gcno *.css ./matrix_test ./*.o ./*.a ./a.out ./coverage*.html ./*.gcov ./*.gcda ./CPPLINT*
rebuild:
	$(MAKE) clean
	$(MAKE) all
