#include <memory>
#include "ComputeAoC.hpp"
#include "Day1.hpp"
#include "Day2.hpp"

class FactoryDay {
public:
    static std::unique_ptr<ComputeAoC> computeDayNum(const int & day_num) {
        if (day_num == 1) {
            return std::make_unique<Day1>();
        } else if (day_num == 2) {
            return std::make_unique<Day2>();
        } else {
            return nullptr;
        }
    }
};
