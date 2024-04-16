#include <iostream>
#include <fstream>
#include <iomanip>
#include "StudentClasses.h"

using namespace std;

class StudentList
{
public:
   StudentList();		// starts out empty
   ~StudentList();		// cleanup (destructor)

   void ImportFile(const char* filename);
   bool CreateReportFile(const char* filename);
   void ShowList() const;	// print basic list data

private:

    Student** List;         // array of student pointers (List is a pointer to a pointer)
    int numStudents;        // current size of the list
    int maxStudents;        // max capacity of the list

    void resizeList(int n); // resize the list
    
};
