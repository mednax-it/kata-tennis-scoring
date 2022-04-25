from tennis_scoring.game import (award_point, start, Player, Score)

def test_non_tied_game():
    game = start()
    while not game['winner']:
        game = award_point(game, Player.ONE)
    assert game['winner'] == Player.ONE
