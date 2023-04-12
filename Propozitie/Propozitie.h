class Propozitie {
private:
    int nrTotalCaractere = 0;
    int indexCuvinte = -1;
    char *propozitie;
    char **cuvinte;

    int strlen(const char *str);

    bool strcmp(const char *str1, const char *str2);

    int vowals(const char *str);

    bool isNumber(const char *str);

    int numbers();

    int totalChars(const char *str);

public:
    Propozitie(char *str);

    void Set(char *str);

    int operator[](const char *str);

    const char *operator[](const int index);

    int operator()(const int nrCaractere);
};
