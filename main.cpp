#include <iostream>
#include "roster.h"

using namespace std;


int main(void)
{
    cout << "hello world!\n";

    Roster* classRoster = new Roster();
    // classRoster->printAll();
    classRoster->add("A6", "Trey", "A", "email@cdomain.com", 10, 2, 2, 2, SECURITY);
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printInvalidEmails();
    classRoster->printAll();


    return 0;
}