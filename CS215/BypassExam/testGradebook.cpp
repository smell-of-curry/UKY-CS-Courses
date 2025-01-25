/*
 *Course: CS215
 *Project: CS215 Bypass Exam Part 2
 *Purpose: to test if the definition of the class, named Gradebook, is correct.
 *         it provides TWO testing cases: Midterm Exam gradebook and Final Exam gradebook
 *         For Midterm Exam gradebook: the scores are "hard-coded", for testing purpose
 *         For Final Exam gradebook: each score is from user input
 *         each student's score is at the range [0,100]
 *         Then display the scores in each gradebook, the number of scores, the highest and lowest scores, and the average
 *
 */

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <limits>       // define numeric_limits
#include <string>
#include "Gradebook.h"

using namespace std;

int main()
{
    // create a static array for testing purpose only
    // the scores in the array are "hard-coded"
    const int SIZE = 7;
    double MidtermG[SIZE] = { 98.5, 76, 80.5, 69.5, 87, 92.5, 57 };

    Gradebook Midterm_gradebook, Final_gradebook;

    for (int i = 0; i < SIZE; i++)
    {
        FinalGrade stu_FG(MidtermG[i]);
        Midterm_gradebook.insert(stu_FG);
    }

    // Display each FinalGrade object in the gradebook, the number of socres, the highest and lowest scores and the average score
    cout << "The gradebook for CS216 Midterm Exam: " << endl;
    Midterm_gradebook.print();
    cout << "The number of scores is:\t" << Midterm_gradebook.getSize() << endl;
    cout << endl << "The maximum score is:" << endl;
    Midterm_gradebook.getMax().print();
    cout << endl << "The minimum score is:" << endl;
    Midterm_gradebook.getMin().print();
    cout << fixed << setprecision(2);
    cout << endl << "The average score for CS216 Midterm is:\t" << Midterm_gradebook.getAverage() << endl << endl;

    double input_score;

    while (true)
    {
        cout << "Please enter a score for CS216 Final Exam(type 'Q' or 'q' to quit): " << endl;
        cin >> input_score;

        // check if the user input is invalid
        if (cin.fail())
        {
            string check_input;
            cin.clear();
            cin >> check_input;
            if (check_input == "Q" || check_input == "q")
                break;
            else {
                cout << "Invalid input, please try again..." << endl;
                continue;
            }
        }

        // check if the input score is in the correct range: [0,100]
        if (input_score < 0 || input_score > 100)
        {
            cout << "The score is not in the correct range, please try again..." << endl;
        }
        else  // valid user input, create a FinalGrade object, then store into Gradebook object
        {
            FinalGrade input_FG(input_score);
            Final_gradebook.insert(input_FG);
        }

        cin.ignore(numeric_limits<int>::max(), '\n'); //extra and ignore any bad input from input stream
    }

    // Your code starts here...
    // check if the gradebook is empty
    if (Final_gradebook.getSize() == 0) {
        cout << "The gradebook is Empty!" << endl << endl;
    }
    else {
        // if the gradebook is not empty
        // Display each FinalGrade object in the gradebook, the number of socres, the highest and lowest scores and the average score

        cout << "The gradebook for CS216 Final Exam: " << endl;
        Final_gradebook.print();
        cout << "The number of scores is:\t" << Final_gradebook.getSize() << endl;
        cout << endl << "The maximum score is:" << endl;
        Final_gradebook.getMax().print();
        cout << endl << "The minimum score is:" << endl;
        Final_gradebook.getMin().print();
        cout << fixed << setprecision(2);
        cout << endl << "The average score for CS215 Final Exam is:\t" << Final_gradebook.getAverage() << endl << endl;
    }

    cout << "Thank you for using the Gradebook Calculator." << endl;

    return 0;
}