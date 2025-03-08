/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main() {
    list<int> intlistA;
    list<int> intlistB;
    int read;

    while (true)
    {
        cin >> read;
        if (read <= 0) break;
        intlistA.push_back(read);
        intlistB.push_front(read);
    }

    for (auto v : intlistA)
    {
        cout << v << " ";
    }
    cout << endl;
    
    ofstream myFile("listB.txt");
    for (auto v: intlistB)
    {
        myFile << v << " ";
    }
    myFile.close();
    
    cout << endl;

    if (!intlistA.empty())
    {
        intlistA.push_back(intlistA.front());
        intlistA.pop_front();
    }
    
    if (!intlistB.empty()) {
        intlistB.push_back(intlistB.front());
        intlistB.pop_front();
    }

    for (auto it = intlistA.begin(); it != intlistA.end(); ++it)
    {
        if (it != intlistA.begin())
        {
            cout << ",";
        }
        cout << *it;
    }
    cout << endl;
    
    for (auto it = intlistB.begin(); it != intlistB.end(); ++it)
    {
        if (it != intlistB.begin())
        {
            cout << ",";
        }
        cout << *it;
    }
    cout << endl;

    cout << endl;

    intlistA.merge(intlistB);

    intlistA.sort();
    for (auto v: intlistA)
    {
        cout << v << " ";
    }
    cout << endl;
    
    return 0;
}