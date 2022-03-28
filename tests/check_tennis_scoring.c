#include <config.h>
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "../src/tennis_scoring.h"

void setup(void)
{
}

void teardown(void)
{
}

START_TEST(test_framework)
{
    ck_assert_str_ne("stringA", "stringB");
    ck_assert_int_eq(4 * 6, 24);
}
END_TEST

Suite * tennis_scoring_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("TennisScoring");

    /* Core test case */
    tc_core = tcase_create("Framework");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_framework);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = tennis_scoring_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
