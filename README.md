**Advent Of Code 2024, in C++**

This repository is created to solve advent 2024 coding puzzle https://adventofcode.com. Please read the puzzle description for each day. This puzzle consists of two parts, on solving the first part unlocks the second. 
The main purpose of this project is to provide a structure that is ready to go with upcoming puzzle with only minimal adjustments depending on the puzzle itself. This project depends on CMake and googletest.

**CMake and gtest setup**

If you don't have CMake installed already, you can download it for free from https://cmake.org/.
Clone and install the googletest as follows:

 ```
git clone https://github.com/google/googletest.git -b v1.15.2
cd googletest        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build
cmake ..             # Generate native build scripts for GoogleTest.
```
**File structure**

The folders break down as follows:

```
project
├── CMakeLists.txt
├── main.cpp
│
├── include
│   └── Day1.hpp
│   └── Day2.hpp
│
├── src
│ └── Day1.cpp
│ └── Day2.cpp
│
├── resource
│   └── day1.txt
│   └── day2.txt
│ 
└── tests
    ├── CMakeLists.txt
    ├── Day1.cpp
    │── Day2.cpp
    │
    └── test_resource
        └── test_day1.txt
    
```


**Download and build**

Clone the repository:
```
git clone git@github.com:bhavnar/AoC2024.git
cd AoC2024
mkdir build
cd build
cmake ..
make
```

**How to run**

After building the project do the following to run the code

e.g. to get result for day 2, part 1 after running following exicutable 

To run main program: 
```
./AoC2024 --day=2 --part=1

```
To run all tests: 

```
cd tests
./AoC2024Tests 

```
