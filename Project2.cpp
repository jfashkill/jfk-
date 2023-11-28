#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

// menu functions
void circleArea();
void taxCal();
void lb2kg();
void pause();
string getName();
// functions for taxCal()
float getPrice(), getTaxRate();
float calculateTax(float price, float taxr, float tax, string name);
// functions for circleArea()
float getRad(), calculateArea(float rad, float area, string name);
// functions for lb2kg()
float getLb(), calculateKg(float lb, float kg, string name);

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
            char pr;
            cin >> pr;

            if (tolower(pr) == 'y')
                break;
            system("clear");
            quit = true;

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
    // const float PI = 3.14159;
    int choice = 0;
    float rad = 0, area = 0;
    bool quit = false;

    // prompt for name
    string name = getName();

    // do while loop to stay or quit circle area.
    do
    {

        // set precision to round up.
        cout << fixed << setprecision(2);

        // this will prompt for the radius over and over to clear 0s and negative numbers
        float rad = getRad();
        float area = calculateArea(rad, area, name);

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

void taxCal()
{
    // call variables tax rate, price. also string for name. Bool to quit.
    int choice = 0;
    float taxr = 0, price = 0, tax = 0, taxA = 0;
    bool quit = false;

    // prompt for name
    string name = getName();
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
    int choice = 0;
    float lb = 0, kg = 0;
    bool quit = false;

    // prompt for name
    string name = getName();

    // do while loop to stay or quit.
    do
    {
        // set precision to round up.
        cout << fixed << setprecision(2);

        float lb = getLb();
        float kg = calculateKg(lb, kg, name);

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

void pause()
{
    std::cout << "Goodbye" << std::endl;

    // sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

string getName()
{
    string name;
    cout << "please enter your first name: ";
    cin >> name;
    cout << "\nhello " << name << endl;

    return name;
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

float getRad()
{
    float rad = 0;
    while (rad <= 0)
    {
        cout << "\nPlease enter the radius of your circle: ";
        while (!(cin >> rad) || rad <= 0) // filter strings and chars
        {
            cout << "\nError. Incorrect input. \nPrice cannot be negative or a string" << endl
                 << "\nPlease enter valid price: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    return rad;
}

float calculateArea(float rad, float area, string name)
{
    const float PI = 3.14159;
    area = PI * rad * rad;
    cout << " \n"
         << name << endl
         << "the area of your circle is " << area << endl;
    cout << " " << endl;
    return area;
}

float getLb()
{
    float lb = 0;
    while (lb <= 0)
    {
        cout << "\nPlease enter the weight in pounds/lb: ";
        while (!(cin >> lb) || lb <= 0) // filter strings and chars
        {
            cout << "\nError. Incorrect input. \nWeight cannot be negative or a string" << endl
                 << "\nPlease enter valid price: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    return lb;
}

float calculateKg(float lb, float kg, string name)
{
    const float lb2kg = 0.453592;
    kg = lb * lb2kg;

    cout << " \n"
         << name << endl
         << "Your weight in Kilograms is " << kg << endl;
    cout << " " << endl;
    return kg;
}