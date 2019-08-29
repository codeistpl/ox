#pragma once

#include "backend_global.h"
#include "matrix.h"
#include <map>
#include <tuple>

namespace ox {
enum State : char { Empty = 0, X, O };
enum Player : char { One = 1, Two };

class Backend {
public:
  Backend(unsigned chartSize = 3);
  void set(unsigned col, unsigned row, State s);
  State get(unsigned col, unsigned row) const;
  void switchPlayer();
  bool haveWin() const;
  void clear();
  unsigned getScore(Player p);

private:
  bool haveWinColumn(unsigned col) const;
  bool haveWinRow(unsigned row) const;
  bool haveWinDiag() const;
  void scoreCurrentPlayer();

  std::map<Player, unsigned> score = {{Player::One, 0}, {Player::Two, 0}};
  Player currentPlayer = Player::One;
  Matrix<State> chart;
};

} // namespace ox
