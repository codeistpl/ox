#pragma once
#include <../backend/backend.h>
#include <QObject>
#include <QVector>
#include <memory>

namespace ox {
class Backend;
}

class GameAdapter : public QObject {
  Q_OBJECT
public:
  explicit GameAdapter(QObject *parent = nullptr);

  Q_INVOKABLE void onFieldClick(int col, int row);
  Q_INVOKABLE void clear();

signals:
  void dataChanged(QVector<int> data);
  void playerChanged(int player);
  void scoreChanged(int scoreP1, int scoreP2);
  void columnWin(int idx);
  void rowWin(int idx);
  void diagonalWin();
  void revDiagonalWin();

public slots:

private:
  ox::Backend backend;
};
