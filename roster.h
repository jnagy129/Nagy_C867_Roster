//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_ROSTER_H
#define C867_ROSTER_H
#pragma once
#include "student.h"
#include <string>

class Roster
{


private:
    int size = 5;
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:
    Roster();

    void add(string studentID, string firstName, string lastName, string email,int age, int days1, int days2, int days3, int degree);
    void remove(string studentID);
    void printAll();
    void printDaysInCourse();
    void printInvalidEmails();
    void printByDegreeProgram(int degree);
    ~Roster();

};
#endif //C867_ROSTER_H
