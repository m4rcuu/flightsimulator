#pragma once

#include "tower.hpp"
#include <memory>

class Plane
{
private:
    int speed;    //higher value - slower plane
    int distance; //how far from the airport (X-axis)
    int lane;     //0 is the Lane enabling a proper landing (Y-axis)
    int number;   //number of plane

    std::shared_ptr<Tower> tower;

    static int numberOfPlanes;

    void move();
    void sendPosition();

public:
    Plane(int _distance, int _lane, std::shared_ptr<Tower> _tower);
    ~Plane();

    bool isLanded();
    void update();

    static int getNumberOfPlanes();
};