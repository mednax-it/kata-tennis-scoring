# 🎾 Tennis Scoring Kata

## 🥷 The Kata

Source: [https://github.com/ardalis/kata-catalog](https://github.com/ardalis/kata-catalog)


# 💻 Setup

### Debian (Ubuntu)
The following programs should be installed on your system using the Aptitute package manager:
- sudo apt install m4 autoconf automake libtool check

### Mac OSX
The following programs should be installed on your system using the Homebrew package manager. Run the "brew doctor" command first, and fix any issues recommended by the tool:
- brew install autoconf automake libtool check pkg-config


# 💻 Building

When working at a clean subdirectory, execute the following commands from a terminal to run the autotools with verbose, install, and force flags. This should determine the installed compiler and libraries needed, and generate make files for the project:
- autoreconf -vif
- ./configure


# 💻 Testing

To compile and run the unit-tests, run the following command from a terminal:
- make check


# 🏸 Background

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
