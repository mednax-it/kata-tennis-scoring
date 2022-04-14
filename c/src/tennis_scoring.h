#ifndef TENNIS_SCORING_H
#define TENNIS_SCORING_H

typedef enum Score_Enum_Type {
    Love,
    Fifteen,
    Thirty,
    Fourty,
    WinningScore
} Score_Enum;
typedef struct Score_Type {
    Score_Enum score;
    int value;
} Score_Structure;
typedef struct Player_Type {
    Score_Structure *score;
} Player_Struct;

extern Player_Struct PlayerBlue;
extern Player_Struct PlayerRed;
extern Player_Struct *Winner;
extern void next_score(Score_Structure **score);

#endif /* TENNIS_SCORING_H */
