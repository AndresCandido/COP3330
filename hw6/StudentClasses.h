// starter file for Student class and it's children classes header
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

class Student {
protected:
    char firstName[21];	// may assume first name is 20 characters or less
    char lastName[21];	// may assume last name is 20 characters or less
    string course;

public:
    Student(const char* lName, const char* fName, string c);
    virtual ~Student(){}

    const char* getFname() const;
    const char* getLname() const;
    string getCourse() const;

    virtual double calculateFinalGrade() const=0;   // make class abstract by giving it a pure virtual function, this is to prevent the user from making objects from this class
    virtual int getFinalExam() const=0;
};


// Derived class for Biology students
class BiologyStudent : public Student {
private:
    int labGrade;
    int Test1;
    int Test2;
    int Test3;
    int finalExam;

public:
    BiologyStudent(const char* lName, const char* fName, int lab, int T1, int T2, int T3, int Tfinal);

    double calculateFinalGrade() const;
    int getFinalExam() const;
};


// Derived class for Theater students
class TheaterStudent : public Student {
private:
    int participation;
    int midterm;
    int finalExam;

public:
    TheaterStudent(const char* lName, const char* fName, int Part, int Mid, int Tfinal);

    double calculateFinalGrade() const;
    int getFinalExam() const;
};


// Derived class for Computer Science students
class ComputerScienceStudent : public Student {
private:
    double programAverage;
    int test1;
    int test2;
    int finalExam;

public:
    ComputerScienceStudent(const char* lName, const char* fName, int Prog1, int Prog2, int Prog3, int Prog4, int Prog5, int Prog6, int T1, int T2, int Tfinal);

    double calculateFinalGrade() const;
    int getFinalExam() const;
};