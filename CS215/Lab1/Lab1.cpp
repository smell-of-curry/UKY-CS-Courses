#include <iostream>
#include <cmath>

using namespace std;

// The name of the TA
const string TAName = "Bipin";

// The name of the user
const string yourName = "Ean Lowell";

// 1 hour = 60 minutes
const int HOUR_TO_MIN = 60;

// 1 minute = 60 seconds
const int MIN_TO_SEC = 60;

/*
* Prints a snowman onto the screen.
*/
static void printSnowman() {
    cout << R"(
    Let it Snow!
    *  *  * *  *
   * *   *   *  *
    * *   *  * *
    *    *   *  *

       _===_
      /     \
     /  O O  \
    (    >    )
     \_______/
      /     \
     /       \
    /_________\
     (       )
    (         )
     (_______)
    )" << endl;
}

int main()
{
    // Introduction
    cout << "Hi " << TAName << ",\n";
    cout << "I am glad you are my TA.\n";
    cout << "My name is " << yourName << ". Nice to meet you!" << endl;

    printSnowman();

    // Ask about courses
    int courses = 0;
    cout << "Its a snow day!\n";
    cout << "How many courses do you have today?" << endl;

    // Input validation loop for courses
    while (true) {
        double tempCourses; // Use a temporary variable for validation
        cin >> tempCourses;

        // Check if the input is an integer
        if (cin.fail() || tempCourses != floor(tempCourses) || tempCourses < 0) {
            cout << "Please enter a valid whole number for courses: ";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            courses = static_cast<int>(tempCourses); // Safe conversion
            break;
        }
    }
    cout << "Enjoy your " << courses << " course(s)!\n" << endl;

    // Ask about hours on CS215
    double hours = 0;
    cout << "How many hours are you going to spend on CS215 every week?" << endl;

    // Input validation loop for hours
    while (true) {
        double tempHours; // Use a temporary variable for validation
        cin >> tempHours;

        // Check if the input is a non-negative double
        if (cin.fail() || tempHours < 0) {
            cout << "Please enter a valid number for hours: ";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            hours = static_cast<double>(tempHours); // Direct assignment since hours can be fractional
            break;
        }
    }

    // Calculate and display seconds.
    double seconds = hours * HOUR_TO_MIN * MIN_TO_SEC;
    cout << "Good Luck! You will spend about " << seconds << " seconds each week on CS215." << endl;

    return 0;
}