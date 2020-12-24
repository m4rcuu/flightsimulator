#pragma once

#include <vector>
#include <memory>

class Tower
{
private:
    struct plane
    {
        int distance;
        int lane;

        plane(int _distance, int _lane) : distance(_distance),
                                          lane(_lane) {}
    };

    std::vector<plane> planes;

public:
    void setPlanes(int _number, int _distance, int _lane);
    bool checkCollisionDistance(int _number);
    bool checkCollisionLane(int _number);
    void printPlanes();
};