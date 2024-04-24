#include "roster.h"

Roster::Roster()
{
    const std::string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Trey,Annis,rannis1@my.wgu.edu,25,8,90,3,SOFTWARE" };
    // parse studentData, insert into Roster::classRosterArray
    for (int i = 0; i < 5; i++)
    {
        Student* st = new Student();
        int size = studentData[i].size();
        std::string id = "";
        std::string first = "";
        std::string last = "";
        std::string email = "";
        std::string age = "";
        std::string firstCourse = "";
        std::string secondCourse = "";
        std::string thirdCourse = "";
        std::string program = "";

        for (int j = 0; j < size; j++)
        {
            while (studentData[i][j] != ',') { id += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { first += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { last += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { email += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { age += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { firstCourse += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { secondCourse += studentData[i][j]; j++; }
            j++;
            while (studentData[i][j] != ',') { thirdCourse += studentData[i][j]; j++; }
            j++;
            while (j != size) { program += studentData[i][j]; j++; }
        }
        std::cout << "id: " << id << std::endl;
        std::cout << "first: " << first << std::endl;
        std::cout << "age: " << age << std::endl;
        std::cout << "last: " << last << std::endl;
        st->setStudentID(id);
        st->setFirstName(first);
        st->setLastName(last);
        st->setEmailAddress(email);
        st->setAge(stoi(age));
        std::array<int, 3> a = { stoi(firstCourse), stoi(secondCourse), stoi(thirdCourse) };
        st->setNumDaysCompleteCourse( a );

        if (program == "SECURITY")
        {
            st->setDegreeProgram(SECURITY);
        }
        else if (program == "NETWORK")
        {
            st->setDegreeProgram(NETWORK);
        }
        else
        {
            st->setDegreeProgram(SOFTWARE);
        }

        classRosterArray[i] = st;
    }
}

void Roster::printAll()
{
    int size = classRosterArray.size();
    std::cout << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        classRosterArray[i]->printStudentData();
    }
}