#include "Propozitie.h"
#include <iostream>

Propozitie::Propozitie(char *str) {
    cuvinte = new char *[1000];
    char *cuvant;

    propozitie = str;

    char *startOfWord = &str[0];
    char *endOfWord = nullptr;

    char *chr = &str[0];
    while (*chr != '\0') {
        if (*chr == ' ' || *(chr + 1) == '\0') {
            endOfWord = chr - 1;

            if (*(chr + 1) == '\0')
                endOfWord = chr;

            cuvant = new char[1000];

            int index = -1;
            for (char *i = startOfWord; i <= endOfWord; i++) {
                cuvant[++index] = *i;
            }

            cuvant[++index] = '\0';

            cuvinte[++indexCuvinte] = cuvant;
        }

        if (*chr == ' ') {
            startOfWord = chr + 1;
        }

        chr = chr + 1;

        if (*chr != ' ')
            nrTotalCaractere++;
    }
};

int Propozitie::strlen(const char *str) {
    int k = 0;
    const char *chr = str;

    while (*chr != '\0') {
        chr++;
        k++;
    }

    return k;
}

bool Propozitie::strcmp(const char *str1, const char *str2) {
    const char *chr1 = str1;
    const char *chr2 = str2;
    while (*chr1 != '\0') {
        if (*chr1 != *chr2)
            return false;

        chr1++;
        chr2++;
    }

    if (strlen(str1) != strlen(str2))
        return false;

    return true;
}

int Propozitie::vowals(const char *str) {
    const char *chr = str;
    int k = 0;

    while (*chr != '\0') {
        if (*chr == 'a' || *chr == 'e' || *chr == 'i' || *chr == 'o' || *chr == 'u' || *chr == 'A' || *chr == 'E' ||
            *chr == 'I' || *chr == 'O' || *chr == 'U')
            k++;
        chr++;
    }

    return k;
}

bool Propozitie::isNumber(const char *str) {
    const char *chr = str;

    while (*chr != '\0') {
        if (*chr < '0' || *chr > '9')
            return false;
        chr++;
    }

    return true;
}

int Propozitie::numbers() {
    int k = 0;
    for (int i = 0; i <= indexCuvinte; i++) {
        if (isNumber(cuvinte[i]))
            k++;
    }

    return k;
}

int Propozitie::operator[](const char *str) {
    if (strcmp(str, "total_chars"))
        return nrTotalCaractere;

    if (strcmp(str, "count"))
        return indexCuvinte + 1;

    if (strcmp(str, "numbers"))
        return numbers();

    if (strcmp(str, "vowals")) {
        int k = 0;

        for (int i = 0; i <= indexCuvinte; i++) {
            k += vowals(cuvinte[i]);
        }

        return k;
    }

    return -1;
}


void Propozitie::Set(char *str) {
//    for (int i = 0; i <= indexCuvinte; i++)
//        delete[] cuvinte[i];
//
//    delete[] cuvinte;

    nrTotalCaractere = 0;
    indexCuvinte = -1;

    cuvinte = new char *[1000];
    char *cuvant;

    propozitie = str;

    char *startOfWord = &str[0];
    char *endOfWord = nullptr;

    char *chr = &str[0];
    while (*chr != '\0') {
        if (*chr == ' ' || *(chr + 1) == '\0') {
            endOfWord = chr - 1;

            if (*(chr + 1) == '\0')
                endOfWord = chr;

            cuvant = new char[1000];

            int index = -1;
            for (char *i = startOfWord; i <= endOfWord; i++) {
                cuvant[++index] = *i;
            }

            cuvant[++index] = '\0';

            cuvinte[++indexCuvinte] = cuvant;
        }

        if (*chr == ' ') {
            startOfWord = chr + 1;
        }

        chr = chr + 1;

        if (*chr != ' ' && *chr != '.')
            nrTotalCaractere++;
    }
}

const char *Propozitie::operator[](const int index) {
    if (index < 0)
        return cuvinte[indexCuvinte + index + 1];
    return cuvinte[index];
};

int Propozitie::operator()(const int nrCaractere) {
    int k = 0;

    for (int i = 0; i <= indexCuvinte; i++) {
        if (strlen(cuvinte[i]) == nrCaractere)
            k++;
    }
    return k;
}




