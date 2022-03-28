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

def point(game, player):
    new_score = next_score(game[player])
    winner = player if new_score == Score.WINNER else None
    return {**game, **{player: new_score, 'winner': winner}}

def next_score(score):
    if score == Score.WINNER:
        return None
    scores = list(Score)
    return scores[scores.index(score) + 1]
