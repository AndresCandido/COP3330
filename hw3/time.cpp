//--------------- time.cpp ---------------
// The class definition for timer.
//

#include "time.h"
using namespace std;

// friend functions 

Time operator+(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);
    return Time(temp1+temp2);
}

Time operator-(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);
    return Time(temp1-temp2);
}

Time operator*(const Time& t1, int x){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    return Time(temp1*x);
}

bool operator<(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);

    if (temp1 < temp2){
        return 1;
    } else{
        return 0;
    }  
}

bool operator>(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);

    if (temp1 > temp2){
        return 1;
    } else{
        return 0;
    }  
}

bool operator<=(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);
    
    if (temp1 <= temp2){
        return 1;
    } else{
        return 0;
    } 
}

bool operator>=(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);
    
    if (temp1 >= temp2){
        return 1;
    } else{
        return 0;
    } 
}

bool operator==(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);
    
    if (temp1 == temp2){
        return 1;
    } else{
        return 0;
    } 
}

bool operator!=(const Time& t1, const Time& t2){

    int temp1 = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
    int temp2 = t2.time_to_sec(t2.days,t2.hours,t2.minutes,t2.seconds);
    
    if (temp1 != temp2){
        return 1;
    } else{
        return 0;
    } 
}

ostream& operator<<(ostream& os, const Time& t1){

    os << t1.days <<"~";
    if (t1.hours<10){
        os<<"0";
    }
    os << t1.hours <<":";
    if (t1.minutes<10){
        os<<"0";
    }    
    os << t1.minutes <<":";
    if (t1.seconds<10){
        os<<"0";
    }
    os << t1.seconds;

    return os;
}

istream& operator>>(istream& is, Time& t1){  
    char tilde, colon1, colon2;
    is >> t1.days >> tilde >> t1.hours >> colon1 >> t1.minutes >> colon2 >> t1.seconds;

    if( (t1.days<0)||(t1.hours<0)||(t1.minutes<0)||(t1.seconds<0) ){
        t1.days=0;
        t1.hours=0;
        t1.minutes=0;
        t1.seconds=0;
    }else{
        int secs = t1.time_to_sec(t1.days,t1.hours,t1.minutes,t1.seconds);
        t1.sec_to_time(secs);
    }

    return is;
}

// member functions
Time::Time(){
    days=0;
    hours=0;
    minutes=0;
    seconds=0;
}

Time::Time(int sec){
    sec_to_time(sec);
}

Time::Time(int a, int b, int c, int d){
    if( (a<0)||(b<0)||(c<0)||(d<0) ){
        days=0;
        hours=0;
        minutes=0;
        seconds=0;
    }else{
        int secs = time_to_sec(a,b,c,d);
        sec_to_time(secs);
    }
}

void Time::sec_to_time(int a){
    if(a<=0){
        days=0;
        hours=0;
        minutes=0;
        seconds=0;
    }else{
        int temp =a/60;
        seconds = a%60;
        minutes = temp%60;
        temp = temp/60;
        hours = temp%24;
        days = temp/24;
    }
}

int Time::time_to_sec(int a, int b, int c, int d) const{
    return ( (a*86400)+(b*3600)+(c*60)+(d) );
}

Time& Time::operator++(){       // pre-fix increment

    int temp = time_to_sec(days,hours,minutes,seconds);
    temp = temp + 1;
    sec_to_time(temp);
    return *this;
}

Time Time::operator++(int){     // postfix increment

    Time temp1 = *this;
    int temp2 = time_to_sec(days,hours,minutes,seconds);
    temp2 = temp2 + 1;
    sec_to_time(temp2);
    return temp1;
}

Time& Time::operator--(){       // prefix decrement

    int temp = time_to_sec(days,hours,minutes,seconds);
    temp = temp - 1;
    sec_to_time(temp);
    return *this;
}	

Time Time::operator--(int){     // postfix decrement

    Time temp1 = *this;
    int temp2 = time_to_sec(days,hours,minutes,seconds);
    temp2 = temp2 - 1;
    sec_to_time(temp2);
    return temp1;
}
