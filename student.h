//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_STUDENT_H
#define C867_STUDENT_H
#include <iostream>
#include "degree.h"
#include <string>
#include <vector>

using namespace std;

const static int numDays = 3;

class Student {
    public:
//-----------------------Constructors------------------------
    //no args constructor
    Student();

    // studentID, first name,  last name,  email, age, pointer to num days -> degree is a subclass
    Student(string, string, string, string , int, int days[]);


//-----------------------Destructor------------------------
    //flush data
    ~Student();
//------------------------accessor/getter for each instance variable------------------------
        string getStudentID() const;  //const after so no changes to variable
        string getFirstName() const;
        string getLastName() const;
        string getEmail() const;
        int getAge() const;
        int* getCourseLength();   //pointer to length of courses -> 3 courses
        Degree getDegreeType();

    //------------------------mutator/setter for each instance variable------------------------

        void setStudentID(string);
        void setFirstName(string);
        void setLastName(string);
        void setEmail(string);
        void setAge(int);
        void setCourseLength(int days[]);
        void setDegreeType(Degree);

    //------------------------virtual print() and getDegreeProgram------------------------
        virtual void print();
        virtual Degree getDegreeProgram();

protected:   //protected = accessible to subclass - degree is subclass - does degree need access??
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int* courseLength;   //array of # of days to complete three different courses using a pointer
    Degree degreeType;
};


#endif //C867_STUDENT_H
