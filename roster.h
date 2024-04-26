#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include "student.h"


class Roster
{
    public:
        Roster();
        ~Roster();
        Student** getClassRosterArray();
        int getRosterSize();
        void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void remove(std::string studentID);
        void printAll();
        void printAverageDaysInCourse(std::string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
    private:
        Student** classRosterArray;
        int rosterSize;

};

#endif