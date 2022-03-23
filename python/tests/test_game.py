from tennis_scoring.game import start

def test_start():
    (player1, player2) = start()
    assert player1['score'] == 0
    assert player2['score'] == 0
