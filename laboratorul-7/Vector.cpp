#include "Vector.h"
#include "algorithm"

template<typename T>
Vector<T>::Vector() {
    vector = new T[size];
    size = 10;
    grow = 10;
    lastIndex = -1;
}

template<typename T>
void Vector<T>::print() {
    for (int i = 0; i <= lastIndex; i++) std::cout << vector[i] << " ";
    std::cout << std::endl;
}

template<typename T>
void Vector<T>::resize(unsigned int newSize) {
    if (size == newSize) return;
    if (newSize <= lastIndex) lastIndex = newSize - 1;

    T *vectorNou = new T[newSize];
    for (int i = 0; i <= lastIndex; i++)
        vectorNou[i] = vector[i];
    delete[] vector;
    vector = vectorNou;
    size = newSize;
}

template<typename T>
void Vector<T>::push(T element) {
    if (lastIndex == size)
        resize(size + grow);

    vector[++lastIndex] = element;
}


template<typename T>
T Vector<T>::pop() {
    T lastElementCopy = vector[--lastIndex];

    if (size - grow >= lastIndex)
        resize(size - grow);

    return lastElementCopy;
}

template<typename T>
void Vector<T>::remove(unsigned int index) {
    if (index > lastIndex) return;

    for (int i = index; i < lastIndex; i++)
        vector[i] = vector[i + 1];

    --lastIndex;

    if (size - grow >= lastIndex)
        resize(size - grow);
}

template<typename T>
void Vector<T>::insert(T element, unsigned int index) {
    unsigned int count = lastIndex + 1;
    unsigned int newCount;

    if (0 < index && index <= lastIndex + 1) newCount++;
    else newCount = index + 1;

    // daca nu incape elementul in vector marim vectorul
    if (size < newCount) resize(newCount + grow);

    // daca inseram dupa ultima pozitie
    if (index > lastIndex) {
        vector[index] = element;
        lastIndex = index;
    }
        // daca inseram pe ultima pozitie sau inainte de ultima pozitie
    else {
        for (int i = lastIndex + 1; i > index; i--)
            vector[i] = vector[i - 1];
        vector[index] = element;
        lastIndex++;
    }
}

template<typename T>
const T &Vector<T>::get(unsigned int index) {
    return vector[index];
}


template<typename T>
void Vector<T>::set(unsigned int index, T element) {
    vector[index] = element;
}

template<typename T>
int Vector<T>::count() {
    return lastIndex + 1;
}


template<typename T>
void Vector<T>::sort(bool (*fn)(int, int)) {
    for (int i = 0; i < count() - 1; i++)
        for (int j = 0; j < count() - i - 1; j++)
            if (fn(vector[j], vector[j + 1]))
                std::swap(vector[j], vector[j + 1]);
}
