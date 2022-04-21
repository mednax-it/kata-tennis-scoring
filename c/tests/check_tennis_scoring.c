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
    ck_assert_uint_eq(Love, PlayerBlue.score->score);
    ck_assert_uint_eq(Love, PlayerRed.score->score);

    /* There is no winner */
    ck_assert_ptr_eq(NULL, Winner);
}
END_TEST

START_TEST(test_next_score)
{
    Score_Structure score = { Love, 0 };
    Player_Struct player = { &score };

    next_score(&player.score);
    ck_assert_int_eq(player.score->score, Fifteen);

    next_score(&player.score);
    ck_assert_int_eq(player.score->score, Thirty);

    next_score(&player.score);
    ck_assert_int_eq(player.score->score, Fourty);

    next_score(&player.score);
    ck_assert_int_eq(player.score->score, WinningScore);

    next_score(&player.score);
    ck_assert_int_eq(player.score->score, WinningScore);
}
END_TEST

START_TEST(test_get_score)
{
    Score_Structure score_a = { Love, 0 };
    Score_Structure score_b = { Love, 0 };
    Player_Struct player_a = { &score_a };
    Player_Struct player_b = { &score_b };
    char score_string[80] = "zero";

    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "love-all");

    next_score(&player_a.score);
    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "15-love");

    next_score(&player_b.score);
    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "15-all");

    next_score(&player_b.score);
    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "15-30");

    next_score(&player_a.score);
    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "30-all");

    next_score(&player_a.score);
    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "40-30");

    next_score(&player_b.score);
    get_score(&player_a, &player_b, (char*)&score_string);
    ck_assert_str_eq(score_string, "40-all");
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
    tcase_add_test(tc_tennis, test_next_score);
    tcase_add_test(tc_tennis, test_get_score);
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

    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
