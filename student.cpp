#include "student.h"

Student::Student()
{
    // ints and strings below to be filled out later
    studentID = "A0";
    studentFirstName = "TBD";
    studentLastName = "TBD";
    emailAddress = "TBD@domain.com";
    studentAge = -1; 
    std::array<int, 3> placeholder;
    numDaysCompleteCourse = placeholder; // empty 
    degreeProgram = SECURITY; // default to SECURITY
}

void Student::printStudentData()
{
    std::cout << getStudentID() + "\t"
    + std::string("First Name: ") + getFirstName() + "\t"
    + std::string("Last Name: ") + getLastName() + "\t"
    + std::string("Email Address: ") + getEmailAddress() + "\t"
    + std::string("Age: ") + std::to_string(getAge()) + "\t"
    + std::string("daysinCourse: { ");

    int size = getNumDaysCompleteCourse().size();
    std::array<int, 3> a = getNumDaysCompleteCourse();
    for (int i = 0; i < size; i++) std::cout << ((i != size - 1) ? std::to_string(a.at(i)) + "," : std::to_string(a.at(i)));
    std::cout << " }\t";
    std::string degreeProgramString = "";
    switch (getDegreeProgram())
    {
        case SECURITY:
            degreeProgramString = "SECURITY";
        case NETWORK:
            degreeProgramString = "NETWORK";
        case SOFTWARE:
            degreeProgramString = "SOFTWARE";
        default:
            degreeProgramString = "INVALID";
    }
    std::cout << std::string("Degree Program: ") + degreeProgramString + "\n";
}

std::string Student::getStudentID()
{
    return studentID;
}

std::string Student::getFirstName()
{
    return studentFirstName;
}

std::string Student::getLastName()
{
    return studentLastName;
}

std::string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return studentAge;
}

std::array<int, 3> Student::getNumDaysCompleteCourse()
{
    return numDaysCompleteCourse;
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

void Student::setStudentID(std::string id)
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

void Student::setNumDaysCompleteCourse(std::array<int, 3> numDaysToCompleteCourseArray)
{
    numDaysCompleteCourse = numDaysToCompleteCourseArray;
}

void Student::setDegreeProgram(int degreeProgramVal)
{
    switch (degreeProgramVal)
    {
        case 0:
            degreeProgram = SECURITY;
        case 1:
            degreeProgram = NETWORK;
        case 2:
            degreeProgram = SOFTWARE;

    }

}