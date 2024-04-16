//--------------- store.h ---------------

#include "book.h"

class store
{

public:
    store(double cash = 0.0);
    ~store();

    void addBook(const char* title, const char* author, Genre genre, double price);
    void sellBook(const char* title);
    void FindBook(const char* searchBy) const;
    void displayInventory() const;
    void displayInventory(Genre genre) const; //display by genre (using function overload)
    double getCashBalance() const;
    void sort(char choice); // extra credit


private:
    /* data */
    double cash;
    Book* inventory;
    int numBooks;
    int maxBooks;

    void resizeInventory();
    
};



