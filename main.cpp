#include "gtest/gtest.h"
#include "Goban.h"

TEST (Testtest, egalite) { 
    ASSERT_EQ (0.0, 1.0);
    ASSERT_EQ (-1, -1);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
