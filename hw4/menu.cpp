// Menu: main program to test the Book store class

#include <iostream>
#include <iomanip>
#include "store.h" //store.h contains book.h (no need to declare again)

using namespace std;


void display_menu() {
    cout << "\nMenu:\n";
    cout << "A: Add a book to inventory\n";
    cout << "F: Find a book from inventory\n";
    cout << "S: Sell a book\n";
    cout << "D: Display the inventory list\n";
    cout << "G: Genre summary\n";
    cout << "M: Show this Menu\n";
    cout << "O: Sort books in inventory\n";
    cout << "X: eXit the program\n\n";
}

int main(){

    store bookStore;    // create bookStore object with 0.0 cash in register
    char input, title[31], author[21], genreChar, searchBy[31], sortBy;
    Genre genre;
    double price;

    while (true) { // menu body

        display_menu();
        cout << "Enter a menu option: ";
        cin >> input;
        input = toupper(input);
        
        if (input == 'X') {
            cout << "Current amount of money in the store cash register: $"<< setw(7) << right << fixed << setprecision(2) << bookStore.getCashBalance() << "\n";
            break;
        }
        else if (input == 'A') {
            cout << "Adding a book to inventory...\n"; 
            cout << "Enter the book's title: ";         // For title and author, we assume that the user will not enter more characters than the stated limits for these inputs.
            cin.getline(title, 31);
            cin.getline(title, 31);
            
            cout << "\nEnter the book's author: ";
            cin.getline(author, 21);

            genreChar='x'; 
            while(genreChar != 'F' && genreChar != 'M' && genreChar != 'S' && genreChar != 'C'){

                cout <<"genre input should be F, M, S, or C.\n";
                cout << "Enter the book's genre: ";
                cin >> genreChar;

                // Convert genreChar to uppercase
                genreChar = toupper(genreChar);

                if(genreChar=='F'){
                    genre = FICTION;
                }else if(genreChar=='M'){
                    genre = MYSTERY;
                }else if (genreChar=='S'){
                    genre = SCIFI;
                }else if (genreChar=='C'){
                    genre = COMPUTER;
                }else{
                    cout << "Invalid genre, try again.\n";
                }
            }

            price = -1.0;
            while(price<0){
                cout << "Enter the book's price: ";
                cin >> price;

                if (price<0){
                    cout << "Price must be positive, try again.\n";
                }     
            }

            bookStore.addBook(title,author,genre,price);
        }
        else if (input == 'F') {
            cout << "Finding a book from inventory...\n";
            cout << "Input book title or author's name: ";
	    cin.getline(searchBy, 31);
            cin.getline(searchBy, 31);

            bookStore.FindBook(searchBy);
        }
        else if (input == 'S') {
            cout << "Selling a book...\n";
            cout << "Input book title: ";
	    cin.getline(title, 31);
            cin.getline(title, 31);
            
            bookStore.sellBook(title);
        }
        else if (input == 'D') {
            cout << "Displaying the inventory list...\n";

            bookStore.displayInventory();
        }
        else if (input == 'G') {
            cout << "Search books by genre in inventory...\n";
            genreChar='x';

            while(genreChar != 'F' && genreChar != 'M' && genreChar != 'S' && genreChar != 'C'){

                cout <<"genre input should be F, M, S, or C.\n";
                cout << "Enter the book's genre: ";
                cin >> genreChar;

                // Convert genreChar to uppercase
                genreChar = toupper(genreChar);

                if(genreChar=='F'){
                    genre = FICTION;
                }else if(genreChar=='M'){
                    genre = MYSTERY;
                }else if (genreChar=='S'){
                    genre = SCIFI;
                }else if (genreChar=='C'){
                    genre = COMPUTER;
                }else{
                    cout << "Invalid genre, try again.\n";
                }
            }

            bookStore.displayInventory(genre);
        }
        else if (input == 'M') {
            // just display the menu again
            display_menu();
        }
        else if (input == 'O') {
            cout << "Sort books in inventory...\n";

            sortBy = 'x';
            while(sortBy != 'T' && sortBy != 'A'){
                cout << "Sort by Title or Author (input T or A): ";
                cin >> sortBy;
                sortBy = toupper(sortBy);

                if (sortBy=='T' || sortBy=='A'){
                    bookStore.sort(sortBy);
                }else{
                    cout << "Invalid input, try again.\n";
                }
            }

            cout << "Books in inventory successfully sorted.\n";
        }
        else {
            cout << "Invalid menu option. Please try again.\n";
        }
    }
}
