from tennis_scoring.game import (start, Player, Score)

def test_start():
    assert start() == {
        Player.ONE: Score.LOVE, Player.TWO: Score.LOVE, 'winner': None}
