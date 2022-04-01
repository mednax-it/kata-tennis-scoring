#ifndef TENNIS_SCORING_H
#define TENNIS_SCORING_H

typedef struct Player_Type {
    unsigned int score;
} Player_Struct;
extern Player_Struct PlayerBlue;
extern Player_Struct PlayerRed;
extern Player_Struct *Winner;

#endif /* TENNIS_SCORING_H */
