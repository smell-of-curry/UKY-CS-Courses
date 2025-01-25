/*
 * File:   FinalGrade.h
 * Course: CS215
 * Project: Lab Exam
 * Purpose: provide the declaration of the class named FinalGrade
 *
 *****PLEASE DO NOT CHANG THIS FILE*****
 *
 */

#ifndef FINALGRADE_H
#define FINALGRADE_H

using namespace std;

// define the valid score range [MIN_SCORE, MAX_SCORE]
const double MIN_SCORE = 0;
const double MAX_SCORE = 100;

class FinalGrade
{
public:
    // default constructor
    FinalGrade();

    // constructor: give the initial value to the private data member score 
    // to pass-in parameter in_score
    FinalGrade(double in_score);

    // set the private data member: score
    // to pass-in parameter in_score
    void setScore(double in_score);

    // return the value of the data member: score
    double getScore() const;

    // return the corresponding letter grade from score
    // based on the grading policy in CS216 syllabus
    char decideLetterGrade() const;

    // print the score and letter grade in the format: (for example)
    // Score: 88        Letter Grade: B
    void print() const;

private:
    double score;  // it represents the final score of a student
};

#endif /* FINALGRADE_H */ 
