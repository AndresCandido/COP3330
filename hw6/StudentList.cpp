// cpp file for Student List class
#include "StudentList.h"

StudentList::StudentList()
{
    numStudents = 0;
    maxStudents = 0;

    List = NULL;
}

StudentList::~StudentList()
{
    for (int i = 0; i < maxStudents; i++) { // delete all objects individually
        delete List[i];
    }
    delete[] List;                          // then delete list 
}

void StudentList::resizeList(int n)
{
    maxStudents += n;

    Student** temp = new Student*[maxStudents];

    // Copy the contents of the old array to the new array if any
    for (int i = 0; i < numStudents; i++) {
        temp[i] = List[i];
    }

    // Delete the old array
    delete[] List;

    // Update the pointer to point to the new array
    List = temp;

}

// Import student data from a file 
void StudentList::ImportFile(const char* filename)
{
    ifstream infile;
    infile.open(filename);
    if (!infile)
    {
        cout << "Invalid file. No data imported\n";
        return;   // returns if filename is invalid
    }

    int IncreaseBy; 
    infile >> IncreaseBy; // read in the number of students to add to list 

    resizeList(IncreaseBy);

    // Read in each student's data and add them to the list
    for (int i = numStudents; i < maxStudents; i++) {

        // Ignore the rest of the line, including the newline character
        string dummy;
        getline(infile, dummy);

        char last_name[21], first_name[21];
        infile.getline(last_name, 21, ','); // read last name
        infile.getline(first_name, 21); // read first name

        // Delete the first character of FirstName (a single whitespace, we don't want it)
        int len = strlen(first_name);
        for (int i = 0; i < len - 1; i++) {
            first_name[i] = first_name[i + 1];
        }
        first_name[len - 2] = '\0';

        string course_name;
        infile >> course_name;  

        if (course_name == "Biology") {
            int lab_grade, test1_grade, test2_grade, test3_grade, final_exam_grade;
            infile >> lab_grade >> test1_grade >> test2_grade >> test3_grade >> final_exam_grade;
            Student* newStudent = new BiologyStudent(last_name, first_name, lab_grade, test1_grade, test2_grade, test3_grade, final_exam_grade);
            List[i] = newStudent;
        }
        else if (course_name == "Theater") {
            int participation_grade, midterm_grade, final_exam_grade;
            infile >> participation_grade >> midterm_grade >> final_exam_grade;
            Student* newStudent = new TheaterStudent(last_name, first_name, participation_grade, midterm_grade, final_exam_grade);
            List[i] = newStudent;
        }
        else if (course_name == "Computer") {
            string trash;
            int Prog1, Prog2, Prog3, Prog4, Prog5, Prog6, test1_grade, test2_grade, final_exam_grade;
            infile >> trash >> Prog1 >> Prog2 >> Prog3 >> Prog4 >> Prog5 >> Prog6 >> test1_grade >> test2_grade >> final_exam_grade;
            Student* newStudent = new ComputerScienceStudent(last_name, first_name, Prog1, Prog2, Prog3, Prog4, Prog5, Prog6, test1_grade, test2_grade, final_exam_grade);
            List[i] = newStudent;
        }
        else {
            // Unknown course name, skip this student
            i-=1;           // set loop 1 back so next student fills this spot in array
            maxStudents-=1; // make maxStudent-1 since this student doesn't count
            continue;
        }

    }

    numStudents = maxStudents;
    infile.close();

    cout << "\n\n";
    return;
}

// Print basic list data
void StudentList::ShowList() const
{
    cout << left << setw(20) << "Last" << left << setw(20) << "First" << "Course\n\n";

    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(20) << List[i]->getLname() << left << setw(20) << List[i]->getFname()
        << List[i]->getCourse() << "\n";
    }

    cout << "\n";
}

