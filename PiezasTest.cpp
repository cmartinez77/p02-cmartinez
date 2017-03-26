/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/*Constructor test*/
TEST(PiezasTest, initialTurn)
{
  Piezas game;
  Piece expected=Blank;
	ASSERT_EQ(expected, game.pieceAt(0,0));
}


/*Get Piece tests*/
TEST(PiezasTest, getPieceLowerBoundBorder1)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.pieceAt(-1,-1));
}

TEST(PiezasTest, getPieceLowerBoundBorder2)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.pieceAt(0,-1));
}

TEST(PiezasTest, getPieceLowerBoundBorder3)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.pieceAt(-1,0));
}

TEST(PiezasTest, getPieceUpperBoundBorder1)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.pieceAt(3,4));
}

TEST(PiezasTest, getPieceUpperBoundBorder2)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.pieceAt(0,4));
}

TEST(PiezasTest, getPieceUpperBoundBorder3)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.pieceAt(3,0));
}

TEST(PiezasTest, getPieceCorrect)
{
  Piezas game;
  Piece expected=Blank;
	ASSERT_EQ(expected, game.pieceAt(0,0));
}

/*Sanity Check*/
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
