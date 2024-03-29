#include "backend.h"

namespace ox {

Backend::Backend(unsigned chartSize) : chart(chartSize) {}

void Backend::set(unsigned col, unsigned row, State s) {
  if (chart.get(col, row) != State::Empty)
    return;

  if ((currentPlayer == Player::One && s == State::O) ||
      (currentPlayer == Player::Two && s == State::X)) {
    chart.set(col, row, s);
    if (haveWin()) {
      scoreCurrentPlayer();
    }
    switchPlayer();
  }
}

State Backend::get(unsigned col, unsigned row) const {
  return State(chart.get(col, row));
}

void Backend::switchPlayer() {
  if (currentPlayer == Player::One) {
    currentPlayer = Player::Two;
  } else {
    currentPlayer = Player::One;
  }
}

std::optional<Win> Backend::haveWin() const {
  for (unsigned x = 0; x < chart.getWidth(); x++) {
    if (haveWinColumn(x))
      return Win{WinType::Column, x};
    if (haveWinRow(x))
      return Win{WinType::Row, x};
  }
  if (haveWinDiag())
    return Win{WinType::Diagonal};

  if (haveWinRevDiag())
    return Win{WinType::RewDiagonal};

  return std::nullopt;
}

void Backend::clear() {
  chart.clear();
  currentPlayer = Player::One;
}

unsigned Backend::getScore(Player p) { return score.at(p); }

Player Backend::getCurrentPlayer() const { return currentPlayer; }

std::vector<State> Backend::getData() const { return chart.getData(); }

bool Backend::haveWinColumn(unsigned row) const {
  for (unsigned col = 1; col < chart.getWidth(); col++) {
    if (chart.get(0, row) == State::Empty ||
        chart.get(0, row) != chart.get(col, row))
      return false;
  }
  return true;
}

bool Backend::haveWinRow(unsigned col) const {
  for (unsigned row = 1; row < chart.getWidth(); row++) {
    if (chart.get(col, 0) == State::Empty ||
        chart.get(col, 0) != chart.get(col, row))
      return false;
  }
  return true;
}

bool Backend::haveWinDiag() const {
  for (unsigned x = 1; x < chart.getWidth(); x++) {
    if (chart.get(0, 0) == State::Empty || chart.get(0, 0) != chart.get(x, x))
      return false;
  }
  return true;
}

bool Backend::haveWinRevDiag() const {
  unsigned max = chart.getWidth() - 1;
  for (unsigned x = 1; x < chart.getWidth(); x++) {
    if (chart.get(max, 0) == State::Empty ||
        chart.get(max, 0) != chart.get(max - x, x))
      return false;
  }
  return true;
}

void Backend::scoreCurrentPlayer() { score[currentPlayer]++; }

} // namespace ox
