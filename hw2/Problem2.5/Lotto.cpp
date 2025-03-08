/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    set<int> drawnNumbers;

    while (drawnNumbers.size() < 6)
    {
        int number = rand() % 49 + 1;
        drawnNumbers.insert(number);
    }

    cout << "The six numbers drawn are: " << endl;

    for (auto v: drawnNumbers)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
