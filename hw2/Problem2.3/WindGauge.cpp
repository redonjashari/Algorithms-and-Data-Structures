/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include "WindGauge.h"
#include <iostream>

WindGauge::WindGauge(int period) : period(period) {}

void WindGauge::currentWindSpeed(int speed) {
    history.push_back(speed);
    if (history.size() > period) {
        history.pop_front();
    }
}

int WindGauge::highest() const {
    if (history.empty()) {
        return 0;
    }
    int max = history.front();
    for (int speed : history) {
        if (speed > max) {
            max = speed;
        }
    }
    return max;
}

int WindGauge::lowest() const {
    if (history.empty()) {
        return 0;
    }
    int min = history.front();
    for (int speed : history) {
        if (speed < min) {
            min = speed;
        }
    }
    return min;
}

int WindGauge::average() const {
    if (history.empty()) {
        return 0;
    }
    int sum = 0;
    for (int speed : history) {
        sum += speed;
    }
    return sum / history.size();
}

void WindGauge::dump() const {
    std::cout << "Lowest: " << lowest() << std::endl;
    std::cout << "Highest: " << highest() << std::endl;
    std::cout << "Average: " << average() << std::endl;
}