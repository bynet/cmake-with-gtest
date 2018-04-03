#include "app.h"
#include <array>
#include <gtest/gtest.h>


using namespace std;

constexpr
int pow(int base, int exp) noexcept {
    auto result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return base;
}

class Base {
public:
    string   name{ "nBase" };
//	virtual ~Base() = default;

};

struct ProjectTest:testing::Test {
    Base b;

};

TEST_F(ProjectTest, FirstTest) {
    Base base;
    EXPECT_EQ(1, 1);
}

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 0);
    EXPECT_TRUE(true);
}


//
//int main()
//{
//	cout << "Hello CMake." << endl;
//	array<int, pow(2, 2)> results;
//	cout << "size " << results.size() << endl;
//
//	Base base;
//	Base base2;
//	base2 = base;
//	
//	cout << base2.name.c_str() << endl;
//
//	cout << "press a key to exit" << endl;
//	cin.get();
//	return 0;
//	
//}
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

}

int main(int c, char* v[]) {
    testing::InitGoogleTest(&c, v);
    return RUN_ALL_TESTS();
}
