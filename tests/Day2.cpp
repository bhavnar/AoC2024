#include "../include/Day2.hpp"
#include "../src/Day2.cpp"
#include <gtest/gtest.h>

class AoCTests : public ::testing::Test {
protected:
    Day2 day2;
};

TEST_F(AoCTests, inRangeTest) {
    std::vector<int> v1{7, 6, 4, 2, 1};
    std::vector<int> v2{1, 2, 7, 8, 9};
    EXPECT_TRUE(day2.isInRange(v1));
    EXPECT_FALSE(day2.isInRange(v2));
}

TEST_F(AoCTests, inOrderTest) {
    std::vector<int> v1{8, 6, 4, 4, 1};
    std::vector<int> v2{1, 3, 6, 7, 9};
    EXPECT_FALSE(day2.isOrdered(v1));
    EXPECT_TRUE(day2.isOrdered(v2));
}

TEST_F(AoCTests, validLine) {
    std::string str1 = "2 5 7 9 8";
    EXPECT_TRUE(day2.isLineValid(str1));
    
    std::string str2 = "2 $ 9 18 30";
    EXPECT_FALSE(day2.isLineValid(str2));
   
}
