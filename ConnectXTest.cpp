/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// The bug is in this test case as the width is negative and so the test case fails.
// The output returned shows it to be valid.
// But the expected output is -1.

TEST(ConnectXTest, inBoundsWidth)
{
	ConnectX connect(5,5,3);
	connect.placePiece(3);

	ASSERT_EQ(-1, connect.at(-4,4));
}

TEST(ConnectXTest, inBoundsHeight)
{
	ConnectX connect(5,5,3);

	ASSERT_EQ(-1, connect.at(4,-4));
}

TEST(ConnectXTest, inBoundsWidthHeight)
{
	ConnectX connect(5,5,3);

	ASSERT_EQ(-1, connect.at(-4,-4));
}

TEST(ConnectXTest, inBoundsWidthHeightPositive)
{
	ConnectX connect(5,5,3);

	ASSERT_EQ(0, connect.at(4,4));
}

// The bug is in this test case as the width is out of bounds and so the test case fails.
// The output returned shows it to be valid.
// But the expected output is -1.

TEST(ConnectXTest, outBoundsWidth)
{
	ConnectX connect(5,5,3);
	
	ASSERT_EQ(-1, connect.at(7,4));
}

TEST(ConnectXTest, outBoundsHeight)
{
	ConnectX connect(5,5,3);
	
	ASSERT_EQ(-1, connect.at(3,7));
}

TEST(ConnectXTest, outBoundsWidthHeight)
{
	ConnectX connect(5,5,3);
	
	ASSERT_EQ(-1, connect.at(7,7));
}

// Constructor with negative width 
TEST(ConnectXTest, widthTurn)
{
	ConnectX connect(-5,5,3);
	
	ASSERT_EQ(2, connect.whoseTurn());
}

// Constructor with negative height 
TEST(ConnectXTest, heightTurn)
{
	ConnectX connect(5,-5,3);
	
	ASSERT_EQ(2, connect.whoseTurn());
}

// Constructor with negative x
TEST(ConnectXTest, xTurn)
{
	ConnectX connect(5,5,-3);
	
	ASSERT_EQ(2, connect.whoseTurn());
}

TEST(ConnectXTest, outOfBoundsWidth)
{
	ConnectX connect(0,5,3);
	
	ASSERT_EQ(2, connect.whoseTurn());
}

TEST(ConnectXTest, outOfBoundsHeight)
{
	ConnectX connect(5,0,3);
	
	ASSERT_EQ(2, connect.whoseTurn());
}

TEST(ConnectXTest, outOfBoundsX)
{
	ConnectX connect(5,5,0);	
	ASSERT_EQ(2, connect.whoseTurn());
}

TEST(ConnectXTest, checkPiece)
{
	ConnectX connect(1,1,3);
	connect.placePiece(1);
	ASSERT_EQ(1, connect.whoseTurn());
}

TEST(ConnectXTest, checkPiecePlaceAndBoard)
{
	ConnectX connect(5,5,3);
	connect.placePiece(3);
	connect.placePiece(4);
	connect.showBoard();
	ASSERT_EQ(2, connect.whoseTurn());
}
