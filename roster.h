//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_ROSTER_H
#define C867_ROSTER_H
#include <string>
#include <list>
#include <cstdio>
#include "student.h"
#include "degree.h"
#pragma once

using std::string;

using namespace std;


//create class
class Roster {

private:

    int size = 5;
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:

    Roster();
    Roster(int size);

    void add(string studentID, string firstName, string lastName, string email, int age, int courseLength1, int courseLength2, int courseLength3, Degree degreeType);
    void remove(string studentID);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degreeType);

    ~Roster();
};

#endif //C867_ROSTER_H
