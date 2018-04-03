#include "app.h"
#include <array>
#include <gtest/gtest.h>


TEST(ProjectTest, FirstTest) {
    EXPECT_EQ(1, 1);
}

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


void function1() {
    std::cerr << "Bad thing happeded ";
    exit(1); //exit(0) is not a death
}

//! Convention : test case name should end with "DeathTest" 
//! DeathTests usually need to be run before other test
TEST(tut_DeathTest, simpletest) {
    int x = 99;

    EXPECT_DEATH(function1(), "Bad thing*");
        //Reasons of death 
        // 1.Program exited with non-zero code
        // 2.Program was killed by a signal
	EXPECT_EXIT(function1(), ::testing::ExitedWithCode(1) , "");

}

int main(int c, char* v[]) {
    testing::InitGoogleTest(&c, v);
    return RUN_ALL_TESTS();
}
