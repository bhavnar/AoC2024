#pragma once

//Defining an abstract base class ComputeAoC

class ComputeAoC {
public:
    virtual void ComputeDay(const int& part) = 0;
    virtual ~ComputeAoC() {} //virtual distructor
};
