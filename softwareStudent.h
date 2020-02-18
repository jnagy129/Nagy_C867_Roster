//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_SOFTWARESTUDENT_H
#define C867_SOFTWARESTUDENT_H
#include "student.h"
#include "degree.h"

// here, softwareStudent is a subclass of Student; class = child; public = parent
class SoftwareStudent: public Student {

public:
    using Student::Student; //inheritance constructor
     Degree getDegreeProgram() override;

protected:

    Degree degreeType = SOFTWARE;
};

#endif //C867_SOFTWARESTUDENT_H
