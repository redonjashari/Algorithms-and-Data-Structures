/*
CH-231-A
hw1
Redon Jashari
RJASHARI@constructor.university
*/

#include <iostream>
#include <vector>

using namespace std;

template <class T>
int array_search(const T arr[], int size, const T& target) {
    int i;
    for (i = 0; i < size; i++){
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

class Complex {
    private:
        double real, imag;
    public:
        Complex(double r, double i) : real(r), imag(i) {}

        bool operator==(const Complex& other) const {
            return (real == other.real) && (imag == other.imag);
        }

        friend ostream& operator<<(ostream& os, const Complex& c) {
            os << "(" << c.real << ", " << c.imag << ")";
            return os;
        } 
};


int main() {
    int intarr[] = {1, 2, 3, 4, 5, 6};
    cout << array_search<int>(intarr, 6, 3) << endl;

    double doublearr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    cout << array_search<double>(doublearr, 5, 4.2) << endl;

    Complex carr[] = {Complex(1,2), Complex(2,2), Complex(2,3)};
    Complex search(1, 2);
    int result = array_search(carr, 3, search);
    cout << result << endl;

    return 0;
}