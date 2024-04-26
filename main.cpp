#include <iostream>
#include "roster.h"

using namespace std;


int main(void)
{
    std::cout << "Scripting and Programming - Applications - C867 | C++ | 008512485 | Trey Annis" << std::endl;
    
    Roster* classRoster = new Roster();
    classRoster->printAll();
    classRoster->printInvalidEmails();
    Student** classRosterArray = classRoster->getClassRosterArray();
    int curr_r_size = classRoster->getRosterSize();

    for (int i = 0; i < curr_r_size; i++)
    {
        classRoster->printAverageDaysInCourse(classRosterArray[i]->getStudentID());
    }
    
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");

    delete classRoster;
    classRoster = nullptr;


    return 0;
}