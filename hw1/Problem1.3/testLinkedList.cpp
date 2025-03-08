/*
CH-231-A
hw1
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> intLinkList;

    cout << "Adding elements to the front of the linked list" << endl;
    intLinkList.addFront(1);
    intLinkList.addFront(10);
    intLinkList.addFront(100);

    cout << "Adding elements to the back of the linked list" << endl;
    intLinkList.addBack(2);
    intLinkList.addBack(20);

    cout << "First element of linked list: " << intLinkList.getFront() << endl;
    cout << "Last element of linked list: " << intLinkList.getFront() << endl;
    cout << "Size of linked list: " << intLinkList.getSize() << endl;


    int removeElem;

    cout << "Removing element from the front of linked list" <<  endl;
    if (intLinkList.removeFront(removeElem))
    {
        cout << "Removed: " << removeElem << endl;
    }

    cout << "Removing element from the back of linked list" <<  endl;
    if (intLinkList.removeBack(removeElem))
    {
        cout << "Removed: " << removeElem << endl;
    }
    
    cout << "Size of the list: " << intLinkList.getSize() << endl;

    return 0;
}