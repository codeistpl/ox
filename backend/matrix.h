#pragma once

#include <numeric>
#include <vector>

template <typename T> class Matrix {
public:
  Matrix(unsigned x = 3) : Matrix(x, x) {}
  Matrix(unsigned w, unsigned h) : width(w), height(h) {
    chart.resize(w * h);
    std::fill(chart.begin(), chart.end(), T());
  }

  unsigned getWidth() const { return width; }
  unsigned getHeight() const { return height; }
  T get(unsigned col, unsigned row) const {
    return chart.at(col * width + row);
  }
  void set(unsigned col, unsigned row, const T &val) {
    chart.at(col * width + row) = val;
  }
  void clear() { std::fill(chart.begin(), chart.end(), T()); }
  std::vector<T> getData() const { return chart; }

private:
  unsigned width = 0;
  unsigned height = 0;

  std::vector<T> chart;
};
