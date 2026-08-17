#include <iostream>
using namespace std;

class Complex {
    public:
    int real = 0, complex = 0;

    Complex() {}

    Complex(int r) {
        real = r;
        complex = r;
    }

    Complex(int r, int i) {
        real = r;
        complex = i;
    }

    Complex(Complex &c) {
        real = c.real;
        complex = c.complex;
    }

    static Complex sum(Complex x, Complex y) {
        Complex result;
        result.real = x.real + y.real;
        result.complex = x.complex + y.complex;
        return result;
    }

    string str() {
        return to_string(real) + " + " + to_string(complex) + "i";
    }
};

int main() {
    Complex x(2), y(1, 2), z = Complex::sum(x, y);

    cout << "x: " << x.str() << ", y: " << y.str() << ", z: " << z.str();
}