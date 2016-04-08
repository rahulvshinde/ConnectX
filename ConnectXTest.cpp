/**
 * Unit Tests for ConnectX class
 * NAME : Rahul Shinde
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
	ConnectX connectx;
	connectx.showBoard();
	ASSERT_TRUE(true);
}
/*
This Test Case check whether the Game Board is empty or not.
*/
TEST(ConnectXTest, isEmpty)
{
	ConnectX connectx;
	int height = 6;
	int width = 7;
	Piece place;
	bool temp = false;
	for(int h = 0; h < height; h++)
	{
		for(int w = 0; w < width; w++)
		{
			place = connectx.at(w,h);
			if(place == 1)
			{
				temp = true;
				break;
			}
			else if( place == 2)
			{
				temp = true;
				break;
			}
		}
		if (temp == true)
		{
			break;
		}
	}
	ASSERT_FALSE(temp);
}

/*
This Test Case checks if player place piece at
valid location then it should change the player
*/
TEST(ConnectXTest, isMyTurn)
{
	ConnectX connectx;
	Piece myturn, yourturn;
	connectx.placePiece(3);
	myturn = connectx.whoseTurn();
	connectx.placePiece(4);
	yourturn = connectx.whoseTurn();
	ASSERT_TRUE(myturn != yourturn);
}

/*
BUG #1 : This Test Case is used to check for
invalid width but it fails because the
inBounds() contains a bug.
*/
TEST(ConnectXTest, isInvalidWidth)
{
	ConnectX connectx;
	int outOfBoard;
	connectx.placePiece(100);
	bool temp = false;
	outOfBoard = connectx.at(100,1);
	if(outOfBoard == -1)
		temp = true;
	ASSERT_FALSE(temp);
}

/*
BUG #1 : This Test Case is used to check for
negative height.
*/
TEST(ConnectXTest, isInvalidHeight)
{
	ConnectX connectx;
	int outOfBoard;
	connectx.placePiece(3);
	bool temp = false;
	outOfBoard = connectx.at(3,100);
	if(outOfBoard == -1)
		temp = true;
	ASSERT_TRUE(temp);
}

/*
BUG #1 : This Test Case is used to check for
invalid width but it fails because the
inBounds() contains a bug.
*/
TEST(ConnectXTest, isNegativeWidth){
	ConnectX connectx;
	int negative;
	bool temp = false;
	connectx.placePiece(-100);
	negative = connectx.at(-100,1);
	if (negative == -1) {
		temp = true;
	}
	ASSERT_FALSE(temp);
}

/*
BUG #1 : This Test Case is used to check for
negative height.
*/
TEST(ConnectXTest, isNegativeHeight)
{
	ConnectX connectx;
	int negative;
	bool temp = false;
	connectx.placePiece(3);
	negative = connectx.at(3,-10);
	if (negative == -1) {
		temp = true;
	}
	ASSERT_TRUE(temp);
}

/*
BUG #2 : This Test Case is used to check
whether the players toggling correctly or
not but it fails because if player tries
to place piece at invalid place, it still
switches the player.
*/
TEST(ConnectXTest, isNotSwitch)
{
	ConnectX connectx;
	Piece myturn, yourturn;
	connectx.placePiece(3);
	myturn = connectx.whoseTurn();
	connectx.placePiece(40);
	connectx.placePiece(4);
	yourturn = connectx.whoseTurn();
	ASSERT_FALSE(myturn != yourturn);
}
