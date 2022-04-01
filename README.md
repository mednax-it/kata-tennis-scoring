# 🎾 Tennis Scoring Kata

## 🥷 The Kata

Source: [https://github.com/ardalis/kata-catalog](https://github.com/ardalis/kata-catalog)

## 💻 Setup

See the READMEs in each language-specific directory for more details on getting up and running.

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
