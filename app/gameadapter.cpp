#include "gameadapter.h"
#include <../backend/backend.h>
#include <QDebug>

namespace {
QVector<int> states2ints(std::vector<ox::State> states) {
  QVector<int> ints(int(states.size()));
  std::transform(states.begin(), states.end(), ints.begin(),
                 [](ox::State s) -> int { return int(s); });
  return ints;
}

int player2Int(ox::Player p) { return int(p); }

} // namespace

GameAdapter::GameAdapter(QObject *parent)
    : QObject(parent), backend(ox::Backend(3)) {}

void GameAdapter::onFieldClick(int col, int row) {
  if (backend.haveWin())
    return;

  backend.set(unsigned(col), unsigned(row),
              backend.getCurrentPlayer() == ox::Player::One ? ox::State::O
                                                            : ox::State::X);
  emit dataChanged(states2ints(backend.getData()));
  emit playerChanged(player2Int(backend.getCurrentPlayer()));
  emit scoreChanged(int(backend.getScore(ox::Player::One)),
                    int(backend.getScore(ox::Player::Two)));
  auto win = backend.haveWin();
  if (win) {
    switch (win->type) {
    case ox::WinType::Column:
      emit columnWin(int(win->idx));
      break;
    case ox::WinType::Row:
      emit rowWin(int(win->idx));
      break;
    case ox::WinType::Diagonal:
      emit diagonalWin();
      break;
    case ox::WinType::RewDiagonal:
      emit revDiagonalWin();
      break;
    }
  }
}

void GameAdapter::clear() {
  backend.clear();
  emit dataChanged(states2ints(backend.getData()));
  emit playerChanged(player2Int(backend.getCurrentPlayer()));
}
