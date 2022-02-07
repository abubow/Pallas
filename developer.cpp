#pragma once
#include "developer.h"
//constructors
Developer::Developer()
{
    xp = 0;
    workPerWeek = 0;
    teamID = "";
    projectCount = 0;
    assignedItemCount = 0;
    assignedProjectCount = 0;
}
Developer::Developer(const Developer& d)
:Member(d)
{
    xp = d.xp;
    workPerWeek = d.workPerWeek;
    teamID = d.teamID;
    projectCount = d.projectCount;
    assignedItemCount = d.assignedItemCount;
    assignedProjectCount = d.assignedProjectCount;
    projects = new string[projectCount];
    for(int i = 0; i < projectCount; i++)
    {
        projects[i] = d.projects[i];
    }
    listOfAssignedItems = new string[assignedItemCount];
    for(int i = 0; i < assignedItemCount; i++)
    {
        listOfAssignedItems[i] = d.listOfAssignedItems[i];
    }
    listOfAssignedProjects = new string[assignedProjectCount];
    for(int i = 0; i < assignedProjectCount; i++)
    {
        listOfAssignedProjects[i] = d.listOfAssignedProjects[i];
    }
}
Developer::Developer(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID, double xp, double workPerWeek, const string& teamID)
:Member(name, email, password, username, phone, description, experience, pfpURL, memberID)
{
    this->xp = xp;
    this->workPerWeek = workPerWeek;
    this->teamID = teamID;
    projectCount = 0;
    assignedItemCount = 0;
    assignedProjectCount = 0;
}
//destructor
Developer::~Developer()
{
    if (projects != nullptr)
    {
        delete[] projects;
    }
    if (listOfAssignedItems != nullptr)
    {
        delete[] listOfAssignedItems;
    }
    if (listOfAssignedProjects != nullptr)
    {
        delete[] listOfAssignedProjects;
    }
}
//setters
void Developer::setXp(double xp)
{
    this->xp = xp;
}
void Developer::setWorkPerWeek(double workPerWeek)
{
    this->workPerWeek = workPerWeek;
}
void Developer::setTeamID(const string& teamID)
{
    this->teamID = teamID;
}
void Developer::setListOfAssignedItems(string* listOfAssignedItems)
{
    this->listOfAssignedItems = listOfAssignedItems;
}
void Developer::setListOfAssignedProjects(string* listOfAssignedProjects)
{
    this->listOfAssignedProjects = listOfAssignedProjects;
}
void Developer::setAssignedItemCount(int assignedItemCount)
{
    this->assignedItemCount = assignedItemCount;
}
void Developer::setAssignedProjectCount(int assignedProjectCount)
{
    this->assignedProjectCount = assignedProjectCount;
}
//getters
string Developer::getTeamID() const
{
    return teamID;
}
const string* Developer::getProjects() const
{
    return projects;
}
int Developer::getProjectCount() const
{
    return projectCount;
}
const string* Developer::getListOfAssignedItems() const
{
    return listOfAssignedItems;
}
const string* Developer::getListOfAssignedProjects() const
{
    return listOfAssignedProjects;
}
int Developer::getAssignedItemCount() const
{
    return assignedItemCount;
}
int Developer::getAssignedProjectCount() const
{
    return assignedProjectCount;
}
double Developer::getXp() const
{
    return xp;
}
double Developer::getWorkPerWeek() const
{
    return workPerWeek;
}

