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

signals:
  void dataChanged(QVector<int> data);

public slots:

private:
  ox::Backend backend;
};
