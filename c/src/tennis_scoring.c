#include <stdlib.h>
#include "tennis_scoring.h"

Score_Structure SCORES[] = {
    {
        Love, 0
    },
    {
        Fifteen, 15
    },
    {
        Thirty, 30
    },
    {
        Fourty, 40
    },
    {
        WinningScore, -1
    }
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

