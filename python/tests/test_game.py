from tennis_scoring.game import (start, Player, Score)

def test_start():
    game = start()
    assert game[Player.ONE] == Score.LOVE
    assert game[Player.TWO] == Score.LOVE
    assert game['winner'] == None
