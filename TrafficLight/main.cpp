#include <iostream>
#include <chrono>
#include <thread>

#include "TrafficLight.h"

int main()
{
    TrafficLight myLight;

    for(;;)
    {
        std::cout << myLight.getColour() << "\b●" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(myLight.sleepAfterTime()));
        myLight.transition();
    }
}
