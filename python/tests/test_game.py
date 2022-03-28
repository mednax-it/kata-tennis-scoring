import pytest

from tennis_scoring.game import (next_score, point, start, Player, Score)

def test_start():
    assert start() == {
        Player.ONE: Score.LOVE, Player.TWO: Score.LOVE, 'winner': None}


def test_point_normal():
    game = start()
    game = point(game, Player.ONE)
    assert game[Player.ONE] == Score.FIFTEEN
    assert game['winner'] == None


def test_point_game():
    game = start()
    game[Player.ONE] = Score.FOURTY
    game = point(game, Player.ONE)
    assert game[Player.ONE] == Score.WINNER
    assert game['winner'] == Player.ONE


def test_next_score():
    assert next_score(Score.LOVE) == Score.FIFTEEN
    assert next_score(Score.FIFTEEN) == Score.THIRTY
    assert next_score(Score.THIRTY) == Score.FOURTY
    assert next_score(Score.FOURTY) == Score.WINNER
    assert next_score(Score.WINNER) == None
