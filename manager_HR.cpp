#include "manager_HR.h"

//Constructors
Manager_HR::Manager_HR()
{
    assignedTeamCount = 0;
    assignedProjectCount = 0;
    listOfAssignedTeams = nullptr;
    listOfAssignedProjects = nullptr;
    title = "";
    department = "";
}
Manager_HR::Manager_HR(const Manager_HR& m)
:Member(m)
{
    assignedTeamCount = m.assignedTeamCount;
    assignedProjectCount = m.assignedProjectCount;
    title = m.title;
    department = m.department;
    listOfAssignedTeams = new string[assignedTeamCount];
    for(int i = 0; i < assignedTeamCount; i++)
    {
        listOfAssignedTeams[i] = m.listOfAssignedTeams[i];
    }
    listOfAssignedProjects = new string[assignedProjectCount];
    for(int i = 0; i < assignedProjectCount; i++)
    {
        listOfAssignedProjects[i] = m.listOfAssignedProjects[i];
    }
}
Manager_HR::Manager_HR(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID, const string& title, const string& department)
:Member(name, email, password, username, phone, description, experience, pfpURL, memberID)
{
    this->title = title;
    this->department = department;
    listOfAssignedProjects = nullptr;
    listOfAssignedTeams = nullptr;
    assignedTeamCount = 0;
    assignedProjectCount = 0;
}
//Destructor
Manager_HR::~Manager_HR()
{
    if(listOfAssignedTeams != nullptr)
    {
        delete[] listOfAssignedTeams;
    }
    if(listOfAssignedProjects != nullptr)
    {
        delete[] listOfAssignedProjects;
    }
}
//Adder and remover
void Manager_HR::addAssignedTeam(const string& assignedTeam)
{
    if (!searchAssignedTeam(assignedTeam))
    {
        if (listOfAssignedTeams == nullptr)
        {
            listOfAssignedTeams = new string[1];
            listOfAssignedTeams[0] = assignedTeam;
            assignedTeamCount = 1;
        }
        else
        {
            string* temp = new string[assignedTeamCount + 1];
            for(int i = 0; i < assignedTeamCount; i++)
            {
                temp[i] = listOfAssignedTeams[i];
            }
            temp[assignedTeamCount] = string(assignedTeam);
            delete[] listOfAssignedTeams;
            listOfAssignedTeams = temp;
            assignedTeamCount++;
        }
    }
    else
    {
        cerr << "Error: Team already assigned." << endl;
    }
}
void Manager_HR::removeAssignedTeam(const string& assignedTeam)
{
    if (assignedTeamCount == 0)
    {
        cerr << "Error: No assigned teams to remove." << endl;
        return;
    }
    else
    {
        if (!searchAssignedTeam(assignedTeam))
        {
            cerr << "Error: Assigned team not found." << endl;
            return;
        }
        else
        {
            if (assignedTeamCount == 1)
            {
                assignedTeamCount--;
                delete[] listOfAssignedTeams;
                listOfAssignedTeams = nullptr;
            }
            else
            {
                string* temp = new string[assignedTeamCount - 1];
                int j = 0;
                for(int i = 0; i < assignedTeamCount; i++)
                {
                    if (listOfAssignedTeams[i] != assignedTeam)
                    {
                        temp[j] = listOfAssignedTeams[i];
                        j++;
                    }
                }
                assignedTeamCount--;
                delete[] listOfAssignedTeams;
                listOfAssignedTeams = temp;
            }
        }
    }
}
void Manager_HR::addAssignedProject(const string& assignedProject)
{
    if(!searchAssignedProject(assignedProject))
    {
        if(listOfAssignedProjects == nullptr)
        {
            listOfAssignedProjects = new string[1];
            listOfAssignedProjects[0] = assignedProject;
            assignedProjectCount = 1;
        }
        else
        {
            string* temp = new string[assignedProjectCount + 1];
            for(int i = 0; i < assignedProjectCount; i++)
            {
                temp[i] = listOfAssignedProjects[i];
            }
            temp[assignedProjectCount] = assignedProject;
            delete[] listOfAssignedProjects;
            listOfAssignedProjects = temp;
            assignedProjectCount++;
        }
    }
    else
    {
        cerr << "Error: Project already assigned." << endl;
    }
}
void Manager_HR::removeAssignedProject(const string& assignedProject)
{
    if(assignedProjectCount == 0)
    {
        cerr << "Error: No assigned projects to remove." << endl;
        return;
    }
    else
    {
        if(!searchAssignedProject(assignedProject))
        {
            cerr << "Error: Assigned project not found." << endl;
            return;
        }
        else
        {
            if(assignedProjectCount == 1)
            {
                assignedProjectCount--;
                delete[] listOfAssignedProjects;
                listOfAssignedProjects = nullptr;
            }
            else
            {
                string* temp = new string[assignedProjectCount - 1];
                int j = 0;
                for(int i = 0; i < assignedProjectCount; i++)
                {
                    if(listOfAssignedProjects[i] != assignedProject)
                    {
                        temp[j] = listOfAssignedProjects[i];
                        j++;
                    }
                }
                assignedProjectCount--;
                delete[] listOfAssignedProjects;
                listOfAssignedProjects = temp;
            }
        }
    }
}
//Getters
const string& Manager_HR::getTitle() const
{
    return title;
}
const string& Manager_HR::getDepartment() const
{
    return department;
}
string* Manager_HR::getListOfAssignedTeams() const
{
    return listOfAssignedTeams;
}
int Manager_HR::getAssignedTeamCount() const
{
    return assignedTeamCount;
}
string* Manager_HR::getListOfAssignedProjects() const
{
    return listOfAssignedProjects;
}
int Manager_HR::getAssignedProjectCount() const
{
    return assignedProjectCount;
}
//Setters
void Manager_HR::setTitle(const string& title)
{
    this->title = title;
}
void Manager_HR::setDepartment(const string& department)
{
    this->department = department;
}
void Manager_HR::setListOfAssignedTeams(string* assignedTeams)
{
    if(listOfAssignedTeams != nullptr)
    {
        delete[] listOfAssignedTeams;
    }
    listOfAssignedTeams = assignedTeams;
}
void Manager_HR::setAssignedTeamCount(int assignedTeamCount)
{
    this->assignedTeamCount = assignedTeamCount;
}
void Manager_HR::setListOfAssignedProjects(string* assignedProjects)
{
    if(listOfAssignedProjects != nullptr)
    {
        delete[] listOfAssignedProjects;
    }
    listOfAssignedProjects = assignedProjects;
}
void Manager_HR::setAssignedProjectCount(int assignedProjectCount)
{
    this->assignedProjectCount = assignedProjectCount;
}
//print functions
void Manager_HR::printAssignedTeams() const
{
    if(assignedTeamCount == 0)
    {
        cout << "No assigned teams" << endl;
    }
    else
    {
        for(int i = 0; i < assignedTeamCount; i++)
        {
            cout << listOfAssignedTeams[i] << endl;
        }
    }
}
void Manager_HR::printAssignedProjects() const
{
    if(assignedProjectCount == 0)
    {
        cout << "No assigned projects" << endl;
    }
    else
    {
        for(int i = 0; i < assignedProjectCount; i++)
        {
            cout << listOfAssignedProjects[i] << endl;
        }
    }
}
void Manager_HR::print() const
{
    Member::print();
    cout << "Title: " << title << endl;
    cout << "Department: " << department << endl;
    cout << "Assigned Teams: " << endl;
    printAssignedTeams();
    cout << "Assigned Projects: " << endl;
    printAssignedProjects();
}
void Manager_HR::print(const string& fileName) const
{
    ofstream outFile;
    outFile.open(fileName, ios::app);
    outFile << "Manager_HR" << endl;
    Member::print(outFile);
    outFile << "Title: " << title << endl;
    outFile << "Department: " << department << endl;
    outFile << "Assigned Teams: " << endl;
    for (int i = 0; i < assignedTeamCount; i++){
        outFile << listOfAssignedTeams[i] << endl;
    }
    outFile << "Assigned Projects: " << endl;
    for (int i = 0; i < assignedProjectCount; i++){
        outFile << listOfAssignedProjects[i] << endl;
    }
    outFile.close();
}
void Manager_HR::print(ofstream& outFile) const
{
    outFile << "Manager_HR" << endl;
    Member::print(outFile);
    outFile << "Title: " << title << endl;
    outFile << "Department: " << department << endl;
    outFile << "Assigned Teams: " << endl;
    for (int i = 0; i < assignedTeamCount; i++){
        outFile << listOfAssignedTeams[i] << endl;
    }
    outFile << "Assigned Projects: " << endl;
    for (int i = 0; i < assignedProjectCount; i++){
        outFile << listOfAssignedProjects[i] << endl;
    }
}
//Operator Overloads
bool Manager_HR::operator==(const Manager_HR& rhs) const
{
    bool isEqual = false;
    if(Member::operator==(rhs) && title == rhs.title && department == rhs.department && assignedTeamCount == rhs.assignedTeamCount && assignedProjectCount == rhs.assignedProjectCount)
    {
        isEqual = true;
        for(int i = 0; i < assignedTeamCount; i++)
        {
            if(listOfAssignedTeams[i] != rhs.listOfAssignedTeams[i])
            {
                isEqual = false;
                break;
            }
        }
        if(isEqual)
        {
            for(int i = 0; i < assignedProjectCount; i++)
            {
                if(listOfAssignedProjects[i] != rhs.listOfAssignedProjects[i])
                {
                    isEqual = false;
                    break;
                }
            }
        }
    }
    return isEqual;
}
bool Manager_HR::operator!=(const Manager_HR& rhs) const
{
    return !(*this == rhs);
}
Manager_HR& Manager_HR::operator=(const Manager_HR& rhs)
{
    if(this != &rhs)
    {
        Member::operator=(rhs);
        title = rhs.title;
        department = rhs.department;
        assignedTeamCount = rhs.assignedTeamCount;
        assignedProjectCount = rhs.assignedProjectCount;
        if(listOfAssignedTeams != nullptr)
        {
            delete[] listOfAssignedTeams;
        }
        listOfAssignedTeams = new string[assignedTeamCount];
        for(int i = 0; i < assignedTeamCount; i++)
        {
            listOfAssignedTeams[i] = rhs.listOfAssignedTeams[i];
        }
        if(listOfAssignedProjects != nullptr)
        {
            delete[] listOfAssignedProjects;
        }
        listOfAssignedProjects = new string[assignedProjectCount];
        for(int i = 0; i < assignedProjectCount; i++)
        {
            listOfAssignedProjects[i] = rhs.listOfAssignedProjects[i];
        }
    }
    return *this;
}
//search functions
bool Manager_HR::searchAssignedTeam(const string& assignedTeam) const
{
    for(int i = 0; i < assignedTeamCount; i++)
    {
        if(listOfAssignedTeams[i] == assignedTeam)
        {
            return true;
        }
    }
    return false;
}
bool Manager_HR::searchAssignedProject(const string& assignedProject) const
{
    for(int i = 0; i < assignedProjectCount; i++)
    {
        if(listOfAssignedProjects[i] == assignedProject)
        {
            return true;
        }
    }
    return false;
}
//other functions
string Manager_HR::getMemberInfo() const
{
    stringstream ss;
    ss << "Manager_HR" << endl;
    ss << Member::getMemberInfo();
    ss << "Title: " << title << endl;
    ss << "Department: " << department << endl;
    ss << "Assigned Teams: " << endl;
    if (assignedTeamCount == 0)
    {
        ss << "None" << endl;
    }
    else
    {
        for(int i = 0; i < assignedTeamCount; i++)
        {
            ss << listOfAssignedTeams[i] << endl;
        }
    }
    ss << "Assigned Projects: " << endl;
    if (assignedProjectCount == 0)
    {
        ss << "None" << endl;
    }
    else
    {
        for(int i = 0; i < assignedProjectCount; i++)
        {
            ss << listOfAssignedProjects[i] << endl;
        }
    }
    return ss.str();
}