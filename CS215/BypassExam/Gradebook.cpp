/*
 * File:   Gradebook.cpp
 * Course: CS215
 * Project: Lab Exam
 * Purpose: provide the implementation of the member functions of the class named FinalGrade
 *
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include "FinalGrade.h"
#include "Gradebook.h"

using namespace std;

// default constructor
Gradebook::Gradebook()
{
    // The scores in the grade book
    scores = {};
}

int Gradebook::getSize() const {
    return scores.size();
}

void Gradebook::insert(FinalGrade newFG) {
    scores.push_back(newFG);
}

FinalGrade Gradebook::getMax() const {
    // Set Max as first score
    FinalGrade max = scores.front();

    for (FinalGrade fg : scores) {
        if (fg.getScore() > max.getScore()) {
            max = fg;
        }
    }

    return max;
}

FinalGrade Gradebook::getMin() const {
    // Set Min as first score
    FinalGrade min = scores.front();

    for (FinalGrade fg : scores) {
        if (fg.getScore() < min.getScore()) {
            min = fg;
        }
    }

    return min;
}

double Gradebook::getAverage() const {
    double sum = 0;

    for (FinalGrade fg : scores) {
        double score = fg.getScore();
        sum += score;
    }

    return sum / scores.size();
}

// print the score and letter grade in the format: (for example)
// Score: 88        Letter Grade: B
void Gradebook::print() const
{
    for (FinalGrade fg : scores) {
        fg.print();
    }
}