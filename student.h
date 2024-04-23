#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <array>
#include "degree.h"

class Student
{
    public:
        int getStudentID();
        std::string getFirstName();
        std::string getLastName();
        std::string getEmailAddress();
        int getAge();
        std::array<int, 3> getNumDaysCompleteCourse();
        DegreeProgram getDegreeProgram();

        void setStudentID(int id);
        void setFirstName(std::string f_name);
        void setLastName(std::string l_name);
        void setEmailAddress(std::string address);
        void setAge(int age);
        void setNumDaysCompleteCourse(std::array<int, 3> numDaysToCompleteCourseArray);
        void setDegreeProgram(DegreeProgram degreeProgramVal);
        void Student::printStudentData();

    private:
        int studentID;
        std::string studentFirstName;
        std::string studentLastName;
        std::string emailAddress;
        int studentAge;
        std::array<int, 3> numDaysCompleteCourse;
        DegreeProgram degreeProgram;
        
};

#endif