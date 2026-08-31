#include <iostream>

using namespace std;

class B;

class A {
private:
    int a = 0;

public:
    A(int a) {
        this->a = a;
    }

    friend int max(A a, B b);
};

class B {
private:
    int b = 0;

public:
    B(int b) {
        this->b = b;
    }

    friend int max(A a, B b);
};

int max(A a, B b) {
    return (a.a >= b.b ? a.a : b.b);
}

int main() {
    A numA(10);
    B numB(15);

    cout << "The greater number is: " << max(numA, numB) << endl;
}