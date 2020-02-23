#include "roster.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "student.h"
#include <iostream>
#include "degree.h"

using namespace std;

/////////////////////////        Functions      ////////////////////////


////no args constructor
Roster::Roster() {

}

////destuctor
Roster::~Roster() {
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] == nullptr) {
            delete classRosterArray[i];
        }
    }
}


////function to add student to classRosterArray and cat by degree subtype
void Roster::add(string id, string firstName, string lastName, string email, int age, int days1, int days2, int days3,
                 int degree) {
    int days[] = {days1, days2, days3};
    Student *student = nullptr;

    switch (degree) {
        case SOFTWARE:
            student = new SoftwareStudent(id, firstName, lastName, email, age, days);
            break;
        case SECURITY:
            student = new SecurityStudent(id, firstName, lastName, email, age, days);
            break;
        case NETWORKING:
            student = new NetworkStudent(id, firstName, lastName, email, age, days);
            break;
        default:
            cout << "You must declare a major" << endl;
            break;
    }

    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = student;
            break;
        }
    }
}


////function to remove student
void Roster::remove(string id) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getStudentID() == id) {
                cout << "Please wait, removing student..." << endl;
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
                found = true;
                cout << id << " removed successfully." << endl;
                break;
            }
        }
    }
    if (found)
        cout << "Sorry, " << id << " does not exist..." << endl;
    return;
}


////Function to Print All
void Roster::printAll() {
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }

}

////function to Print Average Days of courses
void Roster::printDaysInCourse() {
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] != nullptr) //not null
        {
            {
                int *days = classRosterArray[i]->getDays();
                int total = 0;
                for (int j = 0; j < 3; j++) {
                    total += *(days + j);
                }
                cout << classRosterArray[i]->getStudentID() << " has an average of " << (total / 3) << " days left."
                     << endl;
            }
        }
    }
}


////Printing invalid emails based on @, '.', and spaces....
void Roster::printInvalidEmails() {
    cout << "INVALID EMAILS: " << endl;
    for (int i = 0; i < size; i++) {
        string checkEmail = this->classRosterArray[i]->getEmailAddress();
        if (checkEmail.find(' ', 0) != string::npos) {
            cout << checkEmail << "\t Spaces are not permitted" << endl;
        } else if (checkEmail.find('.', 0) == string::npos) {
            cout << checkEmail << "\t You must have a period" << endl;
        } else if (checkEmail.find('@', 0) == string::npos) {
            cout << checkEmail << "\t You must have an '@' symbol" << endl;
        }
    }
}


////printing by degree -> instructions cite softwware
void Roster::printByDegreeProgram(int degree) {
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getDegreeProgram() == degree) {
                classRosterArray[i]->print();
            }
        }
    }

}

/////////////////////////       Main Program       ////////////////////////

int main() {
    ////DATA TO PASS INTO PROGRAM
    const string studentData[] =
            {
                    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                    "A5,Joshua,Nagy,jnagy9@wgu.edu,28,22,58,40,SOFTWARE"
            };

    //creates obj , to use in parsing
    string delimiter = ",";

    //creates obj classRoster of empty Roster class type
    Roster classRoster = Roster();

////Parsing DATA and populating classRosterArray
    for (int i = 0; i < 5; i++) {
        size_t lhs = 0;
        size_t rhs = 0;
        string sub;
        string studentTemp[9];
        int j = 0;
        Degree degree;

        while ((rhs = studentData[i].find(delimiter, lhs)) !=
               string::npos) //right hand size = dist lhs and delimiter comma
        {
            sub = studentData[i].substr(lhs, rhs - lhs);
            studentTemp[j] = sub;
            j++;
            lhs = rhs + 1;
        }

        studentTemp[8] = studentData[i].substr(lhs, studentData[i].length() - 1);

        if (studentTemp[8] == "SOFTWARE")
            degree = SOFTWARE;
        else if (studentTemp[8] == "NETWORK")
            degree = NETWORKING;
        else if (studentTemp[8] == "SECURITY")
            degree = SECURITY;

        //stoi -> string to integer
        classRoster.add(studentTemp[0], studentTemp[1], studentTemp[2], studentTemp[3], stoi(studentTemp[4]),
                        stoi(studentTemp[5]), stoi(studentTemp[6]), stoi(studentTemp[7]), degree);
    }

    ////personal info
    cout << "***************************************************************" << endl;
    cout << "******  WGU C867: Scripting and Programming Applications  *****" << endl;
    cout << "********  Written in C++  *************************************" << endl;
    cout << "********  By: Joshua NAGY\t Student ID No.: 000989389  ********" << endl;
    cout << "***************************************************************" << endl;

////Print All
    classRoster.printAll();
    cout << "***************************************************************" << endl;
    classRoster.printInvalidEmails();
    cout << "***************************************************************" << endl;

    classRoster.printDaysInCourse();
    cout << "***************************************************************" << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << "***************************************************************" << endl;

    classRoster.remove("A3");
    cout << "***************************************************************" << endl;

    classRoster.remove("A3");

    classRoster.~Roster();


    return 0;
}
