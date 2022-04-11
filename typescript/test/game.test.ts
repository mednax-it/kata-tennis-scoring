import { start, Player, Score } from "../src/game";

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
});
