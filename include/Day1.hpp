#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "ComputeAoC.hpp"

class Day1: public ComputeAoC {
    
public:
    void ComputeDay(const int& part) override;
    void parseInput(const std::string& file_name);
    int totalDistance();
    int calcSimilarity();
    bool isLineValid(const std::string& line);
    
private:
    std::vector<int> m_left, m_right;
};
