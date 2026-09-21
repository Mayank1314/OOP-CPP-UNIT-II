



#include <iostream>

using namespace std;


class Complex {

private:

    double real;

    double imag;

public:

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {

        return Complex(real + other.real, imag + other.imag);

    }

    void display() const {

        cout << real << " + " << imag << "i" << endl;

    }

};


int main() {

    Complex a(3, 4);

    Complex b(2, 5);

    Complex result = a + b;

    result.display();

}

