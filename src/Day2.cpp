#include "../include/Day2.hpp"
#include <vector>
#include <string>

std::vector<std::vector<int>> Day2::parseInput(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "File for day 2 cannot be opened!" << std::endl;
        return {}; //return empty vector in place of void
    }
    
    std::vector<std::vector<int>> input;
    std::string line;
    
    while (std::getline(file, line)) {
    
        if (line.empty()) {
            continue; // skip empty line
        }
        std::vector<int> row;
        std::istringstream row_stream(line);
        if (!(isLineValid(line))) {
            std::cerr << "Error in parsing line: " << line << std::endl;
            continue;
        }
        int value;
        while(row_stream >> value) {
            row.push_back(value);
        }
        
        // Checking parsing error
        if (!row_stream.eof() && row_stream.fail()) {
            std::cerr << "Error in parsing line: " << line << std::endl;
            continue;
        }
        
        input.push_back(row);
    }
    file.close();
    return input;
}

bool Day2::isLineValid(const std::string& line) {
    std::stringstream s(line);
    std::string value;
    if (!(s >> value)) {
        return false;
    }
    while (s >> value) {
        try {
            size_t pos;
            std::stoi(value, &pos);
            if (pos < value.length()) {
                // non integral value
                return false;
            }
        } catch (std::invalid_argument&) {
            // Not an integer, failed conversion
            return false;
        }
    }
    return true;
}

bool Day2::checkOnErase(std::vector<int>& data) {
    if (data.size() <= 1) {
        return true;
    }
    
    for (size_t i = 0; i < data.size(); i++)
    {
        int removed = data[i];
        // Removing the ith element
        data.erase(data.begin() + i);
        bool ok = isOrdered(data) && isInRange(data);
        if (ok) {
            return true;
        }
        data.insert(data.begin() + i, removed);
    }
    return false;
}


bool Day2::isOrdered(const std::vector<int>& data) {
    for (size_t c = 1; c < data.size() - 1; ++c) {
        int diff = data[c] - data[c-1];
        if (diff == 0) {
            return false;
        }
        int next = data[c+1] - data[c];
        int pre_order = diff > 0 ? 1 : -1 ;
        int next_order = next > 0 ? 1 : -1;
        if (pre_order != next_order) {
            return false;
        }
    }
    
    return true;
}

bool Day2::isInRange(const std::vector<int>& data) {
    
    if (data.size() < 2) {
        return true;
    }
    for (size_t c = 1; c < data.size(); ++c) {
        int diff = data[c] - data[c - 1];
        if (std::abs(diff) > 3 || diff == 0) {
            return false;
        }
    }
    return true;
}


void Day2::ComputeDay(const int& part) {
    //First and second part
    std::vector<std::vector<int>> input = parseInput("../resource/day2.txt");
    
    int safe_count = 0;
    
    for (auto col : input) {
        bool safe = false;
        std::vector<int>& column = col; //reference to avoid copy
        
        bool order = isOrdered(column);
        bool in_range = isInRange(column);
        safe = (order && in_range);
        
        if (!safe && part == 2) {
            safe = checkOnErase(column);
        }
        
        if (safe) {
            safe_count++;
        }
    }
    std::cout << "Number of safe reports are: " << safe_count << "\n";
    
}

