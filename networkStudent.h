//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_NETWORKSTUDENT_H
#define C867_NETWORKSTUDENT_H
#include "student.h"
#include "degree.h"

using namespace std;

class NetworkStudent : public Student
{
public:
    using Student::Student;
    Degree getDegreeProgram() override;

protected:
    Degree degree = NETWORKING;
};

#endif //C867_NETWORKSTUDENT_H
