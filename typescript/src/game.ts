export enum Player {
  ONE = "player 1",
  TWO = "player 2",
}

export enum Score {
  LOVE = 0,
  FIFTEEN = 15,
  THIRTY = 30,
  FOURTY = 40,
  WINNER = 100,
}

export type GameState = {
  scores: Record<string, number>;
  winner: Player | null;
};

const scores = [
  Score.LOVE,
  Score.FIFTEEN,
  Score.THIRTY,
  Score.FOURTY,
  Score.WINNER,
];

export function start(): GameState {
  return {
    scores: {
      [Player.ONE]: Score.LOVE,
      [Player.TWO]: Score.LOVE,
    },
    winner: null,
  };
}

export function nextScore(currentScore: Score): Score {
  return scores[scores.indexOf(currentScore) + 1];
}

export function awardPoint(game: GameState, player: Player): GameState {
  const newScore = nextScore(game.scores[player]);
  const scores = {
    ...game.scores,
    ...{ [player]: newScore },
  };
  const winner = newScore === Score.WINNER ? player : null;
  return {
    ...game,
    ...{ scores, winner },
  };
}
