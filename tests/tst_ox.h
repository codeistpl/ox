#pragma once
#include "../backend/backend.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace ox;

class TestOX : public ::testing::Test {
public:
  TestOX() = default;
  ~TestOX() = default;
  void testWinningCollumn(unsigned col);
  void testWinningRow(unsigned col);
  void Wins(State s);

protected:
  Backend b;
};

TEST(ox, set_get) {
  Backend b;
  b.set(1, 2, State::O);
  EXPECT_EQ(b.get(1, 2), State::O);
  ASSERT_THAT(0, Eq(0));
}

TEST(ox, set_double_O) {
  Backend b;
  b.set(1, 2, State::O); // player1
  EXPECT_EQ(b.get(1, 2), State::O);
  b.set(1, 2, State::X); // player2
  EXPECT_EQ(b.get(1, 2), State::O);
  b.set(1, 2, State::X); // player1
  EXPECT_EQ(b.get(1, 2), State::O);
}

TEST_F(TestOX, have_winning_collumn) {
  EXPECT_FALSE(b.haveWin());
  testWinningCollumn(0);
  testWinningCollumn(1);
  testWinningCollumn(2);
  b.clear();
  EXPECT_FALSE(b.haveWin());
}

TEST_F(TestOX, have_winning_row) {
  EXPECT_FALSE(b.haveWin());
  testWinningRow(0);
  testWinningRow(1);
  testWinningRow(2);
  b.clear();
  EXPECT_FALSE(b.haveWin());
}

TEST_F(TestOX, have_winning_diagonal) {
  b.clear();
  b.set(0, 0, State::O);
  b.set(1, 0, State::X);
  b.set(1, 1, State::O);
  b.set(0, 1, State::X);
  b.set(2, 2, State::O);
  EXPECT_TRUE(b.haveWin());
}

TEST_F(TestOX, have_winning_reverse_diagonal) {
  b.clear();
  b.set(0, 2, State::O);
  b.set(1, 0, State::X);
  b.set(1, 1, State::O);
  b.set(0, 1, State::X);
  b.set(2, 0, State::O);
  EXPECT_TRUE(b.haveWin());
}

void TestOX::Wins(State s) {
  auto xs = s == State::O ? State::X : State::O;
  if (s == State::X)
    b.set(2, 2, xs);
  b.set(0, 2, s);
  b.set(1, 0, xs);
  b.set(1, 1, s);
  b.set(0, 1, xs);
  b.set(2, 0, s);
}

TEST_F(TestOX, scoring) {
  b.clear();
  Wins(State::O);
  EXPECT_TRUE(b.haveWin());
  EXPECT_EQ(unsigned(1), b.getScore(Player::One));
  EXPECT_EQ(unsigned(0), b.getScore(Player::Two));
  b.clear();
  Wins(State::X);
  EXPECT_TRUE(b.haveWin());
  EXPECT_EQ(unsigned(1), b.getScore(Player::Two));
}

void TestOX::testWinningCollumn(unsigned col) {
  unsigned xcol = col == 1 ? 0 : 1;
  EXPECT_FALSE(b.haveWin());
  b.set(col, 0, State::O);
  EXPECT_FALSE(b.haveWin());
  b.set(xcol, 0, State::X);
  EXPECT_FALSE(b.haveWin());
  b.set(col, 1, State::O);
  EXPECT_FALSE(b.haveWin());
  b.set(xcol, 1, State::X);
  EXPECT_FALSE(b.haveWin());
  b.set(col, 2, State::O);
  EXPECT_TRUE(b.haveWin());
  b.clear();
  EXPECT_FALSE(b.haveWin());
}

void TestOX::testWinningRow(unsigned row) {
  unsigned xrow = row == 1 ? 0 : 1;
  EXPECT_FALSE(b.haveWin());
  b.set(0, row, State::O);
  EXPECT_FALSE(b.haveWin());
  b.set(0, xrow, State::X);
  EXPECT_FALSE(b.haveWin());
  b.set(1, row, State::O);
  EXPECT_FALSE(b.haveWin());
  b.set(1, xrow, State::X);
  EXPECT_FALSE(b.haveWin());
  b.set(2, row, State::O);
  EXPECT_TRUE(b.haveWin());
  b.clear();
  EXPECT_FALSE(b.haveWin());
}
