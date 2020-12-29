#include "include/simulator.hpp"
#include <iostream>
#include <memory>

int main()
{
    int numberOfPlanes = 0;

    std::cout<<"How many planes to create: ";
    std::cin>>numberOfPlanes;
    std::cout<<std::endl;

    Simulator simulator(numberOfPlanes);
    simulator.update();
    simulator.end();

    return 0;
}