//functions
void Developer::addProject(const string& projectID)
{
    projectCount++;
    string* temp = new string[projectCount];
    for(int i = 0; i < projectCount - 1; i++)
    {
        temp[i] = projects[i];
    }
    temp[projectCount - 1] = projectID;
    delete[] projects;
    projects = temp;
}
void Developer::addAssignedItem(const string& itemID)
{
    assignedItemCount++;
    string* temp = new string[assignedItemCount];
    for(int i = 0; i < assignedItemCount - 1; i++)
    {
        temp[i] = listOfAssignedItems[i];
    }
    temp[assignedItemCount - 1] = itemID;
    delete[] listOfAssignedItems;
    listOfAssignedItems = temp;
}
void Developer::addAssignedProject(const string& projectID)
{
    assignedProjectCount++;
    string* temp = new string[assignedProjectCount];
    for(int i = 0; i < assignedProjectCount - 1; i++)
    {
        temp[i] = listOfAssignedProjects[i];
    }
    temp[assignedProjectCount - 1] = projectID;
    delete[] listOfAssignedProjects;
    listOfAssignedProjects = temp;
}
bool Developer::removeProject(const string& projectID)
{
    return removeFromList(projects, projectCount, projectID);
}
bool Developer::removeAssignedItem(const string& itemID)
{
    return removeFromList(listOfAssignedItems, assignedItemCount, itemID);
}
bool Developer::removeAssignedProject(const string& projectID)
{
    return removeFromList(listOfAssignedProjects, assignedProjectCount, projectID);
}
void Developer::printProjects() const
{
    for(int i = 0; i < projectCount; i++)
    {
        cout << projects[i] << endl;
    }
}
void Developer::printAssignedItems() const
{
    for(int i = 0; i < assignedItemCount; i++)
    {
        cout << listOfAssignedItems[i] << endl;
    }
}
void Developer::printAssignedProjects() const
{
    for(int i = 0; i < assignedProjectCount; i++)
    {
        cout << listOfAssignedProjects[i] << endl;
    }
}
void Developer::print() const
{
    Member::print();
    cout << "XP: " << xp << endl;
    cout << "Work Per Week: " << workPerWeek << endl;
    cout << "Team ID: " << teamID << endl;
    cout << "Projects: " << endl;
    printProjects();
    cout << "Assigned Items: " << endl;
    printAssignedItems();
    cout << "Assigned Projects: " << endl;
    printAssignedProjects();
}
void Developer::print(const string& fileName)  const
{
    ofstream outFile;
    outFile.open(fileName, ios::app);
    outFile << "Developer" << endl;
    Member::print(outFile);
    outFile << "XP: " << xp << endl;
    outFile << "Work Per Week: " << workPerWeek << endl;
    outFile << "Team ID: " << teamID << endl;
    outFile << "Projects: " << endl;
    for (int i = 0; i < projectCount; i++)
    {
        outFile << projects[i] << endl;
    }
    outFile << "Assigned Items: " << endl;
    for (int i = 0; i < assignedItemCount; i++)
    {
        outFile << listOfAssignedItems[i] << endl;
    }
    outFile << "Assigned Projects: " << endl;
    for (int i = 0; i < assignedProjectCount; i++)
    {
        outFile << listOfAssignedProjects[i] << endl;
    }
    outFile.close();
}
void Developer::print(ofstream& outFile) const
{
    outFile << "Developer" << endl;
    Member::print(outFile);
    outFile << "XP: " << xp << endl;
    outFile << "Work Per Week: " << workPerWeek << endl;
    outFile << "Team ID: " << teamID << endl;
    outFile << "Projects: " << endl;
    for (int i = 0; i < projectCount; i++)
    {
        outFile << projects[i] << endl;
    }
    outFile << "Assigned Items: " << endl;
    for (int i = 0; i < assignedItemCount; i++)
    {
        outFile << listOfAssignedItems[i] << endl;
    }
    outFile << "Assigned Projects: " << endl;
    for (int i = 0; i < assignedProjectCount; i++)
    {
        outFile << listOfAssignedProjects[i] << endl;
    }
}
//operator overloads
bool Developer::operator==(const Developer& other) const
{
    bool isEqual = false;
    if( Member::operator==(other) && 
        xp == other.xp &&
        workPerWeek == other.workPerWeek &&
        teamID == other.teamID &&
        projectCount == other.projectCount &&
        assignedItemCount == other.assignedItemCount && 
        assignedProjectCount == other.assignedProjectCount
      )
    {
        isEqual = true;
        for(int i = 0; i < projectCount; i++)
        {
            if(projects[i] != other.projects[i])
            {
                isEqual = false;
            }
        }
        for(int i = 0; i < assignedItemCount; i++)
        {
            if(listOfAssignedItems[i] != other.listOfAssignedItems[i])
            {
                isEqual = false;
            }
        }
        for(int i = 0; i < assignedProjectCount; i++)
        {
            if(listOfAssignedProjects[i] != other.listOfAssignedProjects[i])
            {
                isEqual = false;
            }
        }
    }
    return isEqual;
}
bool Developer::operator!=(const Developer& other) const
{
    return !(*this == other);
}
Developer& Developer::operator=(const Developer& other)
{
    if(this != &other)
    {
        Member::operator=(other);
        xp = other.xp;
        workPerWeek = other.workPerWeek;
        teamID = other.teamID;
        projectCount = other.projectCount;
        assignedItemCount = other.assignedItemCount;
        assignedProjectCount = other.assignedProjectCount;
        delete[] projects;
        delete[] listOfAssignedItems;
        delete[] listOfAssignedProjects;
        projects = new string[projectCount];
        listOfAssignedItems = new string[assignedItemCount];
        listOfAssignedProjects = new string[assignedProjectCount];
        for(int i = 0; i < projectCount; i++)
        {
            projects[i] = other.projects[i];
        }
        for(int i = 0; i < assignedItemCount; i++)
        {
            listOfAssignedItems[i] = other.listOfAssignedItems[i];
        }
        for(int i = 0; i < assignedProjectCount; i++)
        {
            listOfAssignedProjects[i] = other.listOfAssignedProjects[i];
        }
    }
    return *this;
}
//search functions
bool Developer::searchProject(const string& projectID)
{
    for(int i = 0; i < projectCount; i++)
    {
        if(projects[i] == projectID)
        {
            return true;
        }
    }
    return false;
}
bool Developer::searchAssignedItem(const string& itemID)
{
    for(int i = 0; i < assignedItemCount; i++)
    {
        if(listOfAssignedItems[i] == itemID)
        {
            return true;
        }
    }
    return false;
}
bool Developer::searchAssignedProject(const string& projectID)
{
    for(int i = 0; i < assignedProjectCount; i++)
    {
        if(listOfAssignedProjects[i] == projectID)
        {
            return true;
        }
    }
    return false;
}
//other functions
string Developer::getMemberInfo() const
{
    stringstream ss;
    ss << "Developer" << endl;
    ss << Member::getMemberInfo();
    ss << "XP: " << xp << endl;
    ss << "Work Per Week: " << workPerWeek << endl;
    ss << "Team ID: " << teamID << endl;
    ss << "Projects: " << endl;
    if (projectCount == 0)
    {
        ss << "None" << endl;
    }
    else
    {
        for (int i = 0; i < projectCount; i++)
        {
            ss << projects[i] << endl;
        }
    }
    ss << "Assigned Items: " << endl;
    if (assignedItemCount == 0)
    {
        ss << "None" << endl;
    }
    else
    {
        for (int i = 0; i < assignedItemCount; i++)
        {
            ss << listOfAssignedItems[i] << endl;
        }
    }
    ss << "Assigned Projects: " << endl;
    if (assignedProjectCount == 0)
    {
        ss << "None" << endl;
    }
    else
    {
        for (int i = 0; i < assignedProjectCount; i++)
        {
            ss << listOfAssignedProjects[i] << endl;
        }
    }
    return ss.str();
}