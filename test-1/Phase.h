class Phase {
private:
    void resize();

public:
    char *str;
    unsigned int strSize;

    Phase();

    Phase(const char *other);

    Phase &operator=(const char *sir);

    void print();
};


