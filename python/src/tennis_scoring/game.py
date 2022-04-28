from enum import Enum
from typing import TypedDict


class Player(Enum):
    ONE = "player 1"
    TWO = "player 2"


class Score(Enum):
    LOVE = 0
    FIFTEEN = 15
    THIRTY = 30
    FOURTY = 40
    WINNER = 100


class GameState(TypedDict):
    scores: dict[Player, Score | None]
    winner: Player | None


def start() -> GameState:
    return {
        "scores": {
            Player.ONE: Score.LOVE,
            Player.TWO: Score.LOVE,
        },
        "winner": None,
    }


def next_score(current_score: Score | None) -> Score | None:
    if not current_score or current_score == Score.WINNER:
        return None
    scores = list(Score)
    return scores[scores.index(current_score) + 1]


def award_point(game: GameState, player: Player) -> GameState:
    new_score = next_score(game["scores"][player])
    scores = {
        **game["scores"],
        **{player: new_score},
    }
    winner = player if new_score == Score.WINNER else None
    return {"scores": scores, "winner": winner}
