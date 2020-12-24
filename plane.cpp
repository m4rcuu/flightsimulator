#include "include/plane.hpp"
#include <utility>
#include <iostream>

int Plane::numberOfPlanes = 0;

Plane::Plane(int _distance, int _lane, std::shared_ptr<Tower> _tower) : distance(std::move(_distance)),
                                                                        lane(std::move(_lane)),
                                                                        tower(std::move(_tower))
{
    number = numberOfPlanes;
    numberOfPlanes++;
    this->sendPosition();
}

Plane::~Plane()
{
    numberOfPlanes--;
}

void Plane::move()
{
    if (distance > lane)
    {
        if (tower->checkCollisionDistance(number))
        {
            distance -= 1;
        }
    }
    else
    {
        if (tower->checkCollisionLane(number))
        {
            lane -= 1;
        }
    }
}

void Plane::sendPosition()
{
    tower->setPlanes(number, distance, lane);
}

bool Plane::isLanded()
{
    return distance == 0 && lane == 0;
}

void Plane::update()
{
    if (!this->isLanded())
    {
        this->move();
        this->sendPosition();
    }
}

int Plane::getNumberOfPlanes()
{
    return numberOfPlanes;
}