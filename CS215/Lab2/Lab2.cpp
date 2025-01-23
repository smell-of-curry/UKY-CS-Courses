#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// A base conversion of CAD to USD
const double CADToUSD = 0.69;

// Conversions for the amount of change type in 100 USD
const int QuartersInDollar = 25;
const int DimesInDollar = 10;
const int NickelsInDollar = 5;

int main()
{
    cout << "CAD -> USD Converter Service!" << endl;;
    cout << "Please enter the amount of Canadian Dollars you want to exchange:" << endl;;
    cout << "C$: ";

    // Prompt for amount of CAD and parse.
    string tmpstr;
    double CAD = 0;
    getline(cin, tmpstr);
    stringstream(tmpstr) >> CAD;
    if (CAD <= 0) {
        cerr << "Please ensure you have entered the correct amount, "<< CAD << " is invalid." << endl;
        return 1;
    }

    // Convert the Canadian amount to USD as a double.
    double USD = CAD * CADToUSD;

    // Convert to integer cents (rounding to nearest cent)
    // This is needed to prevent round off errors.
    int totalCents = static_cast<int>(round(USD * 100.0));

    // Now break down into dollars, quarters, dimes, nickels, pennies.
    const int dollars = totalCents / 100;
    int centsLeft = totalCents % 100;
    const int quarters = centsLeft / QuartersInDollar;
    centsLeft %= QuartersInDollar;
    const int dimes = centsLeft / DimesInDollar;
    centsLeft %= DimesInDollar;
    const int nickels = centsLeft / NickelsInDollar;
    centsLeft %= NickelsInDollar;
    const int pennies = centsLeft;

    // Display the change.
    cout << fixed << setprecision(2) << "\n";
    cout << "The exchange for " << CAD << " CAD is ~" << USD << " USD:\n";
    cout << "Dollar(s):\t" << dollars << "\n";
    cout << "Quarter(s):\t" << quarters << "\n";
    cout << "Dime(s):\t" << dimes << "\n";
    cout << "Nickel(s):\t" << nickels << "\n";
    cout << "Pennie(s):\t" << pennies << "\n";

    return 0;
}