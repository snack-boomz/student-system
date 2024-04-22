#include "student.h"

int Student::getStudentID()
{
    return studentID;
}

std::string Student::getFirstName()
{
    return studentFirstName;
}

std::string Student::getLastName()
{
    return studentFirstName;
}

std::string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return studentAge;
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