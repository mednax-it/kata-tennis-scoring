from enum import Enum

class Player(Enum):
    ONE = 1
    TWO = 2


class Score(Enum):
    LOVE = 0
    FIFTEEN = 15
    THIRTY = 30
    FOURTY = 40
    WINNER = 100


def start():
    return {Player.ONE: Score.LOVE, Player.TWO: Score.LOVE, 'winner': None}


def next_score(score):
    if score == Score.WINNER:
        return None
    scores = list(Score)
    return scores[scores.index(score) + 1]
