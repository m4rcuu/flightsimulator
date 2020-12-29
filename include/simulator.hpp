#pragma once

#include "airport.hpp"
#include "plane.hpp"
#include "tower.hpp"
#include <memory>
#include <vector>
#include <time.h>
#include <stdlib.h>

class Simulator
{
private:
    std::shared_ptr<Tower> tower;
    std::shared_ptr<Airport> airport;

    std::vector<Plane> planes;

    void init(int _numberOfPlanes);

public:
    Simulator(int _numberOfPlanes);
    void update();
    void end();
};