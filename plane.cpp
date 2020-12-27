#include "include/plane.hpp"
#include <utility>

int Plane::numberOfPlanes = 0;

Plane::Plane(int _distance, int _lane, std::shared_ptr<Tower> _tower, std::shared_ptr<Airport> _airport) : distance(std::move(_distance)),
                                                                                                           lane(std::move(_lane)),
                                                                                                           tower(std::move(_tower)),
                                                                                                           airport(std::move(_airport)),
                                                                                                           number(numberOfPlanes),
                                                                                                           movements(0),
                                                                                                           operations(0),
                                                                                                           landed(false)
{
    ++numberOfPlanes;
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
            ++movements;
            distance -= 1;
        }
    }
    else
    {
        if (tower->checkCollisionLane(number))
        {
            ++movements;
            lane -= 1;
        }
    }
    ++operations;
}

void Plane::sendPosition()
{
    tower->setPlanes(number, distance, lane);
}

bool Plane::isLanded()
{
    return distance == 0 && lane == 0;
}

void Plane::landPlane()
{
    airport->setLandedPlanes(number, movements, operations);
    landed = true;
}

void Plane::update()
{
    if (!this->isLanded())
    {
        this->move();
        this->sendPosition();
    }
    else
    {
        if (!landed)
        {
            this->landPlane();
        }
    }
}

int Plane::getMovements()
{
    return movements;
}

int Plane::getOperations()
{
    return operations;
}

int Plane::getNumberOfPlanes()
{
    return numberOfPlanes;
}

bool Plane::getLanded()
{
    return landed;
}