#include <iostream>
#include "Vector.cpp"
#include "Temperature.cpp"

void ex1() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;


    std::cout << a << std::endl << b;
}

void ex2() {
    Vector<int> vectorDeInt;

    vectorDeInt.push(5);
    vectorDeInt.push(1);
    vectorDeInt.push(6);
    vectorDeInt.push(2);
    vectorDeInt.push(5);
    vectorDeInt.push(3);
    vectorDeInt.push(4);


    vectorDeInt.sort([](int a, int b) {
        if (a > b) return true;
        return false;
    });

    vectorDeInt.print();
}

int main() {
    ex2();

    return 0;
}

