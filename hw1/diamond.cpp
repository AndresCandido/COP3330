//--------------- Diamond.CPP ---------------
// The class definition for Diamond.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "diamond.h"

using namespace std;

Diamond::Diamond(int x, char y, char z){
    if(x<1){
        size=1;
    } else if(x>39){
        size=39;
    }else{
        size=x;
    }
    SetBorder(y);
    SetFill(z);
}

int Diamond::GetSize() const{
    return size;
}

int Diamond::Perimeter() const{
    return (size*4);
}

double Diamond::Area() const{
    return ( 2*((sqrt(3)/4)*pow(size,2)) );
}

void Diamond::Draw() const{
    int space = size-1;
    bool blank = 0;
  
    for (int i = 1; i <= size; ++i){
  	    for (int j = 1; j <= space; ++j){
  		    cout << ' ';
        }
        space--;
    
        for (int j = 1; j <= (2*i)-1; ++j){
    	    if (blank==0){
        	    if ( (j==1 || j==(2*i)-1) ){
            	    cout<<border;
                }else{
            	    cout<<fill;
                }
        	    blank = 1;
            } else{
        	    cout<<' ';
        	    blank=0;
            }
        }
        cout << '\n';
        blank = 0;  
    }
    space=1;
    for(int i = 1; i<= size - 1; i++){
  	    for (int j = 1; j <= space; ++j){
  		    cout << ' ';
        }
        space++;
    
        for (int j = 1; j <= 2*(size-i)-1; ++j){
    	    if (blank==0){
        	    if ( (j==1 || j==2*(size-i)-1) ){
            	    cout<<border;
                }else{
            	    cout<<fill;
                }
        	    blank = 1;
            } else{
        	    cout<<' ';
        	    blank=0;
            }    	
        }
        cout << '\n';
        blank = 0; 
    }
}

void Diamond::Summary() const{
    cout<<"Size of diamond's side = "<<GetSize()<<"units.\n";
    cout<<"Perimeter of diamond = "<<Perimeter()<<"units.\n";
    cout<<fixed<<setprecision(2);
    cout<<"Area of diamond = "<<Area()<<"units.\n";
    cout<<"Diamond looks like:\n";
    Draw();
}

void Diamond::Shrink(){
    if (size!=1){
        size--;
    }  
}

void Diamond::Grow(){
    if (size!=39){
        size++;
    }
}

void Diamond::SetBorder(char y){
    if ( (y>=33 && y<=126) ){
        border=y;
    }else{
        border='#';
    }
}

void Diamond::SetFill(char z){
    if ( (z>=33 && z<=126) ){
        fill=z;
    }else{
        fill='*';
    }
}
