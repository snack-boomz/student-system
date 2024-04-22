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

int Student::getStudentID()
{
    return studentID;
}

std::string Student::getFirstName()
{
    return firstName;
}

std::string Student::getLastName()
{
    return lastName;
}

std::string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

void Student::setStudentID(int id)
{
    studentID = id;
}

void Student::setFirstName(std::string firstName)
{
    studentFirstName = firstName;
}

void Student::setLastName(std::string lastName)
{
    studentLastName = lastName;
}

void Student::setEmailAddress(std::string address)
{
    emailAddress = address;
}

void Student::setAge(int age)
{
    studentAge = age;
}

void Student::setNumDaysCompleteCourse(std::vector<int> numDaysToCompleteCourseVector)
{
    numDaysCompleteCourse = numDaysToCompleteCourseVector;
}

void Student::setDegreeProgram(DegreeProgram degreeProgramVal)
{
    degreeProgram = degreeProgramVal;
}

#endif