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
});
