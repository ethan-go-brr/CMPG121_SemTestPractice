// this is for arrays, structs, and functions

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Car
{
    string make;
    string model;
    int year;
    double price;
};

Car makeVehicle(string make, string model, int year, double price)
{
    Car vehicle;

    vehicle.make = make;
    vehicle.model = model;
    vehicle.year = year;
    vehicle.price = price;

    return vehicle;

}

int findHighestPricedCar(Car vehicles[], int count)
{
    int highestIndex = 0;
    double highest = vehicles[0].price;
    for (int i = 0; i < count; i++)
    {
        if (vehicles[i].price > highest)
        {
            highest = vehicles[i].price;
            highestIndex = i;
        }
    }

    return highestIndex;
}

int findOldestCar(Car vehicles[], int count)
{
    int lowestIndex = 0;
    int lowestYear = vehicles[0].year;

    for (int i = 0; i < count; i++)
    {
        if (vehicles[i].year < lowestYear)
        {
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

void removeCar(Car vehicles[], int& count) // & allows this value of count to be used in the main() function
{
    if (count == 0)
    {
        cout << "There are no cars to delete!" << endl;
        return;
    }
    string search;
    bool found = false;
    cin.ignore();

    cout << "Enter model of the vehicle to delete: ";
    getline(cin, search);

    for (int i = 0; i < count; i++)
    {
        if (vehicles[i].model == search)
        {
            found = true;
            vehicles[i].make = vehicles[i + 1].make;
            vehicles[i].model = vehicles[i + 1].model;
            vehicles[i].year = vehicles[i + 1].year;
            vehicles[i].price = vehicles[i + 1].price;
            count--;
        }

    }

    if (!found)
    {
        cout << "Vehicle model not found" << endl;
    }
}

void displayCars(Car vehicles[], int count)
{
    cout << "Car list" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "Car #" << i + 1 << endl;
        cout << vehicles[i].make << " " << vehicles[i].model << endl;
        cout << "Year: " << vehicles[i].year << endl;
        cout << fixed << setprecision(2);
        cout << "Price: " << vehicles[i].price << endl;    
        cout << endl;
    }
}
int main()
{
    const int MAX_SIZE = 100;
    Car vehicles[MAX_SIZE];
    int choice;
    char option = 'n';
    //////////////////////////////
    double price;
    int year;
    string make, model;
    int count = 0;

    do
    {
        cout << "=== CAR DATABASE MENU ===" << endl;
        cout << "1. Add a new car" << endl;
        cout << "2. Find highest priced car" << endl;
        cout << "3. Find oldest car" << endl;
        cout << "4. Delete a car" << endl;
        cout << "5. Display all cars" << endl;
        cout << "6. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        

        switch (choice)
        {
            case 1:
            {

                if (count >= 100)
                {
                    cout << "Database is full, cannot add a new car" << endl;
                }
                do
                {
                    cout << "Add new vehicle:" << endl;
                    cin.ignore();
                    cout << "Enter the make of the vehicle: ";
                    getline(cin, make);

                    cout << "Enter the model of the vehicle: ";
                    getline(cin, model);

                    cout << "Enter the year of production: ";
                    cin >> year;

                    cout << "Enter the price of the vehicle: ";
                    cin >> price;
                    
                    vehicles[count] = makeVehicle(make, model, year, price);
                    count++;

                    cout << "Would you like to add another vehicle? (y/n): ";
                    cin >> option;

                } while (tolower(option) == 'y');
                
                break;
            }
            case 2:
            {
                int highestIndex;
                highestIndex = findHighestPricedCar(vehicles, count);

                cout << "=== THE MOST EXPENSIVE CAR ===" << endl;
                cout << "Make: " << vehicles[highestIndex].make << endl;
                cout << "Model: " << vehicles[highestIndex].model << endl;
                cout << "Year: " << vehicles[highestIndex].year << endl;
                cout << fixed << setprecision(2);
                cout << "Price: R" << vehicles[highestIndex].price << endl;

                break;
            }
            case 3:
            {
                int lowestIndex;
                lowestIndex = findOldestCar(vehicles, count);
                cout << "=== THE OLDEST CAR ===" << endl;
                cout << "Make: " << vehicles[lowestIndex].make << endl;
                cout << "Model: " << vehicles[lowestIndex].model << endl;
                cout << "Year: " << vehicles[lowestIndex].year << endl;
                cout << fixed << setprecision(2);
                cout << "Price: R" << vehicles[lowestIndex].price << endl;

                break;
            }
            case 4:
            {
                removeCar(vehicles, count);
                break;
            }
            case 5:
            {
                displayCars(vehicles, count);
                break;
            }
            case 6:
            {
                cout << "Goodbye!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter 1-6!" << endl;
                break;
            }
        }
        /* code */
    } while (choice != 6);
    
    return 0;
}