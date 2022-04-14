import { awardPoint, nextScore, start, Player, Score } from "../src/game";

describe("game", () => {
  describe("#start", () => {
    it("should create a new game with no winner and both players at love", () => {
      const { scores, winner } = start();
      expect(scores[Player.ONE]).toBe(Score.LOVE);
      expect(scores[Player.TWO]).toBe(Score.LOVE);
      expect(winner).toBe(null);
    });
  });

  describe("#nextScore", () => {
    it("should advance a player's score to the next point value", () => {
      expect(nextScore(Score.LOVE)).toBe(Score.FIFTEEN);
      expect(nextScore(Score.FIFTEEN)).toBe(Score.THIRTY);
      expect(nextScore(Score.THIRTY)).toBe(Score.FOURTY);
      expect(nextScore(Score.FOURTY)).toBe(Score.WINNER);
    });
  });

  describe("#awardPoint", () => {
    it("should return a game state with the next point value", () => {
      const startingGameState = start();
      const newGameState = awardPoint(startingGameState, Player.ONE);
      expect(newGameState.scores[Player.ONE]).toBe(Score.FIFTEEN);
      expect(newGameState.scores[Player.TWO]).toBe(Score.LOVE);
      expect(newGameState.winner).toBe(null);
    });

    it("should return a game state with the winner declared", () => {
      let game = start();
      const player = Player.ONE;
      while (game.scores[player] !== Score.WINNER) {
        game = awardPoint(game, player);
      }
      expect(game.scores[Player.ONE]).toBe(Score.WINNER);
      expect(game.scores[Player.TWO]).toBe(Score.LOVE);
      expect(game.winner).toBe(Player.ONE);
    });
  });
});
