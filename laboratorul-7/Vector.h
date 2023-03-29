#pragma once

#include <iostream>

template<typename T>
class Vector {
private:
    T *vector;
    unsigned int size;
    unsigned int grow;
    int lastIndex;

    void resize(unsigned int newSize);

public:
    Vector();

    void push(T element);

    T pop();

    void remove(unsigned int index);

    void insert(T element, unsigned int index);

    void print();

    const T &get(unsigned int index);

    void set(unsigned int index, T element);

    int count();

    void sort(bool (*fn)(int, int));
};




