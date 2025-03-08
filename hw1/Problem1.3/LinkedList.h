/*
CH-231-A
hw1
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>

using namespace std;

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T value) : data(value), prev(), next() {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    
    LinkedList() : head(), tail(), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addFront(T value) {
        Node* newNode = new Node(value);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            head = tail = newNode;
        }
        size++;
    }

    void addBack(T value) {
        Node* newNode = new Node(value);
        if (tail) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        size++;
    }

    T getFront() const {
        if (head)
        {
            return head->data;
        } else {
            throw out_of_range("The list is empty");
        }
        
    }

    T getBack() const {
        if (tail)
        {
            return tail->data;
        } else {
            throw out_of_range("The list is empty");
        }
    }

    bool removeFront(T& out) {
        if (!head) return false;

        out = head->data;
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        size--;

        return true;
    }

    bool removeBack(T& out) {
        if (!tail) return false;

        out = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    int getSize() const {
        return size;
    }
};
