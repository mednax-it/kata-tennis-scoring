#include <stdlib.h>
#include "tennis_scoring.h"

Player_Struct PlayerBlue = {
    Love
};
Player_Struct PlayerRed = {
    Love
};
Player_Struct *Winner = NULL;
static const Score_Enum ScoreMap[] = {
    Love,
    Fifteen,
    Thirty,
    Fourty,
    WinningScore
};

Score_Enum next_score(Score_Enum score) {
    Score_Enum new_score = score;

    if (score != WinningScore)
    {
        for (int i = 0; i < sizeof(ScoreMap) / sizeof(Score_Enum); i++)
        {
            if (score == ScoreMap[i]){
                new_score = ScoreMap[i + 1];
            }
        }
    }
    return new_score;
}

