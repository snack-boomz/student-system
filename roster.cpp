#include "roster.h"

Roster::Roster()
{
    rosterSize = 5;
    Student** cra = new Student*[rosterSize];
    classRosterArray = cra;
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
        for (int i = 0; i < rosterSize; i++)
        {
                classRosterArray[i]->printStudentData();
        }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
        Student* st = new Student();
        st->setStudentID(studentID);
        st->setFirstName(firstName);
        st->setLastName(lastName);
        st->setEmailAddress(emailAddress);
        st->setAge(age);
        std::array<int, 3> a = { daysInCourse1, daysInCourse2, daysInCourse3 };
        st->setNumDaysCompleteCourse( a );
        st->setDegreeProgram(degreeProgram);

        // if array needs doubled in size due to no more space, dynamically resize it before adding new student
        // int size = sizeof(classRosterArray) / sizeof(Student*);
        // we can see if studentID on last element of array has been changed on last element to indicate if classRosterArray is full.
        // If it's still pre-defined A0, it hasn't been set. Hence, array doesn't need resized yet
        if (classRosterArray[rosterSize - 1]->getStudentID() != "A0") // needs resized
        {
            int orig_size = rosterSize;
        
            rosterSize = rosterSize * 2; // double the size
            Student** new_a = new Student*[rosterSize];
        
            // copy contents over to new_a
            for (int i = 0; i < orig_size; i++) new_a[i] = classRosterArray[i];
            // fill rest of extra contents of new_a with 'TBD' students to be altered later as needed (when adding, subtracting, etc)
            for (int i = orig_size; i < rosterSize; i++)
            {
                Student* s = new Student(); new_a[i] = s;
            }
            // set new classRosterArray to the now doubled new_a
            delete[] classRosterArray;
            classRosterArray = new_a;
            
            // now add new student in new array
            for (int i = 0; i < rosterSize; i++)
            {
                if (classRosterArray[i]->getStudentID() == "A0")
                {
                    classRosterArray[i] = st;
                    break;
                }
                continue;
            }
        }
        else // doesn't need resized, find first available pre-filled slot and fill with new info
        {
            for (int i = 0; i < rosterSize; i++)
            {
                if (classRosterArray[i]->getStudentID() == "A0")
                {
                    classRosterArray[i] = st;
                    break;
                }
                continue;
            }
        }
}

void Roster::remove(std::string studentID)
{
    for (int i = 0; i < rosterSize; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            // because this is a fixed array, we'll simply need to replace this ptr with a default pre-filled student ptr,
            // since removing this ptr from the array would effectively break the roster if we don't replace it, and it doesn't resize dynamically if things are removed.
            // and in the future, an add() func call would refill that new pre-filled student ptr with custom info.
            // 
            Student* new_s = new Student();
            delete classRosterArray[i];
            classRosterArray[i] = nullptr; // null it for good practice so there's no old reference to it
            
            classRosterArray[i] = new_s;
            return; // ensure we gracefully leave the function. if this return never fires, this means the provided student ID doesn't exist
        }
    }
    std::cout << "A student with that student ID (" << studentID << ") doesn't exist." << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
    for (int i = 0; i < rosterSize; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            std::array<int, 3> s_course_days = classRosterArray[i]->getNumDaysCompleteCourse();
            int sum = 0; for (int i = 0; i < 3; i++) sum += s_course_days[i];
            std::cout << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " (Student ID: " << studentID << ") Average Days in Course: " << sum / 3 << std::endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    std::cout << "Invalid Emails: " << std::endl;
    for (int i = 0; i < rosterSize; i++)
    {
        std::string curr_email = classRosterArray[i]->getEmailAddress();
        int strlen = curr_email.length();
        int sign_count = 0;
        int whitespace = 0;
        for (int i = 0; i < strlen; i++)
        {
            if (curr_email[i] == '@' || curr_email[i] == '.') sign_count++;
            if (curr_email[i] == ' ') whitespace++;
        }
        
        if (sign_count < 2 || whitespace > 0) std::cout << curr_email << std::endl;
        
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    std::string s = "";
    switch (degreeProgram)
    {
        case SECURITY:
            s = "SECURITY";
            break;
    case NETWORK:
            s = "NETWORK";
            break;
    case SOFTWARE:
            s = "SOFTWARE";
            break;
    default:
            s = "INVALID";
    }
    
    std::cout << "Students in Degree Program " << s << ":" << std::endl;
    
    for (int i = 0; i < rosterSize; i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->printStudentData();
        }
    }
}