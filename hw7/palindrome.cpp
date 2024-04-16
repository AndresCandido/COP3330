#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"

using namespace std;

bool isPalindrome(const char *str) {
    Stack<char> stack;
    int len = strlen(str);

    // Push only letters onto the stack, ignoring spaces and punctuation
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {              // Here we check if item in stack is a letter
            stack.push(tolower(str[i]));
        }
    }

    // Check if the string is a palindrome by comparing the characters in the stack
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            char c;
            stack.pop(c);
            if (tolower(str[i]) != tolower(c)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    char str[101];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    if (isPalindrome(str)) {
        cout << '"' << str << '"' << " is a palindrome." << endl;
    } else {
        cout << '"' << str << '"' << " is not a palindrome." << endl;
    }

    return 0;
}