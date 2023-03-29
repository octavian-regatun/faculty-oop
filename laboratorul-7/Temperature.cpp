#include <iostream>
#include "Temperature.h"

int operator "" _Fahrenheit(const char *x) {
    int fahrenheit = std::stoi(x);

    int celsius = (fahrenheit - 32) * (5.0 / 9);

    return celsius;
}

int operator "" _Kelvin(const char *x) {
    return std::stoi(x) - 273.15;
}