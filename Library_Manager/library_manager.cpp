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

void createBookID(Book books[], int count)
{
    string title;
    string ID, firstThree;
    int randNum;

    title = books[count].title;
    firstThree = title.substr(0, 3); // would like to make the letters uppercase
    randNum = rand() % 100;
    ID = firstThree + to_string(randNum);

    books[count].ID = ID;
}


void addNewBook(Book books[], int& count)
{
    char opt;
    string ID;

    do 
    {
        cin.ignore();
        cout << "Title of the book: ";
        getline(cin, books[count].title);
        
        cout << "Author of the book: ";;
        getline(cin, books[count].author);

        // ID Stuff needs to go here
        createBookID(books, count);
        // availability will also go here
        books[count].available = true;
        count++;

        cout << "Would you like to add another book? (y/n): ";
        cin >> opt;

    } while (tolower(opt) == 'y');
}


void viewBooks(Book books[], int count)
{
    string ID;
    if (count < 1)
    {
        cout << "There are no books to view!" << endl;
    }
    cout << "=== All books in the library ===" << endl;
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << books[i].title << " by " << books[i].author << endl;
        cout << "Book ID: " << books[i].ID << endl;
        if (books[i].available)
        {
            cout << "Availabiltiy: This book is available to borrow" << endl;
        }
        else
        {
            cout << "Availability:  This book is currently being borrowed" << endl;
        }
        
        cout << endl;
    }
}

void borrowBook(Book books[], int count, int& borrowedCount, int& availCount)
{
    string search;
    bool found = false;
    if (count < 1 || availCount < 1)
    {
        cout << "There are no books to borrow!" << endl;
        return;
    }
    cout << "Enter book ID to borrow: ";
    cin >> search;

    for (int i = 0; i < count; i++)
    {
        if (books[i].ID == search)
        {
            found = true;
            books[i].available = false;
            borrowedCount++;
            availCount--;
        }
    }
    if (!found)
    {
        cout << "Book ID not found" << endl;
    }
}

void returnBook(Book books[], int count, int& availCount, int& borrowedCount)
{
    string search;
    bool found = false;
    if (borrowedCount < 1 || count < 1)
    {
        cout << "There are no books to return!" << endl;
        return;
    }
    cout << "Enter book ID to return: ";
    cin >> search;

    for (int i = 0; i < count; i++)
    {
        if (books[i].ID == search)
        {
            found = true;
            books[i].available = true;
            borrowedCount--;
            availCount++;
        }
    }

    if(!found)
    {
        cout << "Book ID not found" << endl;
    }
}

void removeBook(Book books[], int& count)
{
    bool found = false;
    cin.ignore();

    if (count < 1)
    {
        cout << "There are no books to remove!" << endl;
        return;
    }
    string search;
    cout << "Enter ID of the book to remove: ";
    getline(cin, search);

    for (int i = 0; i < count; i++)
    {
        if (books[i].ID == search)
        {
            found = true;
            books[i].title = books[i + 1].title;
            books[i].author = books[i + 1].author;
            books[i].ID = books[i + 1].ID;
            books[i].available = books[i + 1].available;
            count--;
        }
    }

    if (!found)
    {
        cout << "Book ID not found" << endl;
        return;
    }
}

int main()
{
    srand(time(0));

    int choice;
    int availCount = 0;
    int borrowedCount = 0;
    int count = 0;
    const int MAX_SIZE = 50;
    Book books[MAX_SIZE];

    do
    {
       cout << "Welcome to the Book Manager!" << endl;

        cout << "What would you like to do?" << endl;
        cout << endl;

        cout << "1. Add a new book" << endl;
        cout << "2. View all books" << endl;
        cout << "3. View all available books" << endl;
        cout << "4. View all borrowed books" << endl;
        cout << "5. Borrow a book" << endl;
        cout << "6. Return a book" << endl;
        cout << "7. Remove a book from the shelves" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter a choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                addNewBook(books, count);
                break;
            }
            case 2:
            {
                viewBooks(books, count);
                break;
            }
            case 3:
            {
                
                cout << "=== All available books ===" << endl;
                for (int i = 0; i < count; i++)
                {
                    if (books[i].available)
                    {
                        cout << books[i].title << " by " << books[i].author << endl;
                        cout << endl;
                        availCount++;
                    }
                }

                if (availCount < 1)
                {
                    cout << "There are no books currently available" << endl;
                }
                
                break;
            }
            case 4:
            {
                
                cout << "=== All currently borrowed books ===" << endl;
                for (int i = 0; i < count; i++)
                {
                    if (!books[i].available)
                    {
                        cout << books[i].title << " by " << books[i].author << endl;
                        borrowedCount++;
                    }
                }

                if (borrowedCount < 1)
                {
                    cout << "No books are currently being borrowed" << endl;
                }
                break;
            }
            case 5:
            {
                borrowBook(books, count, borrowedCount, availCount);
                break;
            }
            case 6:
            {
                returnBook(books, count, availCount, borrowedCount);
                break;
            }
            case 7:
            {
                removeBook(books, count);
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

    } while (choice != 8);
    
    
    return 0;
}

