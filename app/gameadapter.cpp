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
} // namespace

GameAdapter::GameAdapter(QObject *parent)
    : QObject(parent), backend(ox::Backend(3)) {}

void GameAdapter::onFieldClick(int col, int row) {
  qDebug() << __FUNCTION__ << col << row;
  backend.set(unsigned(col), unsigned(row),
              backend.getCurrentPlayer() == ox::Player::One ? ox::State::O
                                                            : ox::State::X);
  emit dataChanged(states2ints(backend.getData()));
}
