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

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
