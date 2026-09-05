#include <string>
#include <iostream>

using namespace std;

int main()
{
    // basic string access
    string words = "Hello, world!";

    char word;
    word = words[0]; // getting an individual character

    cout << word << endl;

    words[2] = 'L'; // changing an individual character

    cout << words << endl;

    int num, num2;

    num = words.length();
    num2 = words.size(); // size and length both return the number of characters in the string (incl spaces)

    cout << num << " " << num2 << endl;
    /////////////////////////////////////////////////////////////
    // extracting/searching in strings

    string words2;
    int num3;

    words2 = words.substr(7, 6); // finds a substring within a string (starting index, number of characters to copy)
    cout << words2 << endl;

    num3 = words2.find('l'); // returns the position of the char in the string

    cout << num3 << endl;

    string words4;
    char search;

    cout << "Enter a word: ";
    cin >> words4;

    cout << "Enter a letter to search for in word: ";
    cin >> search;

    int pos = words4.find(search);

    if (pos == -1) // find returns -1 if there is no letter that matches
    {
        cout << "Letter not in word" << endl;
    }
    else
    {
        cout << "The letter " << search << " is at position " << pos + 1 << " in " << words4 << endl;
        cout << "The index is " << pos << endl;
    }
    ///////////////////////////////////////////////////////////////
    // modifying strings

    string inp;

    cin.ignore();
    cout << "Enter a greeting: ";
    cin >> inp;

    string inp2;

    cout << "Enter a name: ";
    cin >> inp2;

    string out;

    out = inp.append(inp2); // appends inp2 to inp

    cout << out << endl;


    string inp3;

    cout << "Enter a word: ";
    cin >> inp3;

    string out2;

    out2 = inp3.insert(2,3,'P'); // inserts at index 2, 3 P's (EISH = EIPPPSH)
    cout << out2 << endl;

    out2 = inp3.erase(2,3); //begin and end pos to erase (i think it starts at 2 and erases 3 chars)
    cout << out2 << endl;

    //////////////////////////////////////////////////////////
}  