// cpp file for Student class and it's children classes header
#include "StudentClasses.h"

// Student Class

Student::Student(const char* lName, const char*  fName, string c) {
    strncpy(lastName, lName, sizeof(lastName));
    strncpy(firstName, fName, sizeof(firstName));
    course = c;
}

const char* Student::getFname() const {
    return firstName;
}

const char* Student::getLname() const {
    return lastName;
}

string Student::getCourse() const {
    return course;
}



// Biology students Class

BiologyStudent::BiologyStudent(const char* lName, const char* fName, int lab, int T1, int T2, int T3, int Tfinal) : Student(lName, fName, "Biology") {
    labGrade = lab;
    Test1 = T1;
    Test2 = T2;
    Test3 = T3;
    finalExam = Tfinal;
}

double BiologyStudent::calculateFinalGrade() const {
    return labGrade * 0.3 + Test1 * 0.15 + Test2 * 0.15 + Test3 * 0.15 + finalExam * 0.25;
}

int BiologyStudent::getFinalExam() const {
    return finalExam;
}




// theater students Class

TheaterStudent::TheaterStudent(const char* lName, const char* fName, int Part, int Mid, int Tfinal) : Student(lName, fName, "Theater") {
    participation = Part;
    midterm = Mid;
    finalExam = Tfinal;
}

double TheaterStudent::calculateFinalGrade() const {
    return participation * 0.4 + midterm * 0.25 + finalExam * 0.35;
}

int TheaterStudent::getFinalExam() const {
    return finalExam;
}




// Computer Science students Class

ComputerScienceStudent::ComputerScienceStudent(const char* lName, const char* fName, int Prog1, int Prog2, int Prog3, int Prog4, int Prog5, int Prog6, int T1, int T2, int Tfinal)
: Student(lName, fName, "Computer Science") {
    programAverage = (Prog1+Prog2+Prog3+Prog4+Prog5+Prog6)/6.0;
    test1 = T1;
    test2 = T2;
    finalExam = Tfinal;
}

double ComputerScienceStudent::calculateFinalGrade() const {
    return programAverage * 0.3 + test1 * 0.2 + test2 * 0.2 + finalExam * 0.3;
}

int ComputerScienceStudent::getFinalExam() const {
    return finalExam;
}
