#include <iostream>
#include <string>
#include "include/Day1.hpp"
#include "include/FactoryDay.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] <<" --day=<number>" <<" --part=<number>\n";
    }
    std::string arg(argv[2]), days = argv[1], parts = argv[2];

    if (days.rfind("--day=", 0) != 0) {
        std::cerr << "Invalid argument. Use --day=<number>\n";
    }
    if (parts.rfind("--part=", 0) != 0) {
        std::cerr << "Invalid argument. Use --part=<number>\n";
    }

    int day = std::stoi(days.substr(6));
    int part = std::stoi(parts.substr(7));
    
    if (day == 1 || day == 2) {
        auto result = FactoryDay::computeDayNum(day);
        if (result) {
            result->ComputeDay(part);
        }
    } else {
            std::cerr << "Day " << day << " is not implemented yet";
    }

return 0;
}
