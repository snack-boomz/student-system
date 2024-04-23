#include <iostream>
#include "roster.h"

using namespace std;


int main(void)
{
    cout << "hello world!\n";
    
    Roster* r = new Roster();
    cout << "roster built. printing all things\n";
    r->printAll();


    return 0;
}