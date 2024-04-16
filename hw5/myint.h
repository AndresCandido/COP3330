// starter file for MyInt class header
#include <iostream>
#include <iomanip>
#include <cstring> // for strlen()
#include <cctype>

using namespace std;

class MyInt
{
   // these overload starters are declared as friend functions

   friend MyInt operator+ (const MyInt& x, const MyInt& y);

   friend MyInt operator- (const MyInt& x, const MyInt& y);

   friend MyInt operator* (const MyInt& x, const MyInt& y);

   friend MyInt operator/ (const MyInt& x, const MyInt& y);

   friend MyInt operator% (const MyInt& x, const MyInt& y);


   friend bool operator< (const MyInt& x, const MyInt& y);

   friend bool operator> (const MyInt& x, const MyInt& y);

   friend bool operator<= (const MyInt& x, const MyInt& y);

   friend bool operator>= (const MyInt& x, const MyInt& y);

   friend bool operator== (const MyInt& x, const MyInt& y);

   friend bool operator!= (const MyInt& x, const MyInt& y);


   friend ostream& operator<<(ostream& , const MyInt& );

   friend istream& operator>>(istream& , MyInt& );


public:

   MyInt(int n = 0);         // constructor with default value 
   MyInt(const char *str);   // constructor that takes a C-style string 
   MyInt(const MyInt& other); // copy constructor

   ~MyInt(); // destructor 
    
   // operator overloads as member 
   MyInt& operator=(const MyInt& other); // assignment operator

   MyInt& operator++();     // prefix increment
   MyInt operator++(int);   // postfix increment

private: 

   int* digits;            // pointer to dynamic array of digits
   unsigned int numDigits; // number of digits in the number 

};