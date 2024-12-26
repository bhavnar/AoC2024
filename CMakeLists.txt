cmake_minimum_required(VERSION 3.10)

#project(AoC2024)

#C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable Testing
enable_testing()

# Link GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

#Add the executable
add_executable(AoC2024 ${SOURCES}
main.cpp
)
target_include_directories(AoC2024 PRIVATE src include)

# Add Tests
include_directories(include)

add_subdirectory(tests)
