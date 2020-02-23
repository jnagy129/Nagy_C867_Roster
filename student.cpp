//
// Created by Joshua Nagy on 1/27/20.
//

#include "student.h"
#include <iostream>
#include <string>
#include <utility>
using std::string;
using namespace std;

//------------------------------------------------constructor------------------------------------------------
    //no args constructor
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int & day : this->days) {day = 0;}
}

    //overloaded constructors
Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, const int days[])
{
    this->studentID = std::move(ID);
    this->firstName = std::move(firstName);
    this->lastName = std::move(lastName);
    this->emailAddress = std::move(emailAddress);
    this->age = age;
    for(int i = 0; i < numDays; i++) this->days[i] = days[i];
}

//------------------------------------------------getters------------------------------------------------
//pass data into protected class in student.h -> ref variables there

string Student::getStudentID()
{
    return studentID;  //this is pointer to an object w/in student
}
string Student::getFirstName()
{
    return firstName;
}
string Student::getLastName()
{
    return lastName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
int Student::getAge()
{
    return age;
}
int* Student::getDays()
{
    return days;
}
Degree Student::getDegreeProgram()
{
    return dProgram;
}

//------------------------------------------------setters------------------------------------------------
void Student::setStudentID(string ID)
{
    this->studentID = std::move(ID);
}
void Student::setFirstName(string firstName)
{
   this->firstName = std::move(firstName);
}
void Student::setLastName(string lastName)
{
   this->lastName = std::move(lastName);
}
void Student::setEmailAddress(string email)
{
    this->emailAddress = std::move(email);
}
void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDays(const int days[])
{
    for (int i = 0; i < numDays; i++)
        this->days[i] = days[i];
}

//------------------------------------------------virtual print------------------------------------------------
//  child - will call degree type
void Student::print()
{
  cout << studentID << "\t";
  cout <<  "First Name: " << firstName << "\t";
  cout << "Last Name: " << lastName << "\t";
  cout << "Age: " << age << "\t";
  cout << "Days in Course(s): {" << days[0] << " , " << days[1] << " , " << days[2] << "} ";
  cout << "\tDegree: ";

    switch (getDegreeProgram())
    {
        case SOFTWARE:
            cout << "SOFTWARE";
            break;
        case NETWORKING:
            cout << "NETWORK";
            break;
        case SECURITY:
            cout << "SECURITY";
            break;
        default:
            cout << "Not Major Declared";
            break;
    }

    cout << endl;
}

//------------------------------------------------destructor------------------------------------------------
Student::~Student()
= default;
