/*
 * test_Goban.cpp
 *
 *  Created on: 8 déc. 2016
 *      Author: user
 */


# include "gtest/gtest.h"
#include "Goban.h"
#include <iostream>
using namespace std ;

TEST(GobanClass,PoserPierre){
	Goban machin = Goban();
	machin.PoserPierre(2,2);
	machin.SetJoueur();
	EXPECT_EQ(true,machin.PoserPierre(2,3));
	EXPECT_EQ(false,machin.PoserPierre(2,2));
}
/*
TEST(IntegerFunctionTest, negative) {
        EXPECT_EQ(1, factorial(-5));
        EXPECT_EQ(1, factorial(-1));
        EXPECT_GT(factorial(-10), 0);
}

TEST(IntegerFunctionTest, DISABLED_zero) {
         EXPECT_EQ(1, factorial(0));
}

TEST(IntegerFunctionTest, postive) {
         EXPECT_EQ(1, factorial(1));
         EXPECT_EQ(2, factorial(2));
         EXPECT_EQ(6, factorial(3));
         EXPECT_EQ(40320, factorial(8));
}
*/
