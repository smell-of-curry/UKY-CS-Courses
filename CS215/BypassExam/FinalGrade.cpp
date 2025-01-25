/*
 * File:   FinalGrade.cpp
 * Course: CS215
 * Project: Lab Exam
 * Purpose: provide the implementation of the member functions of the class named FinalGrade
 *
 *****PLEASE DO NOT CHANG THIS FILE*****
 *
 */
#include <iostream>
#include <iomanip>
#include "FinalGrade.h"

 // default constructor
FinalGrade::FinalGrade()
{
    // give initial value to be 0
    score = 0;
}

// constructor: give the initial value to the private data member score 
// to pass-in parameter in_score
FinalGrade::FinalGrade(double in_score)
{
    if (in_score < MIN_SCORE || in_score > MAX_SCORE)
        score = 0;
    else
        score = in_score;
}

// set the private data member: score
// to pass-in parameter in_score
void FinalGrade::setScore(double in_score)
{
    if (in_score < MIN_SCORE || in_score > MAX_SCORE)
        score = 0;
    else
        score = in_score;
}

// return the value of the data member: score
double FinalGrade::getScore() const
{
    return score;
}

// return the corresponding letter grade from score
// based on the grading policy in CS216 syllabus
char FinalGrade::decideLetterGrade() const
{
    char letterGrade;
    const int UNIT = 10;
    int range = static_cast<int> (score) / UNIT;
    switch (range)
    {
    case 9:
    case 10:    letterGrade = 'A';
        break;
    case 8:     letterGrade = 'B';
        break;
    case 7:     letterGrade = 'C';
        break;
    case 6:     letterGrade = 'D';
        break;
    default:    letterGrade = 'E';
        break;
    }
    return letterGrade;
}

// print the score and letter grade in the format: (for example)
// Score: 88        Letter Grade: B
void FinalGrade::print() const
{
    cout << "Score: " << fixed << setprecision(1) << setw(5) << score << "\t\tLetter Grade: " << this->decideLetterGrade() << endl;
}

