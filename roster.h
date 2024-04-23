#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include <array>
#include "degree.h"

class Student
{
    public:
        void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void remove(std::string studentID);
        void printAll()
    private:
        std::array<int*, 5> classRosterArray;
        
};

#endif