// Create a report file with student data
bool StudentList::CreateReportFile(const char* filename)
{
    ofstream outfile;
    outfile.open(filename);

    if (!outfile)			// if the open failed
    {
      cerr << "Attempt to create file failed\n";
      return false;
    }

    outfile << "Student Grade Summary\n---------------------\n\nBIOLOGY CLASS\n\n";
    outfile << left << setw(40) << "Student" << setw(6) << "Final" << setw(8) << "Final" << "Letter\n";
    outfile << left << setw(40) << "Name" << setw(6) << "Exam" << setw(8) << "Avg" << "Grade\n";
    outfile << "----------------------------------------------------------------------\n";

    int total_As =0, total_Bs =0, total_Cs =0, total_Ds =0, total_Fs =0;

    for (int i = 0; i < numStudents; i++)
    {

        if (List[i]->getCourse()=="Biology"){

            char letter = 'x';
            if (List[i]->calculateFinalGrade() >= 90.0) {
                letter = 'A';
                total_As += 1;
            } else if (List[i]->calculateFinalGrade() >= 80.0) {
                letter = 'B';
                total_Bs += 1;
            } else if (List[i]->calculateFinalGrade() >= 70.0) {
                letter = 'C';
                total_Cs += 1;
            } else if (List[i]->calculateFinalGrade() >= 60.0) {
                letter = 'D';
                total_Ds += 1;
            } else {
                letter = 'F';
                total_Fs += 1;
            } 
            
            outfile << List[i]->getFname() << " " << left << setw(40 - (strlen(List[i]->getFname())+1)) << List[i]->getLname() 
            << List[i]->getFinalExam() 
            << right << setw(9) << fixed << setprecision(2) << List[i]->calculateFinalGrade() 
            << right << setw(4) << letter <<"\n"; 
        }
    }

    outfile << "\n\nTHEATER CLASS\n\n";
    outfile << left << setw(40) << "Student" << setw(6) << "Final" << setw(8) << "Final" << "Letter\n";
    outfile << left << setw(40) << "Name" << setw(6) << "Exam" << setw(8) << "Avg" << "Grade\n";
    outfile << "----------------------------------------------------------------------\n";

    for (int i = 0; i < numStudents; i++)
    {

        if (List[i]->getCourse()=="Theater"){

            char letter = 'x';
            if (List[i]->calculateFinalGrade() >= 90.0) {
                letter = 'A';
                total_As += 1;
            } else if (List[i]->calculateFinalGrade() >= 80.0) {
                letter = 'B';
                total_Bs += 1;
            } else if (List[i]->calculateFinalGrade() >= 70.0) {
                letter = 'C';
                total_Cs += 1;
            } else if (List[i]->calculateFinalGrade() >= 60.0) {
                letter = 'D';
                total_Ds += 1;
            } else {
                letter = 'F';
                total_Fs += 1;
            } 
            
            outfile << List[i]->getFname() << " " << left << setw(40 - (strlen(List[i]->getFname())+1)) << List[i]->getLname() 
            << List[i]->getFinalExam() 
            << right << setw(9) << fixed << setprecision(2) << List[i]->calculateFinalGrade() 
            << right << setw(4) << letter <<"\n";  
        }
    }

    outfile << "\n\nCOMPSCI CLASS\n\n";
    outfile << left << setw(40) << "Student" << setw(6) << "Final" << setw(8) << "Final" << "Letter\n";
    outfile << left << setw(40) << "Name" << setw(6) << "Exam" << setw(8) << "Avg" << "Grade\n";
    outfile << "----------------------------------------------------------------------\n";

    for (int i = 0; i < numStudents; i++)
    {

        if (List[i]->getCourse()=="Computer Science"){

            char letter = 'x';
            if (List[i]->calculateFinalGrade() >= 90.0) {
                letter = 'A';
                total_As += 1;
            } else if (List[i]->calculateFinalGrade() >= 80.0) {
                letter = 'B';
                total_Bs += 1;
            } else if (List[i]->calculateFinalGrade() >= 70.0) {
                letter = 'C';
                total_Cs += 1;
            } else if (List[i]->calculateFinalGrade() >= 60.0) {
                letter = 'D';
                total_Ds += 1;
            } else {
                letter = 'F';
                total_Fs += 1;
            } 
            
            outfile << List[i]->getFname() << " " << left << setw(40 - (strlen(List[i]->getFname())+1)) << List[i]->getLname() 
            << List[i]->getFinalExam() 
            << right << setw(9) << fixed << setprecision(2) << List[i]->calculateFinalGrade() 
            << right << setw(4) << letter <<"\n"; 
        }
    }

    outfile << "\n\nOVERALL GRADE DISTRIBUTION\n";
    outfile << "A: " << setw(3) << total_As << endl;
    outfile << "B: " << setw(3) << total_Bs << endl;
    outfile << "C: " << setw(3) << total_Cs << endl;
    outfile << "D: " << setw(3) << total_Ds << endl;
    outfile << "F: " << setw(3) << total_Fs << endl;

    outfile.close();

    return true;
}