#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct Attendee
{
    string name;
    string studentNo;
    char ticketType;
    bool checkedIn;
};

int findByStudentNo (Attendee att[], int numOfStudents, string studentNo)
{
    int index = 0;\
    bool found = false;
    for (int i = 0; i < numOfStudents; i++)
    {
        if (att[i].studentNo == studentNo)
        {
            index = i;
            found = true;
        }
    }

    if (found)
    {
        return index;
    }
    else
    {
        return -1;
    }
    
}

int registerAttendee(Attendee att[], int& numOfStudents)
{
    if (numOfStudents == 20)
    {
        return -1;
    }

    string studentNo;
    cout << "Enter student number (exactly 8 digits): ";
    cin >> studentNo;

    while (studentNo.length() != 8)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid. Student number must be exactly 8 digits. Try again: ";
        cin >> studentNo;
    }

    string name;
    cout << "Enter name: ";
    cin >> name;

    char ticket;
    cout << "Ticket type (G/V): ";
    cin >> ticket;

    while (ticket != 'G' || ticket != 'V')
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid ticket type. Enter G or V." << endl;
        cout << "Ticket type (G/V): ";
        cin >> ticket;
    }


    if(findByStudentNo(att, numOfStudents, studentNo) == -1)
    {
        att[numOfStudents].name = name;
        att[numOfStudents].studentNo = studentNo;
        att[numOfStudents].ticketType = ticket;
        att[numOfStudents].checkedIn = false;
        cout << "Registered successfully for " << att[numOfStudents].name << 
        " ("<< att[numOfStudents].ticketType << ")";
        numOfStudents++;
        
    }
    else
    {
        cout << "Registration failed (duplicate ID or full capacity)." << endl;
    }
}

void listAll(Attendee att[], int numOfStudents)
{
    if (numOfStudents < 0)
    {
        cout << "No attendees registered" << endl;
        return;
    }

    cout << "#" << left << setw(3) << "StudentNo" << setw(9) << setw(3) << "Name" << setw(15) << "Type" 
    << setw(5) << "CheckedIn" << setw(7) << endl;
    string checked;

    for (int i = 0; i < numOfStudents; i++)
    {
        if (att[numOfStudents].checkedIn == false)
        {
            checked = "No";
        }
        else
        {
            checked = "Yes";
        }

        cout << i + 1 << left << setw(3) << att[i].studentNo << setw(9) << setw(3) << att[i].name 
        << setw(15) << att[i].ticketType 
        << setw(5) << checked << setw(7) << endl;
    }
}

bool checkIn (Attendee att[], int numOfStudents)
{
    string studentNo;

    cout << "Enter student number to check in: ";
    cin >> studentNo;

    if (findByStudentNo(att, numOfStudents, studentNo) == -1)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < numOfStudents; i++)
        {
            if (att[i].studentNo == studentNo)
            {
                if (att[i].checkedIn == true)
                {
                    return false;
                }
            }
            else
            {
                att[i].checkedIn = true;
                return true;
            }
        }  
    }
}

string toLowerCopy(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}

void searchByName(Attendee att[], int numOfStudents)
{
    if (numOfStudents > 0)
    {
        cout << "No attendees registered" << endl;
        return;
    }

    string search;

    cout << "Enter part of name to search: ";
    cin >> search;

    string searchLow;
    searchLow = toLowerCopy(search);

    for (int i = 0; i < numOfStudents; i++)
    {
        
    }

}
void showMenu()
{
    int choice;

   
    do 
    {
        cout << "===== Campus Event Manager =====" << endl;
        cout << "1. Register Attendee" << endl;
        cout << "2. List all attendees" << endl;
        cout << "3. Check-in attendee" << endl;
        cout << "4. Search attendees by name" << endl;
        cout << "5. Remove attendee" << endl;
        cout << "6. Summary report" << endl;
        cout << "0. Exit" << endl;
        cout << "Select option: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Goodbye!" << endl;
            return;
        }

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
            default:
            {
                cout << "Invalid option." << endl;
                break;
            }
        }
    } while (choice != 0);
}

int main()
{
    Attendee att[20];
    int numOfAttendees = 0;
    showMenu();

}