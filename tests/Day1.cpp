#include "../include/Day1.hpp"
#include "../src/Day1.cpp"
#include <gtest/gtest.h>

class AoCTests : public ::testing::Test {
protected:
    Day1 day1;
};

TEST_F(AoCTests, FindDistance) {
    day1.parseInput("../tests/test_resource/test_day1.txt");
    int distance = day1.totalDistance();
    EXPECT_EQ(distance, 11);
}

TEST_F(AoCTests, calculateSimilarity) {
    day1.parseInput("../tests/test_resource/test_day1.txt");
    int similarity = day1.calcSimilarity();
    EXPECT_EQ(similarity, 31);
}

TEST_F(AoCTests, readLine) {
    std::string str1 = "2 5 ";
    EXPECT_TRUE(day1.isLineValid(str1));
    
    std::string str2 = "2 $ ";
    EXPECT_FALSE(day1.isLineValid(str2));
   
}
