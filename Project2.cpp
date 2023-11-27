#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

// define functions
void circleArea();
void taxCal();
void lb2kg();
void pause();
float getPrice();
float getTaxRate();
float calculateTax(float price, float taxr, float tax, string name);

int main()
{
    // bool to quit or stay. int for the choices of the menu.
    bool quit = false;
    int choice = 0;

    do // do while loop to keep menu up unless user quits.
    {
        // promt menu
        cout << "\nWelcome, please choose an option(1-4)" << endl;
        cout << "\n1) Calculate the area of a circle" << endl;
        cout << "2) Calculate the tax based on an item's price" << endl;
        cout << "3) Convert pound to kilogram" << endl;
        cout << "4) Quit" << endl;

        // filter strings and chars from int.
        while (!(cin >> choice) || choice <= 0 || choice >= 5)
        {
            cout << "\nError: Incorrect input. \nChoice is not in range 1-4. " << endl
                 << "\nplease enter choices (1-4): ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        // switch loop for choices
        switch (choice)
        {
            char pr;

        case 1: // runs area of a circle
            circleArea();
            break;

        case 2:
            taxCal();
            break;

        case 3:
            lb2kg();
            break;

        case 4:
            system("clear");
            cout << "Press Y to repeat the program" << endl;
            cout << "Any other input will terminate" << endl;
            cin >> pr;
            if (tolower(pr) != 'y')
            {
                system("clear");
                quit = true;
            }
            else
                break;

        default:
            pause();
            system("clear");
        }

    } while (!quit);

    return 0;
}

void circleArea()
{
    // call variables pi, radius, and area. also string for name. Bool to quit.
    const float PI = 3.14159;
    string name;
    int choice = 0;
    double rad = 0, area = 0;
    bool quit = false;

    // prompt for name
    cout << "please enter your first name: ";
    cin >> name;
    cout << "\nhello " << name << endl;

    // do while loop to stay or quit circle area.
    do
    {

        // set precision to round up.
        cout << fixed << setprecision(2);

        // this will prompt for the radius over and over to clear 0s and negative numbers
        while (rad <= 0)
        {

            cout << "\nPlease enter the radius of your circle: ";

            while (!(cin >> rad) || rad <= 0) // filter strings and chars
            {
                cout << "\nError. Incorrect input. \nChoice is not in range 1-2." << endl
                     << "\nPlease enter radius of circle: ";
                cin.clear();
                cin.ignore(123, '\n');
            }

            // calculate the area and print answer.
            area += PI * (rad * rad);

            cout << " \n"
                 << name << endl
                 << "the area of your circle is " << area << endl;
            cout << " " << endl;

            // promt to stay or leave
            cout << "1) To calculate again." << endl;
            cout << "2) To exit." << endl;
        }

        while (!(cin >> choice) || choice <= 0 || choice >= 3) // filter strings and chars
        {
            cout << "\nError: Incorrect input. \nChoice is not in range 1-2" << endl
                 << "\nplease enter choices (1-2): ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        switch (choice) // exit or stay
        {
        case 1:

            area = 0;
            rad = 0;
            break;

        case 2:
            cout << "Goodbye" << endl;
            system("clear");
            quit = true;
        }

    } while (!quit);
}

void taxCal()
{
    // call variables tax rate, price. also string for name. Bool to quit.
    string name;
    int choice = 0;
    double taxr = 0, price = 0, tax = 0, taxA = 0;
    bool quit = false;

    // prompt for name
    cout << "please enter your first name: ";
    cin >> name;
    cout << "\nhello " << name << endl;

    // do while loop to stay or quit circle area.
    do
    {
        // set precision to round up.
        cout << fixed << setprecision(2);

        
        float price = getPrice();
        float taxr = getTaxRate();
        float taxAmount = calculateTax(price, taxr, tax, name);


        // promt to stay or leave
        cout << "1) To calculate again." << endl;
        cout << "2) To exit." << endl;

        while (!(cin >> choice) || choice <= 0 || choice >= 3) // filter strings and chars
        {
            cout << "\nError: Incorrect input. \nChoice is not in range 1-2" << endl
                 << "\nplease enter choices (1-2): ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        if (choice == 2)
        {
            cout << "Goodbye" << endl;
            system("clear");
            quit = true;
        }

    } while (!quit);
}

void lb2kg()
{
    // call variables lb2kg for conversion, lb, and kg. also string for name. Bool to quit.
    const float lb2kg = 0.453592;
    string name;
    int choice = 0;
    double lb = 0, kg = 0;
    bool quit = false;

    // prompt for name
    cout << "please enter your first name: ";
    cin >> name;
    cout << "\nhello " << name << endl;

    // do while loop to stay or quit.
    do
    {

        // set precision to round up.
        cout << fixed << setprecision(2);

        // this will prompt for the weight over and over to clear 0s and negative numbers
        while (lb <= 0)
        {

            cout << "\nPlease enter the weight in pounds/lb: ";

            while (!(cin >> lb) || lb <= 0) // filter strings and chars
            {
                cout << "\nError" << endl
                     << "\nPlease enter the weight in pounds/lb: ";
                cin.clear();
                cin.ignore(123, '\n');
            }

            // calculate the area and print answer.
            kg += lb * lb2kg;

            cout << " \n"
                 << name << endl
                 << "Your weight in Kilograms is " << kg << endl;
            cout << " " << endl;

            // promt to stay or leave
            cout << "1) To calculate again." << endl;
            cout << "2) To exit." << endl;
        }

        while (!(cin >> choice) || choice <= 0 || choice >= 3) // filter strings and chars
        {
            cout << "\nError" << endl
                 << "\nplease enter choices (1-2): ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        switch (choice) // exit or stay
        {
        case 1:
            lb = 0;
            kg = 0;
            break;

        case 2:
            cout << "Goodbye" << endl;
            system("clear");
            quit = true;
        }

    } while (!quit);
}

void pause()
{
    std::cout << "Goodbye" << std::endl;

    // sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

float getPrice()
{
    float price = 0;
    while (price <= 0)
    {
        cout << "\nPlease enter the total Price of your item: ";
        while (!(cin >> price) || price <= 0) // filter strings and chars
        {
            cout << "\nError. Incorrect input. \nPrice cannot be negative or a string" << endl
                 << "\nPlease enter valid price: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    return price;
}

float getTaxRate()
{
    float taxr = 0;

    while (taxr <= 0)
    {
        cout << "\nPlease enter the tax rate: ";

        while (!(cin >> taxr) || taxr <= 0) // filter strings and chars
        {
            cout << "\nError. Incorrect input. \ntax cannot be negative or a string" << endl
                 << "\nPlease enter valid tax rate: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    return taxr;
}

float calculateTax(float price, float taxr, float tax, string name)
{

    tax += (taxr * price) / 100;
    cout << " \n"
         << name << endl
         << "the tax amount is: $" << tax << endl;
    cout << " " << endl;

    return tax;
}