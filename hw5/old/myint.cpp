#include <iostream>
#include "myint.h"

using namespace std;


// ------------------------- friend functions ----------------------------

MyInt operator+ (const MyInt& x, const MyInt& y){
    // find the maximum number of digits between the two input MyInt objects
    unsigned int maxDigits;
    if (x.numDigits > y.numDigits) {
        maxDigits = x.numDigits;
    } else {
        maxDigits = y.numDigits;
    }
    // allocate memory for the digits array in a result MyInt object
    MyInt result;
    result.digits = new int[maxDigits + 1]; // add one extra digit in case of a carry
    result.numDigits = maxDigits + 1; // add one extra digit in case of a carry
    // perform the addition digit by digit, taking care of any carries
    int carry = 0;
    for (unsigned int i = 0; i < maxDigits; i++) {
        int sum = carry;
        if (i < x.numDigits) sum += x.digits[i];
        if (i < y.numDigits) sum += y.digits[i];
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        result.digits[maxDigits] = carry;
    } else {
        result.numDigits--;
    }
    return result;
}


MyInt operator- (const MyInt& x, const MyInt& y) {
    // check if x is smaller than y, return 0 if that's the case
    if (x < y) {
        return MyInt();
    }
    // allocate memory for the digits array of the result MyInt object
    MyInt result;
    result.digits = new int[x.numDigits]; // result has at most as many digits as x
    result.numDigits = x.numDigits;
    // perform the subtraction digit by digit, taking care of any borrows
    int borrow = 0;
    for (unsigned int i = 0; i < x.numDigits; i++) {
        int diff = borrow + x.digits[i];
        if (i < y.numDigits) diff -= y.digits[i];
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }
    // remove leading zeros from the result
    while (result.numDigits > 1 && result.digits[result.numDigits - 1] == 0) {
        result.numDigits--;
    }
    return result;
}


MyInt operator* (const MyInt& x, const MyInt& y) {
    // allocate memory for the result MyInt object
    MyInt result;
    result.digits = new int[x.numDigits + y.numDigits];
    result.numDigits = x.numDigits + y.numDigits;
    // set all digits to zero initially
    for (unsigned int i = 0; i < result.numDigits; i++) {
        result.digits[i] = 0;
    }
    // perform the multiplication digit by digit, storing the intermediate results
    for (unsigned int i = 0; i < y.numDigits; i++) {
        int carry = 0;
        for (unsigned int j = 0; j < x.numDigits; j++) {
            int prod = x.digits[j] * y.digits[i] + carry + result.digits[i+j];
            result.digits[i+j] = prod % 10;
            carry = prod / 10;
        }
        if (carry > 0) {
            result.digits[i+x.numDigits] += carry;
        }
    }
    // remove leading zeros from the result
    while (result.numDigits > 1 && result.digits[result.numDigits - 1] == 0) {
        result.numDigits--;
    }
    return result;
}


MyInt operator/ (const MyInt& x, const MyInt& y) {
    // if the divisor is zero, return an empty MyInt object (0)
    if (y == MyInt(0)) {
        return MyInt();
    }
    // if the dividend is less than the divisor, return an empty MyInt object (0)
    if (x < y) {
        return MyInt();
    }
    // if the divisor is 1, return dividend
    if (y == 1) {
        return x;
    }
    

    MyInt quotient;
    MyInt dividend = x;

    while (dividend >= y) {
        dividend = dividend - y;
        ++quotient;
    }

    return quotient;
}


MyInt operator% (const MyInt& x, const MyInt& y) {
    // if the divisor is zero, return an empty MyInt object (0)
    if (y == MyInt(0)) {
        return MyInt();
    }
    // if the dividend is less than the divisor, return the dividend
    if (x < y) {
        return x;
    }
    // if the divisor is 1, return  empty MyInt object (0)
    if (y == 1) {
        return MyInt();
    }
    
    MyInt remainder;
    MyInt dividend = x;

    while (dividend >= y) {
        dividend = dividend - y;
    }

    remainder = dividend;
    return remainder;
}


bool operator< (const MyInt& x, const MyInt& y) {
    // compare the number of digits first
    if (x.numDigits < y.numDigits) {
        return true;
    }
    if (x.numDigits > y.numDigits) {
        return false;
    }
    // if the number of digits is the same, compare digit by digit
    for (int i = x.numDigits - 1; i >= 0; i--) {
        if (x.digits[i] < y.digits[i]) {
            return true;
        }
        if (x.digits[i] > y.digits[i]) {
            return false;
        }
    }
    // if all digits are the same, the numbers are equal
    return false;
}


