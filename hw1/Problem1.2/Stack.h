/*
CH-231-A
hw1
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>

using namespace std;

template <class T, int initialsize = 10>
class Stack {
    private:
        T* ptrArr;
        int size;
        int where;
    public:
            Stack() : size(10), where(-1) {
                ptrArr = new T[size];
            }

            Stack(int stackSize) : size(stackSize), where(-1) {
                ptrArr = new T[size];
            }

            Stack (const Stack& other) : size(other.size), where(other.where) {
                ptrArr = new T[size];
                for (int i = 0; i <= where; i++)
                {
                    ptrArr[i] = other.ptrArr[i];
                }
            }

            ~Stack() {
                delete [] ptrArr;
            }

            bool push(T element) {
                if (where >= size - 1)
                {
                    return false;
                }
                
                ptrArr[++where] = element;
                return true;
            }

            bool pop(T& out) {
                if (where < 0)
                {
                    return false;
                }
                
                out = ptrArr[where--];
                return true;
            } 

            T back() const {
                if (where < 0)
                {
                    throw range_error("Stack is empty");
                }
                return ptrArr[where];
            }

            int getNumEntries() const {
                return where + 1;
            }
};
