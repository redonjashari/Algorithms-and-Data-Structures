/*
CH-231-A
hw1
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> intStack;
    cout << "Pushing elements onto the integer Stack" << endl;
    for (int i = 1; i <= 3; i++)
    {
        cout << "Pushed " << i << (intStack.push(i) ? " Success " : " Failed")<<endl;
    }

    cout << "Number of entries in intStack: " << intStack.getNumEntries() << endl;
    cout << "Top Element: " << intStack.back() << endl;

    int poppedElement;
    cout << "Popping elements from intStack" << endl;
    while (intStack.pop(poppedElement))
    {
        cout << "Popped: " << poppedElement << endl;
    }

    Stack<double> doubleStack(5);
    doubleStack.push(1.2);
    doubleStack.push(1.8);
    doubleStack.push(1.6);
    doubleStack.push(2.2);
    cout << "Top element in doubleStack" << doubleStack.back() << endl;

    return 0;
}