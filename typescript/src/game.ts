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

export function start(): GameState {
  return {
    scores: {
      [Player.ONE]: Score.LOVE,
      [Player.TWO]: Score.LOVE,
    },
    winner: null,
  };
}
