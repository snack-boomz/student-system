#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "degree.h"

class Student
{
    public:
        int getStudentID();
        std::string getFirstName();
        std::string getLastName();
        std::string getEmailAddress();
        int getAge();
        std::vector<int> getNumDaysCompleteCourse();
        DegreeProgram getDegreeProgram();

        void setStudentID(int id);
        void setFirstName(std::string f_name);
        void setLastName(std::string l_name);
        void setEmailAddress(std::string address);
        void setAge(int age);
        void setNumDaysCompleteCourse(std::vector<int> numDaysToCompleteCourseVector);
        void setDegreeProgram(DegreeProgram degreeProgramVal);

    private:
        int studentID;
        std::string studentFirstName;
        std::string studentLastName;
        std::string emailAddress;
        int studentAge;
        std::vector<int> numDaysCompleteCourse;
        DegreeProgram degreeProgram;
        
};

#endif