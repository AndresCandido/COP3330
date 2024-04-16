/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
   temperature t1;		// should default to 0 Celsius
   temperature t2(34.5, 'F');  // should init to 34.5 Fahrenheit 

   // display dates to the screen
   cout << "\nTemperature t1 is: ";
   t1.Show();	
   cout << "\n t1 from get degree and scale: " << t1.GetDegrees() << " " << t1.GetScale();		
   cout << "\nTemperature t2 is: ";
   t2.Show();
   cout << "\n t1 from get degree and scale: " << t2.GetDegrees() << " " << t2.GetScale();

   t1.Input();			// Allow user to enter a temperature for t1
   cout << "\nTemperature t1 is: ";
   t1.Show();			
   
   t1.SetFormat('L');		// change format of t1 to "Long" format
   cout << "\nTemperature t1 is: ";
   t1.Show();		

   cout << "\nIs t1 greater than t2? (yes=1 equal=0 no=-1)" << t1.Compare(t2) << "\n";	

   cout << "\nIs t2 greater than t1? (yes=1 equal=0 no=-1)" << t2.Compare(t1) << "\n";	

   cout << "t1 before increment: ";
   t1.Show();
   t1.Increment(10,'k');
   cout << "\n t1 after increment: ";
   t1.Show();

   cout << "\nt2 before set: ";
   t2.Show();
   cout << "\nset worked? " << t2.Set(13.4,'C');
   cout << "\nt2 after set: ";
   t2.Show();

   cout << "\nt2 before converting: ";
   t2.Show();
   cout << "\nconvert worked? " << t2.Convert('k');
   cout << "\nt2 after set: ";
   t2.Show();
  
   // and so on.  Add your own tests to fully test the class' 
   //   functionality.
}