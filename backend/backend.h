#pragma once

#include "backend_global.h"
#include "matrix.h"
#include <map>
#include <optional>

namespace ox {
enum State : char { Empty = 0, X, O };
enum Player : char { One = 1, Two };
enum WinType : char { Column = 0, Row, Diagonal, RewDiagonal };

struct Win {
  WinType type = WinType::Column;
  unsigned idx = 0;
};

class Backend {
public:
  Backend(unsigned chartSize = 3);
  void set(unsigned col, unsigned row, State s);
  State get(unsigned col, unsigned row) const;
  void switchPlayer();
  std::optional<Win> haveWin() const;
  void clear();
  unsigned getScore(Player p);
  Player getCurrentPlayer() const;
  std::vector<State> getData() const;

private:
  bool haveWinColumn(unsigned col) const;
  bool haveWinRow(unsigned row) const;
  bool haveWinDiag() const;
  bool haveWinRevDiag() const;
  void scoreCurrentPlayer();

  std::map<Player, unsigned> score = {{Player::One, 0}, {Player::Two, 0}};
  Player currentPlayer = Player::One;
  Matrix<State> chart;
};

} // namespace ox
