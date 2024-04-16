//--------------- time.h ---------------

#include <iostream>		// for "ostream", "istream" below
using namespace std;


class Time{

    // operator overload as friend functions,   friend functions are only declared inside the class definition and defined outside the class definition. 
    friend Time operator+(const Time& , const Time& );
    friend Time operator-(const Time& , const Time& );
    friend Time operator*(const Time& , int x );

    friend bool operator<(const Time& , const Time& );
    friend bool operator>(const Time& , const Time& );
    friend bool operator<=(const Time& , const Time& );
    friend bool operator>=(const Time& , const Time& );
    friend bool operator==(const Time& , const Time& );
    friend bool operator!=(const Time& , const Time& );

    friend ostream& operator<<(ostream& , const Time& );
    friend istream& operator>>(istream& , Time& );

public:

    // constructors with parameters and default. 
    Time();
    Time(int sec);
    Time(int a, int b, int c, int d); 

    // operator overload as member
    Time& operator++();	    // prefix increment
    Time operator++(int);	// postfix increment
    Time& operator--();	    // prefix decrement
    Time operator--(int);	// postfix decrement


private:
    // these are attributes
    int days,hours,minutes,seconds;

    // the user doesn't need to see these so we put them in the private section
    void sec_to_time(int a);
    int time_to_sec(int a, int b, int c, int d) const;

};