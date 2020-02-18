//
// Created by Joshua Nagy on 1/27/20.
//

#ifndef C867_NETWORKSTUDENT_H
#define C867_NETWORKSTUDENT_H
#include "student.h"


// here, networkStudent is a subclass of Student; class = child; public = parent
class NetworkStudent: public Student {
public:
    using Student::Student; //inheritance constructor
    Degree getDegreeProgram() override;

protected:
    Degree degreeType = NETWORKING;
};

#endif //C867_NETWORKSTUDENT_H
