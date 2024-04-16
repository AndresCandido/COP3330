#include "flex.h"
#include <cstring>

Flex::Flex() {
    size_ = 1;
    str_ = new char[size_];
    std::strcpy(str_, " ");
}

Flex::Flex(const char* str) {
    size_ = std::strlen(str) + 1;
    str_ = new char[size_];
    std::strcpy(str_, str);
}

Flex::~Flex() {
    delete[] str_;
}

void Flex::cat(const Flex& other) {
    int newSize = size_ + other.size_ - 1;
    char* newStr = new char[newSize];
    std::strcpy(newStr, str_);
    std::strcat(newStr, other.str_);
    delete[] str_;
    str_ = newStr;
    size_ = newSize;
}

std::ostream& operator<<(std::ostream& os, const Flex& flex) {
    os << "*" << flex.str_ << "*";
    return os;
}