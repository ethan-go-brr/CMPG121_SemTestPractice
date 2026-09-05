#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

struct Book
{
    string title;
    string ID;
    string author;
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

string createBookID(Book books[], int count)
{
    string title;
    string ID, firstThree;
    int randNum;

    title = books[count].title;
    firstThree = title.substr(0, 3);
    randNum = rand() % 100;
    ID = firstThree + to_string(randNum);

    return ID;
}


void addNewBook(Book books[], int& count)
{
    char opt;
    string ID;

    do 
    {
        cout << "Title of the book: ";
        getline(cin, books[count].title);
        
        cout << "Author of the book: ";;
        getline(cin, books[count].author);

        // ID Stuff needs to go here
        ID = createBookID(books, count);
        books[count].ID = ID;
        // availability will also go here
        books[count].available = true;
        count++;

        cout << "Would you like to add another book? (y/n): ";
        cin >> opt;

    } while (tolower(opt) == 'y');
}

bool isAvailable()
{

}

void viewBooks(Book books[], int count)
{
    string ID;
    cout << "=== All books in the library ===" << endl;
    cout << endl;
    ID = createBookID(books, count);
    for (int i = 0; i < count; i++)
    {
        cout << books[count].title << " by " << books[count].author << endl;
        cout << "Book ID: " << ID << endl;
        cout << "Availability: " << /*still need to do the availability function*/ << endl;
    }
}


int main()
{
    srand(time(0));

    int choice;
    int count = 0;

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

