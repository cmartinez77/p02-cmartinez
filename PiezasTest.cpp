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
TEST(PiezasTest, initialization)
{
  Piezas game;
  Piece expected=Blank;
	ASSERT_EQ(expected, game.pieceAt(0,0));
}

/*Reset test*/
TEST(PiezasTest, reset1)
{
  Piezas game;
  Piece expected=Blank;
  game.dropPiece(0);
  game.reset();
	ASSERT_EQ(expected, game.pieceAt(0,0));
}

TEST(PiezasTest, reset2)
{
  Piezas game;
  Piece expected=Blank;
  game.dropPiece(0);
  game.dropPiece(0);
  game.reset();
	ASSERT_EQ(expected, game.pieceAt(1,0));
}

/*Get Piece tests*/
TEST(PiezasTest, validFirstTurn1)
{
  Piezas game;
  Piece expected=X;
  game.dropPiece(0);
	ASSERT_EQ(expected, game.pieceAt(0,0));
}

TEST(PiezasTest, validFirstTurn2)
{
  Piezas game;
  Piece expected=X;
  game.dropPiece(1);
	ASSERT_EQ(expected, game.pieceAt(0,1));
}

TEST(PiezasTest, invalidFirstTurn1)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.dropPiece(-1));
}

TEST(PiezasTest, invalidFirstTurn2)
{
  Piezas game;
  Piece expected=Invalid;
	ASSERT_EQ(expected, game.dropPiece(4));
}

TEST(PiezasTest, validSecondTurn1)
{
  Piezas game;
  Piece expected=O;
  game.dropPiece(0);
  game.dropPiece(0);
	ASSERT_EQ(expected, game.pieceAt(1,0));
}

TEST(PiezasTest, fullColumn)
{
  Piezas game;
  Piece expected=Blank;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
	ASSERT_EQ(expected, game.dropPiece(0));
}

TEST(PiezasTest, firstTurnPieceReturn)
{
  Piezas game;
  Piece expected=X;
	ASSERT_EQ(expected, game.dropPiece(0));
}

TEST(PiezasTest, secondTurnPieceReturn)
{
  Piezas game;
  Piece expected=O;
  game.dropPiece(0);
	ASSERT_EQ(expected, game.dropPiece(0));
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

/*Win Check*/
TEST(PiezasTest, xRowWin)
{
  Piezas game;
  Piece expected=X;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(0);
  game.dropPiece(3);
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(1);
  game.dropPiece(3);
	ASSERT_EQ(expected, game.gameState());
}
TEST(PiezasTest, oRowWin)
{
  Piezas game;
  Piece expected=O;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(2);
  
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(3);
  game.dropPiece(1);
  game.dropPiece(2);
	ASSERT_EQ(expected, game.gameState());
}

TEST(PiezasTest, RowTie)
{
  Piezas game;
  Piece expected=Blank;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(3);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(2);
  game.dropPiece(2);
	ASSERT_EQ(expected, game.gameState());
}

TEST(PiezasTest, xColWin)
{
  Piezas game;
  Piece expected=X;

  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(0);
  game.dropPiece(3);
  
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(2);
  
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(2);

	ASSERT_EQ(expected, game.gameState());
}

TEST(PiezasTest, oColWin)
{
  Piezas game;
  Piece expected=O;

  game.dropPiece(1);
  game.dropPiece(0);
  game.dropPiece(3);
  game.dropPiece(2);
  
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(2);
  game.dropPiece(1);
  
  game.dropPiece(1);
  game.dropPiece(3);
  game.dropPiece(2);
  game.dropPiece(0);

	ASSERT_EQ(expected, game.gameState());
}

TEST(PiezasTest, ColTie)
{
  Piezas game;
  Piece expected=Blank;

  game.dropPiece(0);
  game.dropPiece(1);
  game.dropPiece(0);
  game.dropPiece(3);
  
  game.dropPiece(2);
  game.dropPiece(3);
  game.dropPiece(0);
  game.dropPiece(2);
  
  game.dropPiece(1);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);

	ASSERT_EQ(expected, game.gameState());
}

TEST(PiezasTest, unfinished)
{
  Piezas game;
  Piece expected=Invalid;
  game.dropPiece(0);
	ASSERT_EQ(expected, game.gameState());
}

/*Sanity Check*/
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
