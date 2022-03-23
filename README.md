# 🎾 Tennis Scoring Kata

## 🥷 The Kata

Source: [https://github.com/ardalis/kata-catalog](https://github.com/ardalis/kata-catalog)

## 💻 Setup

Note: this assumes you have a recent-ish version of Python 3 and Poetry both setup locally. Be careful on the Poetry install; right now they're changing their installation process and you want to be sure to [use the new installation process](https://python-poetry.org/docs/master/#installation).

1. [Fork this repo](https://docs.github.com/en/get-started/quickstart/fork-a-repo).
1. Clone your forked repo to your local machine
1. (Optional) Checkout a task branch if you want to leave your `main` in pristine condition for easy resets: `git checkout -b interation1`
1. Install your dependencies: `poetry install`

You should now be ready to code!

Note that all the commands below assume your virtualenv is active. You can either do that by prefixing the command with `poetry run`, e.g., `poetry run ptw`, or you can spawn a shell with the virtualenv activated by running `poetry shell`.

- To run all tests: `pytest`
- To run all tests in watch mode: `ptw`
- To run a specific module of tests: `pytest test/test_tennis_scoring.py`
- To run a specific test: `pytest test/test_tennis_scoring.py::test_start_game` or `pytest test/test_tennis_scoring.py::TestGame::test_start`

## 🏸 Background

In a game of tennis, a player begins with a score of love (0). With each success, the player earns more points. The points are earned in this sequence:

- love (0)
- 15
- 30
- 40

If a player has 40 and scores again, that player wins the game as long as the other player does not also have 40 points. If both players reach 40 points it is referred to as a 'deuce.'

Scoring during deuce give a player advantage. If the other player scores again, the score returns to deuce. If a player has advantage and scores again, that player wins the game.

### 📖 Instructions

Write a program to handle each of these requirements while scoring a two player game of tennis.

1. Complete each iteration before reading the next one.
1. It's recommended you perform this kata with a pairing partner and while writing tests.

#### 1️⃣ Iteration One

1. A game can be started with the following state:
   - Both players have a score of love
   - There is no winner

#### 2️⃣ Iteration Two

1. Players must be able to score points
   - scores should progress from 0 to 40, following the sequence above
1. The current score of either player should be available at any point during the game
   - scores are reported as "40-30", "15-love", etc.
   - when scores are tied, they are reported as "love-all", "15-all", "30-all", etc.

#### 3️⃣ Iteration Three

1. The 'deuce' case should be handled
   - If both players have 40 points, the score is reported as "deuce"
   - If a player scores, the score is reported as "advantage player 1"
   - If the player with the advantage scores again, they win
   - If the other player scores, the score reverts back to "deuce"
