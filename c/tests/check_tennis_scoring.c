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

START_TEST(test_game_initial_state)
{
    /* We have two players */
    ck_assert_ptr_ne(NULL, &PlayerBlue);
    ck_assert_ptr_ne(NULL, &PlayerRed);

    /* They both have a score of 0 (love) */
    ck_assert_uint_eq(0, PlayerBlue.score);
    ck_assert_uint_eq(0, PlayerRed.score);

    /* There is no winner */
    ck_assert_ptr_eq(NULL, Winner);
}
END_TEST

Suite * tennis_scoring_suite(void)
{
    Suite *s;
    TCase *tc_core, *tc_tennis;
    TCase *tc_limits;

    s = suite_create("TennisScoring");

    /* Core test case */
    tc_core = tcase_create("Framework");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_framework);
    suite_add_tcase(s, tc_core);

    /* Tennis test case */
    tc_tennis = tcase_create("Tennis");

    tcase_add_test(tc_tennis, test_game_initial_state);
    suite_add_tcase(s, tc_tennis);

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
