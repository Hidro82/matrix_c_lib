#include "tests.h"

int main() {
    int no_failed = 0;

    Suite *s = s21_matrix_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, 2);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
