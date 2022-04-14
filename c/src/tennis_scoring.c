#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tennis_scoring.h"

Score_Structure SCORES[] = {
    { Love, 0 },
    { Fifteen, 15 },
    { Thirty, 30 },
    { Fourty, 40 },
    { WinningScore, -1 }
};
Player_Struct PlayerBlue = {
    &SCORES[Love]
};
Player_Struct PlayerRed = {
    &SCORES[Love]
};
Player_Struct *Winner = NULL;

void next_score(Score_Structure **current_score) {
    if ((*current_score)->score != WinningScore)
    {
        *current_score = &SCORES[(*current_score)->score + 1];
    }
}

void get_score_string(Score_Structure *score, char *score_string) {
    if (score->score == Love) {
        strcpy(score_string, "love");
    }
    else {
        sprintf(score_string, "%d", score->value);
    }
}

void get_score(Player_Struct *score_a, Player_Struct *score_b, char *score_string) {
    char left[6], right[6];

    get_score_string(score_a->score, left);
    if (score_a->score->score == score_b->score->score) {
        strcpy(right, "all");
    }
    else {
        get_score_string(score_b->score, right);
    }
    sprintf(score_string, "%s-%s", left, right);
}
