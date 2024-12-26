cmake_minimum_required(VERSION 3.10)
project(AocTesting)


# Add Library for src/*.cpp
add_library(test_lib 
../src/Day1.cpp
../src/Day2.cpp 

../include/Day1.hpp 
../include/Day2.hpp 
)

# Enable testing
enable_testing()
add_executable(AoC2024Tests 
Day1.cpp
Day2.cpp
)


# Link GoogleTest
find_package(GTest REQUIRED)
target_link_libraries(AoC2024Tests GTest::GTest GTest::Main pthread)



#Register Tests
add_test(NAME AoCTests COMMAND AoC2024Tests)
