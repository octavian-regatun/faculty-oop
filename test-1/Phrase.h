class Phrase {
public:
    const char *str;

    Phrase(const char *s);

    operator int();

    const char *operator[](const int index);

    const char *GetLongestWord();

    const int CountVowels();

    const int CountLetter(char letter);
};
