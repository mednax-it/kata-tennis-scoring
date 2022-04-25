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
    return {
        'scores': {
            Player.ONE: Score.LOVE,
            Player.TWO: Score.LOVE,
        },
        'winner': None,
    }

def next_score(current_score):
    if current_score == Score.WINNER:
        return None
    scores = list(Score)
    return scores[scores.index(current_score) + 1]

def award_point(game, player):
    new_score = next_score(game['scores'][player])
    new_scores = {
        **game['scores'],
        **{ player: new_score },
    }
    winner = player if new_score == Score.WINNER else None
    return {
        **game,
        **{ 'scores': new_scores, 'winner': winner }
    }
