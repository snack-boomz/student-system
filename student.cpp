#include "student.h"

Student::Student()
{
    // ints and strings below to be filled out later
    studentID = -1;
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
    std::cout << getStudentID(); + "\t";
    std::cout << "First Name: " + getFirstName(); + "\t";
    std::cout << "Last Name: " + getLastName(); + "\t";
    std::cout << "Email Address: " + getEmailAddress(); + "\t";
    std::cout << "Age: " + getAge(); + "\t";
    std::cout << "daysinCourse: [";
    auto size = getNumDaysCompleteCourse().size();
    auto a = getNumDaysCompleteCourse();
    for (int i = 0; i < size; i++) std::cout << a.at(i);
    std::cout << "]\t";
    std::string degreeProgramString = "";
    switch (getDegreeProgram())
    {
        case '0':
            degreeProgramString = "SECURITY";
        case '1':
            degreeProgramString = "NETWORK";
        case '2':
            degreeProgramString = "SOFTWARE";
        default:
            degreeProgramString = "INVALID";
    }
    std::cout << "Degree Program: " + degreeProgramString; + "\t";
}

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

std::array<int, 3> Student::getNumDaysCompleteCourse()
{
    return numDaysCompleteCourse;
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

void Student::setNumDaysCompleteCourse(std::array<int, 3> numDaysToCompleteCourseArray)
{
    numDaysCompleteCourse = numDaysToCompleteCourseArray;
}

void Student::setDegreeProgram(DegreeProgram degreeProgramVal)
{
    degreeProgram = degreeProgramVal;
}