bool operator> (const MyInt& x, const MyInt& y) {
    return y < x; // just reverse the order and use the < operator
 }


bool operator<= (const MyInt& x, const MyInt& y) {
    return !(y < x); // just just reverse the order and negate the < operator (we want to return false if x less than y)
}


bool operator>= (const MyInt& x, const MyInt& y) {
    return !(x < y); // just negate the < operator (we want to return false if x less than y)
}

bool operator== (const MyInt& x, const MyInt& y) {
    // if the number of digits is different, they are not equal
    if (x.numDigits != y.numDigits) {
        return false;
    }
    // check each digit for equality
    for (int i = 0; i < x.numDigits; i++) {
        if (x.digits[i] != y.digits[i]) {
            return false;
        }
    }
    // if all digits match, they are equal
    return true;
}

bool operator!= (const MyInt& x, const MyInt& y) {
    return !(x == y);
}

ostream& operator<< (ostream& os, const MyInt& num) {
    // print the digits in reverse order
    for (int i = num.numDigits - 1; i >= 0; i--) {
        os << num.digits[i];
    }
    return os;
}

istream& operator>> (istream& is, MyInt& num) {
    // skip leading whitespace
    char ch;
    while (is.get(ch) && isspace(ch)) {}

    // read consecutive digits
    num = MyInt(0); // initialize the number to 0
    while (isdigit(ch)) {
        num = num*10;
        num = num + (ch - '0');
        is.get(ch);
    }

    // put back the last non-digit character
    if (!isspace(ch)) {
        is.unget();
    }

    return is;
}



// ------------------------- Member functions ----------------------------

// Contructor #1
MyInt::MyInt(int n) {
    if (n < 0) {

        numDigits = 1;
        digits = new int[1];
        digits[0] = 0;

    } else { 
        // calculate number of digits needed to represent n
        numDigits = 0;
        int temp = n;

        while (temp > 0) {
            temp /= 10;
            numDigits++;
        }

        if (numDigits == 0) numDigits = 1; // for n=0

        // allocate memory for digits array and populate it
        digits = new int[numDigits];
        for (unsigned int i = 0; i < numDigits; i++) {
            digits[i] = n % 10;
            n /= 10;
        }

    }
}


// Contructor #2
MyInt::MyInt(const char *str) {
    // determine the length of the input string
    unsigned int strLength = strlen(str);
    // check if the string is empty or contains non-digit characters
    bool validInput = true;
    if (strLength == 0) validInput = false;
    for (unsigned int i = 0; i < strLength; i++) {
        if (str[i] < '0' || str[i] > '9') {
            validInput = false;
            break;
        }
    }

    if (!validInput) {
        numDigits = 1;
        digits = new int[1];
        digits[0] = 0;
    } else {
        // allocate memory for the digits array
        numDigits = strLength;
        digits = new int[numDigits];
        // populate the digits array with the decimal digits of the input string
        for (unsigned int i = 0; i < numDigits; i++) {
            digits[i] = str[strLength - 1 - i] - '0';
        }
    }
}


// Copy Constructor
MyInt::MyInt(const MyInt& other) {
    numDigits = other.numDigits;
    digits = new int[numDigits];
    for (unsigned int i = 0; i < numDigits; i++) {
        digits[i] = other.digits[i];
    }
}


// Destructor
MyInt::~MyInt() {
    delete[] digits;
}


 // assignment operator
MyInt& MyInt::operator=(const MyInt& other) {
    if (this != &other) { // check for self-assignment
        delete[] digits;
        numDigits = other.numDigits;
        digits = new int[numDigits];
        for (unsigned int i = 0; i < numDigits; i++) {
            digits[i] = other.digits[i];
        }
    }
    return *this;
}

// prefix increment
MyInt& MyInt::operator++() {
    // prefix increment: add 1 to the current MyInt object
    *this = *this + 1;
    return *this;
}

// postfix increment
MyInt MyInt::operator++(int) {
    // postfix increment: create a copy of the current MyInt object and then increment it
    MyInt temp(*this);
    *this = *this + 1;
    return temp;
}