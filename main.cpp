#include "include/simulator.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<Tower> wieza = std::make_shared<Tower>();
    std::shared_ptr<Airport> lotnisko = std::make_shared<Airport>();
    Plane samolot(200000, 8003330, wieza, lotnisko);
    Plane samolot2(311100, 30200, wieza, lotnisko);
    Plane samolot3(100330, 412000, wieza, lotnisko);

    std::cout << Plane::getNumberOfPlanes() << std::endl;
    std::cout << "INICJALIZACJA" << std::endl;
    wieza->printPlanes();

    while (!(samolot.getLanded() & samolot2.getLanded() & samolot3.getLanded()))
    {
        samolot.update();
        samolot2.update();
        samolot3.update();
    }

    lotnisko->printLandedPlanes();

    return 0;
}