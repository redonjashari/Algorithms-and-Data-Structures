/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include <deque>

class WindGauge {
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump() const;
private:
    std::deque<int> history;
    long unsigned int period;
};