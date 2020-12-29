#include "include/airport.hpp"
#include <iostream>

void Airport::setLandedPlanes(int _number, int _movements, int _operations)
{
    landedPlanes.emplace_back(landedPlane(_number, _movements, _operations));
}

void Airport::printLandedPlanes()
{
    int num = 0;
    for (auto i : landedPlanes)
    {
        std::cout << "it" << ++num << " n" << i.number << " m" << i.movements << " o" << i.operations << " t" << i.time << "ms" << std::endl;
    }
}

int Airport::getNumberOfLandedPlanes()
{
    return landedPlanes.size();
}