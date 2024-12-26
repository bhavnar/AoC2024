#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>


#include "ComputeAoC.hpp"


class Day2: public ComputeAoC {
    
public:
    void ComputeDay(const int& part) override;
    std::vector<std::vector<int>> parseInput(const std::string& file_name);
    bool isLineValid(const std::string& line);
    bool isOrdered(const std::vector<int>& data);
    bool isInRange(const std::vector<int>& data);
    bool checkOnErase(std::vector<int>& data);

};
