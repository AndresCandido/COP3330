//--------------- book.cpp ---------------
// The class definition for book.
//

#include "book.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Book::Book()
{
    title[0] = '\0';
    author[0] = '\0';
    type = FICTION;
    price = 0.0;
}

// Set function
void Book::Set(const char* t, const char* a, Genre g, double p)
{
    strncpy(title, t, sizeof(title));
    strncpy(author, a, sizeof(author));
    type = g;
    price = p;
}


const char* Book::GetTitle() const{
    return title;
}

const char* Book::GetAuthor() const{
    return author;
}

double Book::GetPrice() const{
    return price;
}

Genre Book::GetGenre() const{
    return type;
}

void Book::Display() const{

    cout << setw(sizeof(title)) << left << title << setw(sizeof(author)) << left << author;

    if(type == FICTION){
        cout << setw(10) << left << "Fiction";
    }else if(type == MYSTERY){
        cout << setw(10) << left << "Mystery";
    }else if(type == SCIFI){
        cout << setw(10) << left << "Sci-Fi";
    }else if(type == COMPUTER){
        cout << setw(10) << left << "Computer";
    }

    cout << "$" << setw(7) << right << fixed << setprecision(2) << price <<"\n";
}