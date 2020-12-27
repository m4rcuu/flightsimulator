#include "include/tower.hpp"
#include <iostream>

void Tower::setPlanes(int _number, int _distance, int _lane)
{
    if (planes.size() < _number + 1)
    {
        planes.emplace_back(plane(_distance, _lane));
    }
    else
    {
        planes[_number] = plane(_distance, _lane);
    }
}

bool Tower::checkCollisionDistance(int _number)
{
    for (auto i = 0; i < planes.size(); ++i)
    {
        if (i == _number)
        {
            continue;
        }
        if (planes[_number].distance - 1 == planes[i].distance && planes[_number].lane == planes[i].lane && planes[i].distance != 0)
        {
            return false;
        }
    }
    return true;
}

bool Tower::checkCollisionLane(int _number)
{
    for (auto i = 0; i < planes.size(); ++i)
    {
        if (i == _number)
        {
            continue;
        }
        if (planes[_number].lane - 1 == planes[i].lane && planes[_number].distance == planes[i].distance && planes[i].lane != 0)
        {
            return false;
        }
    }
    return true;
}

void Tower::printPlanes()
{
    auto number = 0;

    for (auto i : planes)
    {
        std::cout << "n" << ++number << " d" << i.distance << " l" << i.lane << std::endl;
    }
}