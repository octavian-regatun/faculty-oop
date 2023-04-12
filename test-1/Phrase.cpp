#include "Phrase.h"

Phrase::Phrase(const char *s) {
    str = s;
}

Phrase::operator int() {
    int index = 0;
    int counter = 0;
    char chr = str[index];

    while (chr != '\0') {
        if (chr == ' ')
            counter++;
        chr = str[++index];
    }

    return counter;
}

const char *Phrase::operator[](const int index) {
    int counter = 0;
    int wordIndex = -1;
    const char *startOfWord = &str[0];
    const char *endOfWord = nullptr;

    const char *chr = &str[0];
    while (*chr != '\0') {
        if (*chr != ' ') {
            if (*(chr - 1) == ' ') {
                wordIndex++;
                if (wordIndex == index)
                    startOfWord = chr;
            } else if (*(chr + 1) == ' ' || *(chr + 1) == '\n') {
                if (wordIndex == index)
                    endOfWord = chr;
                if (counter == 0) {
                    startOfWord = chr;
                }
            }
        }
        counter++;
        chr++;
    }

    char *word = new char[100];
    int j = -1;
    for (auto i = startOfWord; i <= endOfWord; i++) {
        word[++j] = *i;
    }

    word[++j] = '\0';

    return word;
}

const int Phrase::CountLetter(char letter) {
    const char *chr = &str[0];
    int counter = 0;

    while (*chr != '\0') {
        if (*chr == letter)
            counter++;
        chr++;
    }

    return counter;
}

const int Phrase::CountVowels() {

    const char *chr = &str[0];
    int counter = 0;

    while (*chr != '\0') {
        if (*chr == 'a' || *chr == 'e' || *chr == 'i' || *chr == 'o' || *chr == 'u' || *chr == 'A' || *chr == 'E' ||
            *chr == 'I' || *chr == 'O' || *chr == 'U')
            counter++;
        chr++;
    }

    return counter;
}
