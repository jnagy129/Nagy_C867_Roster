//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_SECURITYSTUDENT_H
#define C867_SECURITYSTUDENT_H

#include "student.h"
#include "degree.h"

// here, securityStudent is a subclass of Student; class = child; public = parent
class SecurityStudent: public Student {
    public:
        using Student::Student; //inheritance constructor
        Degree getDegreeProgram() override;

protected:
    Degree degreeType = SECURITY;
};



#endif //C867_SECURITYSTUDENT_H
