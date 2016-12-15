#include "gtest/gtest.h"
using namespace std;

TEST(GobanClass,PoserPierre){
    EXPECT_EQ(true,1);
    EXPECT_EQ(false,0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
