#include <memory>
#include "ComputeAoC.hpp"
#include "Day1.hpp"

class FactoryDay {
public:
    static std::unique_ptr<ComputeAoC> computeDayNum(const int & day_num) {
        if (day_num == 1) {
            return std::make_unique<Day1>();
        } else {
            return nullptr;
        }
    }
};
