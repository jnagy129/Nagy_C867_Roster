//
// Created by Joshua Nagy on 1/27/20.
//

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

//------------------------------------------------constructor------------------------------------------------
    //no args constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < numDays; i++) {
    this->courseLength[i] = 0;
    }
}

    //overloaded constructors

Student::Student(string id, string firstName, string lastName, string email, int age, int courseLength[]) {
    this->studentID = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->courseLength = new int[3];
    for(int i = 0; i < 3; i++) {
        this->courseLength[i] = courseLength[i];
    }
}

//------------------------------------------------destructor------------------------------------------------

Student::~Student() {}

//------------------------------------------------getters------------------------------------------------
//pass data into protected class in student.h -> ref variables there

string Student::getStudentID() const {
    return this->studentID;  //this is pointer to an object w/in student
}
string Student::getFirstName() const {
    return this->firstName;
}
string Student::getLastName() const {
    return this->lastName;
}
string Student::getEmail() const {
    return this->email;
}
int Student::getAge() const {
    return this->age;
}
int* Student::getCourseLength() {
    return this->courseLength;
}
Degree Student::getDegreeProgram() {
    return this->degreeType;
}

//------------------------------------------------setters------------------------------------------------

void Student::setStudentID(string setID) {
    studentID = setID;
}
void Student::setFirstName(string setFName) {
   firstName = setFName;
}
void Student::setLastName(string setLName) {
   lastName = setLName;
}
void Student::setEmail(string setE) {
    email = setE;
}
void Student::setAge(int setA) {
    age = setA;
}

void Student::setCourseLength(int days[]) {
    for (int i = 0; i < numDays; ++i) {
        this->courseLength[i] = days[i];
    }
}
void Student::setDegreeType(Degree degreeType) {
    degreeType = degreeType;
}

//------------------------------------------------virtual print------------------------------------------------
void Student::print() {
  cout << "\nStudent ID: " << getStudentID();
  cout << "\nFirst Name: " << getFirstName();
  cout << "\nLast Name: " << getLastName();
  cout << "\nEmail: " << getEmail();
  cout << "\nAge: " << getAge();
cout << "\nCourse 1: " << getCourseLength()[0];
    cout << "\tCourse 2: " << getCourseLength()[1];
    cout << "\tCourse 3: " << getCourseLength()[2];
  cout << "\nDegree: ";
  if (getDegreeProgram() == Degree::SECURITY) {
      cout << "Security" << endl;
  } else if (getDegreeProgram() == Degree::NETWORKING) {
      cout << "Networking" << endl;
  } else if (getDegreeProgram() == Degree::SOFTWARE) {
      cout << "Software" << endl;
  } else {
      cout << "No Major Specified" << endl;
  }
}




