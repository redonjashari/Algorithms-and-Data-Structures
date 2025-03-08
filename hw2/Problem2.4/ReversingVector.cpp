/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> intVector;

    for (int i = 1; i <= 30; i++)
    {
        intVector.push_back(i);
    }
    
    intVector.push_back(5);

    reverse(intVector.begin(), intVector.end());

    for (auto it = intVector.begin(); it != intVector.end(); ++it)
    {
        if (it != intVector.begin())
        {
            cout << ""; 
        }
        cout << *it;
    }

    cout << endl;

    replace(intVector.begin(), intVector.end(), 5, 129);

    for (auto v: intVector)
    {
        cout << v;
    }
    
    return 0;
}