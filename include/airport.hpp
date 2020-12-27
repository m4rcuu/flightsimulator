#pragma once

#include <vector>
#include <time.h>

class Airport
{
private:
    struct landedPlane
    {
        int number;
        int movements;
        int operations;
        double time;

        landedPlane(int _number, int _movements, int _operations) : number(_number),
                                                                    movements(_movements),
                                                                    operations(_operations),
                                                                    time(clock() / (CLOCKS_PER_SEC / 1000.0)) {}
    };

    std::vector<landedPlane> landedPlanes;

public:
    void setLandedPlanes(int _number, int _movements, int _operations);
    void printLandedPlanes();
};