#ifndef FLEX_H
#define FLEX_H

#include <iostream>

class Flex {
public:
    Flex();
    Flex(const char* str);
    ~Flex();
    void cat(const Flex& other);
    friend std::ostream& operator<<(std::ostream& os, const Flex& flex);
private:
    char* str_;
    int size_;
};

#endif /* FLEX_H */