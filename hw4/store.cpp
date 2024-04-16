//--------------- store.cpp ---------------
// The class definition for store.
//

#include "store.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;


store::store(double c){
    cash = c;
    numBooks = 0;
    maxBooks = 5;    // initial capacity of the inventory array
    inventory = new Book[maxBooks];
}

store::~store() {
    delete[] inventory;
}

void store::addBook(const char* title, const char* author, Genre genre, double price) {

    resizeInventory(); // check if inventory needs to be resized

    inventory[numBooks].Set(title, author, genre, price);
    numBooks++;
}

void store::sellBook(const char* title){
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(inventory[i].GetTitle(), title) == 0) { // check if book title is in array
            cash += inventory[i].GetPrice();
            // remove the book from the inventory by shifting all books after it one position to the left
            for (int j = i + 1; j < numBooks; j++) {
                inventory[j - 1] = inventory[j];
            }
            numBooks--;

            resizeInventory(); // check if inventory needs to be resized

            return;
        }
    } 

    cout << "Book not found in inventory.\n";
}

void store::resizeInventory() {

    if(numBooks==maxBooks){
        maxBooks += 5;  // increase the capacity of the inventory array by 5
    }else if(maxBooks > numBooks+5){
        maxBooks--;     // there should never be more than 5 unused slots in this array
    }else{
        return;         // dont change if unnecessary
    }

    Book* newInventory = new Book[maxBooks];

    // copy the books from the old inventory array to the new one
    for (int i = 0; i < numBooks; i++) {
        newInventory[i] = inventory[i];
    }

    // delete the old inventory array and update the pointer to the new one
    delete[] inventory;
    inventory = newInventory;
}

void store::FindBook(const char* searchBy) const{
    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (strstr(inventory[i].GetTitle(), searchBy) != NULL || strstr(inventory[i].GetAuthor(), searchBy) != NULL ) {
            inventory[i].Display();  
            found = true;          
        }
    }

    if(found == false){
        cout << "Book(s) not found in inventory.\n";
    }
}

void store::displayInventory() const{
    // Display each book in inventory
    if(numBooks==0){
        cout << "Inventory is empty.\nCurrent amount of money in the store cash register: $" << setw(7) << right << fixed << setprecision(2) << cash <<"\n";
        return;
    }else if(numBooks>0){
        cout << "\nTotal number of books in inventory: " << numBooks << "\nCurrent amount of money in the store cash register: $" << setw(7) << right << fixed << setprecision(2) << cash <<"\n";
    }

    for (int i = 0; i < numBooks; i++) {
        inventory[i].Display();
    }
}

void store::displayInventory(Genre genre) const{
    // Display each book in inventory of matching genre
    int bookOfGenreCounter = 0;
    for (int i = 0; i < numBooks; i++) {
        if(inventory[i].GetGenre() == genre){
            bookOfGenreCounter++;
        }
    }

    if(bookOfGenreCounter==0){
        cout << "No books of this genre in inventory.\nCurrent amount of money in the store cash register: $" << setw(7) << right << fixed << setprecision(2) << cash <<"\n";
        return;
    }else if(bookOfGenreCounter>0){
        cout << "\nTotal number of books of this genre in inventory: " << bookOfGenreCounter << "\nCurrent amount of money in the store cash register: $" << setw(7) << right << fixed << setprecision(2) << cash <<"\n";
    }

    for (int i = 0; i < numBooks; i++) {
        if(inventory[i].GetGenre() == genre){
            inventory[i].Display();
        }
    }
}

double store::getCashBalance() const {
    return cash;
}

void store::sort(char choice){
    // Convert the user's choice to uppercase for simplicity
    choice = toupper(choice);

    if (choice == 'A') {
        // Sort by author
        for (int i = 0; i < numBooks - 1; i++) {
            for (int j = i + 1; j < numBooks; j++) {
                if (strcmp(inventory[i].GetAuthor(), inventory[j].GetAuthor()) > 0) {
                    // Swap the books
                    Book temp = inventory[i];
                    inventory[i] = inventory[j];
                    inventory[j] = temp;
                }
            }
        }
    } else if (choice == 'T') {
        // Sort by title
        for (int i = 0; i < numBooks - 1; i++) {
            for (int j = i + 1; j < numBooks; j++) {
                if (strcmp(inventory[i].GetTitle(), inventory[j].GetTitle()) > 0) {
                    // Swap the books
                    Book temp = inventory[i];
                    inventory[i] = inventory[j];
                    inventory[j] = temp;
                }
            }
        }
    } else {
        // Invalid choice
        cout << "Invalid choice." << endl;
    }
}
