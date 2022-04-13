#ifndef TENNIS_SCORING_H
#define TENNIS_SCORING_H

typedef enum Score_Type {
    Love = 0,
    Fifteen = 15,
    Thirty = 30,
    Fourty = 40
} Score_Enum;
typedef struct Player_Type {
    Score_Enum score;
} Player_Struct;
extern Player_Struct PlayerBlue;
extern Player_Struct PlayerRed;
extern Player_Struct *Winner;

#endif /* TENNIS_SCORING_H */
