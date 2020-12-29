#include "include/simulator.hpp"
#include <iostream>

Simulator::Simulator(int _numberOfPlanes)
{
    srand(time(NULL));
    tower = std::make_shared<Tower>();
    airport = std::make_shared<Airport>();
    this->init(_numberOfPlanes);
}

void Simulator::init(int _numberOfPlanes)
{
    for (auto i = 0; i < _numberOfPlanes; ++i)
    {
        planes.emplace_back(Plane(rand() % 10000 + 1, rand() % 10000 + 1, tower, airport));
    }
    std::cout << "Number of planes: " << Plane::getNumberOfPlanes() << "\n"
              << std::endl;

    tower->printPlanes();
    std::cout << "\nInitialization complete!\n"
              << std::endl;
}

void Simulator::update()
{
    while (Plane::getNumberOfPlanes() != airport->getNumberOfLandedPlanes())
    {
        for (auto &p : planes)
        {
            p.update();
        }
    }
}

void Simulator::end()
{
    airport->printLandedPlanes();
}