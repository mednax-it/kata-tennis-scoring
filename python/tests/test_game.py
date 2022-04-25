import pytest

from tennis_scoring.game import (award_point, next_score, start, Player, Score)

def test_start():
    game = start()
    assert game['scores'][Player.ONE] == Score.LOVE
    assert game['scores'][Player.TWO] == Score.LOVE
    assert game['winner'] == None


def test_next_score():
    assert next_score(Score.LOVE) == Score.FIFTEEN
    assert next_score(Score.FIFTEEN) == Score.THIRTY
    assert next_score(Score.THIRTY) == Score.FOURTY
    assert next_score(Score.FOURTY) == Score.WINNER
    assert next_score(Score.WINNER) == None


def test_award_point_normal():
    game = start()
    game = award_point(game, Player.ONE)
    assert game['scores'][Player.ONE] == Score.FIFTEEN
    assert game['scores'][Player.TWO] == Score.LOVE
    assert game['winner'] == None


def test_award_point_game():
    game = start()
    game['scores'][Player.ONE] = Score.FOURTY
    game = award_point(game, Player.ONE)
    assert game['scores'][Player.ONE] == Score.WINNER
    assert game['scores'][Player.TWO] == Score.LOVE
    assert game['winner'] == Player.ONE
