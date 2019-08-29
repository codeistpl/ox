#pragma once

#pragma once
#include "../backend/matrix.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
using namespace testing;

TEST(matrix, dummy) {
  Matrix<int> m;
  EXPECT_EQ(unsigned(3), m.getWidth());
  EXPECT_EQ(unsigned(3), m.getHeight());

  for (unsigned c = 0; c < m.getWidth(); c++)
    for (unsigned r = 0; r < m.getHeight(); r++) {
      EXPECT_EQ(0, m.get(c, r));
      m.set(c, r, int(r));
      EXPECT_EQ(int(r), m.get(c, r));
    }
}
