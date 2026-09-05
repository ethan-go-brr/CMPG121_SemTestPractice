#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Book
{
    string title;
    string ID;
    bool available;

};

Book makeBook(string title, string ID, bool available)
{
    Book books;

    books.title = title;
    books.ID = ID;
    books.available = available;

    return books;
}

void addNewBook(Book books[], int count)
{
    
}
int main()
{
    srand(time(0));

    int choice;

    cout << "Welcome to the Book Manager!" << endl;

    cout << "What would you like to do?" << endl;
    cout << endl;

    cout << "1. Add a new book" << endl;
    cout << "2. View all books" << endl;
    cout << "3. View all available books" << endl;
    cout << "4. View all borrowed books" << endl;
    cout << "5. Rent a book" << endl;
    cout << "6. Return a book" << endl;
    cout << "7. Remove a book from the shelves" << endl;
    cout << "8. Exit" << endl;

    cout << "Enter a choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            cout << "Thank you for using The Book Manager! Goodbye." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please choose an option between 1 and 8!" << endl;
            break;
        }
    }
    return 0;
}

