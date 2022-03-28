import random

from tennis_scoring.game import (next_score, start, Player, Score)

def test_non_tied_game():
    my_game = start()
    while not my_game['winner']:
        scorer = Player.ONE
        current_score = my_game[scorer]
        my_game[scorer] = next_score(current_score)
        if my_game[scorer] == Score.WINNER:
            my_game['winner'] = scorer
    assert my_game['winner'] != None
    assert my_game['winner'] == Player.ONE
