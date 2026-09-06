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

int registerAttendee(Attendee att[], int& numOfStudents, string studentNo, string name, char ticket)
{
    if (numOfStudents == 20)
    {
        return -1;
    }

    if(findByStudentNo(att, numOfStudents, studentNo) == -1)
    {
        att[numOfStudents].name = name;
        att[numOfStudents].studentNo = studentNo;
        att[numOfStudents].ticketType = ticket;
        att[numOfStudents].checkedIn = false;
        cout << "Registered successfully for " << att[numOfStudents].name << 
        " ("<< att[numOfStudents].ticketType << ")" << endl; // added endl;
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

bool checkIn (Attendee att[], int numOfStudents, string studentNo)
{
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
                if (att[i].checkedIn == false)
                {
                    att[i].checkedIn = true;
                    return true;
                    
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;

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

void searchByName(Attendee att[], int numOfStudents, string search)
{
    if (numOfStudents > 0)
    {
        cout << "No attendees registered" << endl;
        return;
    }
    bool found = false;
    string check;

    string searchLow;
    searchLow = toLowerCopy(search);

    string nameLow;
    cout << "Matches: " << endl;

    for (int i = 0; i < numOfStudents; i++)
    {
        nameLow = toLowerCopy(att[i].name);
        if (nameLow.find(searchLow) != -1)
        {
            found = true;
            if (att[i].checkedIn)
            {
                check = "Yes";
            }
            else
            {
                check = "No";
            }
            cout << att[i].studentNo << " | " << att[i].name << " | " <<
            att[i].ticketType << " | Checked-In: " << check << endl;
        }
    }

    if (!found)
    {
        cout << "No matches found" << endl;
    }

}
int removeAttendee(Attendee att[], int& numOfStudents, string studentNo)
{
    if (findByStudentNo(att, numOfStudents, studentNo) == -1)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < numOfStudents; i++)
        {
            att[i].name = att[i + 1].name;
            att[i].checkedIn = att[i + 1].checkedIn;
            att[i].studentNo = att[i + 1].studentNo;
            att[i].ticketType = att[i + 1].ticketType;

        }
        numOfStudents--;
    }
}
void summaryReport(Attendee att[], int numOfStudents)
{
    int gen = 0, vip = 0, checked = 0, non_checked = 0;
    for (int i = 0; i < numOfStudents; i++)
    {
        if (att[i].ticketType == 'G')
        {
            gen++;
        }
        else
        {
            vip++;
        }

        if(att[i].checkedIn)
        {
            checked++;
        }
        else
        {
            non_checked++;
      
        }
    }

    cout << "SUMMARY" << endl;
    cout << "Total registered: " << right << setw(20) << numOfStudents << "/20" << endl;
    cout << "Remaining seats: " << right << setw(20) << 20 - numOfStudents << endl;
    cout << "General (G): " << right << setw(20) << gen << endl;
    cout << "VIP (V): " << right << setw(20) << vip << endl;
    cout << "Checked-in: " << right << setw(20) << checked << endl;
    cout << "Non-checked-in:  " << right << setw(20) << non_checked << endl;

}
void showMenu(Attendee att[], int numOfStudents)
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

                while (ticket != 'G' && ticket != 'V') // changed from || to &&
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid ticket type. Enter G or V." << endl;
                    cout << "Ticket type (G/V): ";
                    cin >> ticket;
                }

                registerAttendee(att, numOfStudents, studentNo, name, ticket);
                break;
            }
            case 2:
            {
                listAll(att, numOfStudents);
                break;
            }
            case 3:
            {
                string studentNo;
                cout << "Enter student number to check in: ";
                cin >> studentNo;

                if(checkIn(att, numOfStudents, studentNo)) 
                {
                        cout << "Check-in successful" << endl;
                }
                else
                {
                        cout << "Check-in failed" << endl;
                }
                    break;
            }
            case 4:
            {
                string search;
                cout << "Enter part of name to search: ";
                cin >> search;
                searchByName(att, numOfStudents, search);
                break;
            }
            case 5:
            {
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

                if (removeAttendee(att, numOfStudents, studentNo) == -1)
                {
                    cout << "Attendee not found" << endl;
                }
                else
                {
                    cout << "Removed successfully" << endl;
                }
                break;
            }
            case 6:
            {
                summaryReport(att, numOfStudents);
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
    const int MAX_ATTENDEES = 20;
    Attendee att[MAX_ATTENDEES];
    int numOfAttendees = 0;
    showMenu(att, numOfAttendees);
}


/*
Bugs that I have so far:
Check in function does not update att.checkedIn
Literally most of the formatting
Counter for the students is a bit weird, this may be why checkIn doesn't work
search doesn't work, may also be due to the counter

What works:
Information in the summary
Listing the attendees
yeah :)
*/