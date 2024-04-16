// Menu: main program to test the Student List class

#include <iostream>
#include <iomanip>
#include "StudentList.h" //StudentList.h contains StudentClasses.h (no need to declare again)

using namespace std;


void display_menu() {
    cout << setw(10) << "*** Student List menu ***\n\n";
    cout << setw(10) << "I       Import students from a file\n";
    cout << setw(10) << "S       Show student list (brief)\n";
    cout << setw(10) << "E       Export a grade report (to file)\n";
    cout << setw(10) << "M       Show this Menu\n";
    cout << setw(10) << "Q       Quit Program\n";
}

int main() {

    StudentList myList;
    char input;
    string fileName;

    display_menu();

    while (true) { // menu body

        cout << "Enter a menu option: ";
        cin >> input;
        input = toupper(input);

        if (input == 'I') {
            cout << "Enter filename: ";
            cin >> fileName;
            cout << "\n";
            const char* charArray = fileName.c_str();
            myList.ImportFile(charArray);
        }
        else if(input == 'S'){
            myList.ShowList();
        }
        else if(input == 'E'){
            cout << "Enter filename: ";
            cin >> fileName;
            cout << "\n";
            const char* charArray = fileName.c_str();
            myList.CreateReportFile(charArray);
        }
        else if(input == 'M'){
            display_menu();
        }
        else if(input == 'Q'){
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid menu option. Please try again.\n";
        }
        
    }

    return 0;
}