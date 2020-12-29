#pragma once

#include "tower.hpp"
#include "airport.hpp"
#include <memory>

class Plane
{
private:
    int distance; //how far from the airport (X-axis)
    int lane;     //0 is the Lane enabling a proper landing (Y-axis)
    int number;   //number of plane
    int movements;
    int operations;
    bool landed;

    std::shared_ptr<Tower> tower;
    std::shared_ptr<Airport> airport;

    static int numberOfPlanes;

    void move();
    void sendPosition();
    bool isLanded();
    void landPlane();

public:
    Plane(int _distance, int _lane, std::shared_ptr<Tower> _tower, std::shared_ptr<Airport> _airport);

    void update();
    int getMovements();
    int getOperations();
    bool getLanded();

    static int getNumberOfPlanes();
};