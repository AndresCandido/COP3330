//--------------- temperature.cpp ---------------
// The class definition for temperature.
//

#include <iostream>
#include <iomanip>
#include <cctype>
#include "temperature.h"

using namespace std;

temperature::temperature(double x, char y){
    y = toupper(y); // make char input UPPERCASE here
    if((x<0 && y=='K')||(x<-273.15 && y=='C')||(x<-459.67 && y=='F')){
        degree = 0;
        scale = 'C';
    } else if(y!='K' && y!='C' && y!='F'){
        degree = 0;
        scale = 'C';
    } else{
        degree = x;
        scale = y;
    }
    format='D';
}

void temperature::Show() const{
    if(format=='D'){
        cout << degree << " " << scale;
    }else if(format=='P'){
        cout<<fixed<<setprecision(1);
        cout << degree << " " << scale;
    }else if(format=='L'){
        if(scale=='C'){
            cout << degree << " Celsius";
        }else if(scale=='F'){
            cout << degree << " Fahrenheit";
        }else{
            cout << degree << " Kelvin";
        }
    }    
}

double temperature::GetDegrees() const{
    return degree;
}

char temperature::GetScale() const{
    return scale;
}

int temperature::Compare(const temperature& d) const{
    double first_temp, second_temp;    
    // Convert both temperatures to Kelvin for comparison (stored in temporary variables to not change the originals)
    if (scale == 'C') {
        first_temp = degree + 273.15;
    } else if (scale == 'F') {
        first_temp = (degree + 459.67) * (5.0 / 9.0);
    } else {
        first_temp = degree;
    }

    if (d.scale == 'C') {
        second_temp = d.degree + 273.15;
    } else if (d.scale == 'F') {
        second_temp = (d.degree + 459.67) * (5.0 / 9.0);
    } else {
        second_temp = d.degree;
    }

    // Compare the temperatures in Kelvin
    if (first_temp < second_temp) {
        return -1;
    } else if (first_temp == second_temp) {
        return 0;
    } else {
        return 1;
    }
}

void temperature::Input(){
    bool valid = 0;
    double input1;
    char input2;

    while (valid==false) {
        cout << "Enter the temperature (D S):";
        cin >>input1>>input2;

        input2 = toupper(input2);
        if((input1<0 && input2=='K')||(input1<-273.15 && input2=='C')||(input1<-459.67 && input2=='F')){
            cout << "Invalid temperature.  Try again.\n";
        } else if(input2!='K' && input2!='C' && input2!='F'){
            cout << "Invalid temperature.  Try again.\n";
        } else{
            cout << "You entered "<<input1<<" "<<input2<<"\n";
            degree = input1;
            scale = input2;
            valid=1;
        }
    }
}

bool temperature::Set(double deg,char s){
    s = toupper(s);
    if((deg<0 && s=='K')||(deg<-273.15 && s=='C')||(deg<-459.67 && s=='F')){
        return 0;
    } else if(s!='K' && s!='C' && s!='F'){
        return 0;
    } else{
        degree = deg;
        scale = s;
        return 1;
    }
}

bool temperature::SetFormat(char f){
    f = toupper(f);
    if ( f=='D' || f=='P' || f=='L'){
        format = f;
        return 1;
    }else{
        return 0;
    }
}

bool temperature::Convert(char sc){
    sc = toupper(sc);
    if(sc!='K' && sc!='C' && sc!='F'){
        return 0;
    }else if(sc == scale){
        return 1;
    }else{

        if (sc == 'K'){
            if (scale == 'C'){
                degree = degree + 273.15;
                scale = sc;
            }else if (scale == 'F'){
                degree = (degree + 459.67) * 5.0 / 9.0;
                scale = sc;
            }
        }else if (sc == 'C'){
            if (scale == 'K'){
                degree = degree - 273.15;
                scale = sc;
            }else if (scale == 'F'){
                degree = (degree - 32) * 5.0 / 9.0;
                scale = sc;
            }
        }else if (sc == 'F'){
            if (scale == 'C'){
                degree = (degree * 9.0 / 5.0) + 32;
                scale = sc;
            }else if (scale == 'K'){
                degree = (degree - 273.15) * 9.0 / 5.0 + 32;
                scale = sc;
            }
        }
        
        return 1;
    }
}

void temperature::Increment(int deg, char sc){ 
    sc=toupper(sc);
    if((deg<0 && sc=='K')||(deg<-273.15 && sc=='C')||(deg<-459.67 && sc=='F')){
        //nothing changes
    } else if(sc!='K' && sc!='C' && sc!='F'){
        //nothing changes
    }else if(sc == scale){
        degree = degree + deg;
    } else{

        if (sc == 'K'){
            if (scale == 'C'){
                deg = deg - 273.15;
                degree = degree + deg;
            }else if (scale == 'F'){
                deg = (deg - 273.15) * 9.0 / 5.0 + 32;
                degree = degree + deg;
            }
        }else if (sc == 'C'){
            if (scale == 'K'){
                deg = deg + 273.15;
                degree = degree + deg;
            }else if (scale == 'F'){
                deg = (deg * 9.0 / 5.0) + 32;
                degree = degree + deg;
            }
        }else if (sc == 'F'){
            if (scale == 'C'){
                deg = (deg - 32) * 5.0 / 9.0;
                degree = degree + deg;
            }else if (scale == 'K'){
                deg = (deg + 459.67) * 5.0 / 9.0;
                degree = degree + deg;
            }
        }

    }

}
