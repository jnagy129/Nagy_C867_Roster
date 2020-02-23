//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_STUDENT_H
#define C867_STUDENT_H
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:  //this is at top for visibility
    const static int numDays = 3;

protected:   //protected = accessible to subclass - degree is subclass - does degree need access??
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[numDays];   //array of # of days to complete three different courses using a pointer
    Degree dProgram;       //virtual methods imply this


public: //public = visible everywhere

//-----------------------Constructors------------------------
    Student(); //empty no args constructor
    // full constructor w/o degree bc subclass
    Student(string ID, string firstName, string lastName, string emailAddress, int age, const int days[]);

//------------------------accessor/getter for each instance variable------------------------
        string getStudentID();  //const after so no changes to variable
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getDays();   //pointer to length of courses -> 3 courses
        virtual Degree getDegreeProgram(); //virt bc cannot instantiate student obj

    //------------------------mutator/setter for each instance variable------------------------

        void setStudentID(string ID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDays(const int days[]);

    //------------------------virtual print() and getDegreeProgram------------------------
        virtual void print(); //display everything known about student obj except degree

    //-----------------------Destructor------------------------
    ~Student();
};

#endif //C867_STUDENT_H
