#include "include/simulator.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<Tower> wieza = std::make_shared<Tower>();
    Plane samolot(2, 24, wieza);
    Plane samolot2(31, 3, wieza);
    Plane samolot3(100, 4, wieza);

    wieza->printPlanes();
    std::cout << "INICJALIZACJA\n" << std::endl;

    while (!(samolot.isLanded() && samolot2.isLanded() && samolot3.isLanded()))
    {
        samolot.update();
        samolot2.update();
        samolot3.update();

        wieza->printPlanes();

        std::cout << std::endl;
    }

    return 0;
}