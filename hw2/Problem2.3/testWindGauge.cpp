/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include "WindGauge.h"
#include <iostream>

int main() {
    WindGauge wg;

    // Add five wind speeds
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(12);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(15);
    std::cout << "After adding first 5 speeds:" << std::endl;
    wg.dump();

    // Add ten more measurements
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);
    std::cout << "After adding 10 more speeds:" << std::endl;
    wg.dump();

    return 0;
}