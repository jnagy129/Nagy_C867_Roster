//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_SECURITYSTUDENT_H
#define C867_SECURITYSTUDENT_H

#include "student.h"
#include "degree.h"

class SecurityStudent : public Student
{
public:
    using Student::Student;
    Degree getDegreeProgram() override;

protected:
    Degree degree = SECURITY;
};


#endif //C867_SECURITYSTUDENT_H
