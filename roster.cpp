#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "student.h"

using namespace std;

//data to pass into program
string const studentData[] =  {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Joshua,Nagy,jnagy9@wgu.edu,28,50,58,40,SOFTWARE"
};

string delimiter = ",";

//Function to remove students
void Roster::remove(string studentID) {
    cout << "Removing Student No.: " << studentID << flush;
    for (int i = 0; i < size; ++i) {
        if (classRosterArray[i] == nullptr) {
            cout << "I cannot find that student, please try again" << endl;
            break;
        } else if (studentID == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            cout << "Removal Successful!" << endl;
        }
    }
};

////Function to add students to roster
//void Roster::add(string studentID, string firstName, string lastName, string email, int age, int courseLength1,
//                 int courseLength2, int courseLength3, Degree degree) {
//    int courseLength[] = {courseLength1, courseLength2, courseLength3};
//    Student* student = nullptr;
//
//    switch (degree) {
//        case NETWORKING:
//            student = new networkStudent(studentID, firstName, lastName, email, age, courseLength, degree);
//            break;
//        case SECURITY:
//            student = new securityStudent(studentID, firstName, lastName, email, age, courseLength, degree);
//            break;
//        case SOFTWARE:
//            student = new softwareStudent(studentID, firstName, lastName, email, age, courseLength, degree);
//            break;
//    }
//
//    for (int i = 0; i < amtStudents; ++i) {
//        if (classRosterArray[i] == nullptr) {
//            classRosterArray[i] = student;
//            break;
//        }
//    }
//}

//Updating the classRosterArray

void Roster::add(string studentID, string firstName, string lastName,
                string email, int age, int courseLength1, int courseLength2, int courseLength3, Degree degreeType) {
    int toComplete[] = {courseLength1, courseLength2, courseLength3};
    Student *student = nullptr;

    switch (degreeType) {
        case SOFTWARE:
            student = new SoftwareStudent(studentID, firstName, lastName, email, age, toComplete);
            break;
        case SECURITY:
            student = new SecurityStudent(studentID, firstName, lastName, email, age, toComplete);
            break;
        case NETWORKING:
            student = new NetworkStudent(studentID, firstName, lastName, email, age, toComplete);
            break;
        default:
            cout << "ERROR: Could not create user." << endl;
            break;
    }
}



//Function to print all students
void Roster::printAll() {
    cout << "Displaying roster:" << '\n';
    cout << endl;
    for (int i = 0; i < size; i++) {
        (*classRosterArray[i]).print();
    }
    cout << '\n';
}

////Function to print average days
//void Roster::printAvgDaysInCourse(string studentID) {
//    for (int i = 0; i < amtStudents; ++i) {
//        if (studentID == *classRosterArray[i]->getStudentID()) {
//            const int *days = *classRosterArray[i]->getCourseLength();
//            int average = ((days[0] + days[1] + days[2]) / 3);
//            cout << studentID << ":\t" << average << " average days" << endl;
//
//        }
//    }
//};

void Roster::printDaysInCourse(string studentID) {
    for (int i = 0; i < size; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int avg = 0;
            avg = ((*classRosterArray[i]).getCourseLength()[0] + (*classRosterArray[i]).getCourseLength()[1]
                   + (*classRosterArray[i]).getCourseLength()[2]) / 3;
            cout << "The average days it took the student with studentID: " << studentID << " to finish 3 courses: " << avg << '\n';
        }
    }
    cout << '\n';
}


//Function for invalid email address finding
void Roster::printInvalidEmails() {
    for (int i = 0; i < size; i++) {
        bool validEmail = true;
        const string studentEmail = classRosterArray[i]->getEmail();
        if (studentEmail.find("@") == string::npos) {
            validEmail = false;
        }
        if (studentEmail.find(" . ") == string::npos) {
            validEmail = false;
        }
        if (studentEmail.find(" ") != string::npos) {
            validEmail = false;
        }
        if (validEmail != true) {
            cout << studentEmail << " is an invalid email address" << endl;
        }
    }
}

//Function to print by degree
void Roster::printByDegreeProgram(Degree degree) {
    for (int i = 0; i < size; ++i) {
        Student student = *classRosterArray[i];
        if (student.getDegreeProgram() == degree) {
            student.print();
        }
    }
};

//destructor
Roster::~Roster() {
}


int main() {

    Roster classRoster;
    Degree degree;


    //-----------intro-------------
    do {
        cout << '\n' << "Press Enter to continue...";
    } while (cin.get() != '\n');

    cout << "\n--------Scripting and Programming - Applications - C867-----------------" << endl;

    do {
        cout << '\n' << "Press Enter to continue...";
    } while (cin.get() != '\n');

    cout << "\n----------Written in C++ by Joshua Nagy - Student ID: 000989389-----------------" << endl;

    do {
        cout << '\n' << "Press Enter to continue...";
    } while (cin.get() != '\n');


     // adding each student to the classRoster
    for (int i = 0; i < 5; i++) {
        stringstream sInfo(studentData[i]);

        vector<string> result;

        while (sInfo.good()) {
            string substr;
            getline(sInfo, substr, ',');
            result.push_back(substr);
        }
        if (result[8] == "SECURITY") {
            degree = Degree::SECURITY;
        }
        if (result[8] == "SOFTWARE") {
            degree = Degree::SOFTWARE;
        }
        if (result[8] == "NETWORKING") {
            degree = Degree::NETWORKING;
        }
        classRoster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
                        stoi(result[6]), stoi(result[7]), degree);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printDaysInCourse("A3");
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    classRoster.~Roster();

    return 0;
}
