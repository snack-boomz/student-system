#include <iostream>
#include "roster.h"

using namespace std;


int main(void)
{
    cout << "hello world!\n";

    Roster* r = new Roster();
    r->printAll();
    r->add("A6", "Trey", "A", "email@cdomain.com", 10, 2, 2, 2, SECURITY);
    r->printAll();


    return 0;
}