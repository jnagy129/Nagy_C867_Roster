//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_SOFTWARESTUDENT_H
#define C867_SOFTWARESTUDENT_H

#include "student.h"
#include "degree.h"

using namespace std;

class SoftwareStudent : public Student
{
public:
    using Student::Student;
    Degree getDegreeProgram() override;

protected:
    Degree degree = SOFTWARE;
};

#endif //C867_SOFTWARESTUDENT_H
