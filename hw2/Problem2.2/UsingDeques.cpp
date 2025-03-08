/*
CH-231-A
hw2
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<float> A;
    float read;

    while (true)
    {
        cin >> read;
        
        if (read == 0) break;
        if (read <= 0)
        {
            A.push_front(read);
        } else if (read > 0) {
            A.push_back(read);
        }
    }
    cout << endl;

    auto it = A.begin() + A.size() / 2;

    A.insert(it, 0);

    for (auto v: A)
    {
        cout << v << ";";
    }

    return 0;
    
}