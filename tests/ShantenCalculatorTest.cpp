#include <gtest/gtest.h>
#include "../src/Hand.h"
#include "../src/Tile.h"
#include "../src/ShantenCalculator.h"

class ShantenCalculatorTest : public ::testing::Test {
protected:
    ShantenCalculator calculator;
};

TEST_F(ShantenCalculatorTest, CompleteSequence) {
    Hand hand;
    hand.addTile(Tile(Suit::Man, 1));
    hand.addTile(Tile(Suit::Man, 2));
    hand.addTile(Tile(Suit::Man, 3));
    int result = calculator.dfs_shanten(hand, 0, 0, 0);
    EXPECT_EQ(result, 6);
}

TEST_F(ShantenCalculatorTest, CompleteTriplet) {
    Hand hand;

    hand.addTile(Tile(Suit::Man, 1));
    hand.addTile(Tile(Suit::Man, 1));
    hand.addTile(Tile(Suit::Man, 1));

    int result = calculator.dfs_shanten(hand, 0, 0, 0);

    EXPECT_EQ(result, 6);
}

TEST_F(ShantenCalculatorTest, Pair) {
Hand hand;

hand.addTile(Tile(Suit::Man, 1));
hand.addTile(Tile(Suit::Man, 1));

int result = calculator.dfs_shanten(hand, 0, 0, 0);

EXPECT_EQ(result, 7);
}

TEST_F(ShantenCalculatorTest, ConsecutiveTaatsu) {
Hand hand;

hand.addTile(Tile(Suit::Man, 1));
hand.addTile(Tile(Suit::Man, 2));

int result = calculator.dfs_shanten(hand, 0, 0, 0);

EXPECT_EQ(result, 7);
}

TEST_F(ShantenCalculatorTest, GapTaatsu) {
Hand hand;

hand.addTile(Tile(Suit::Man, 1));
hand.addTile(Tile(Suit::Man, 3));

int result = calculator.dfs_shanten(hand, 0, 0, 0);

EXPECT_EQ(result, 7);
}

TEST_F(ShantenCalculatorTest, IsolatedTiles) {
Hand hand;

hand.addTile(Tile(Suit::Man, 1));

int result = calculator.dfs_shanten(hand, 0, 0, 0);

EXPECT_EQ(result, 8);
}