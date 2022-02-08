#include "productOwner.h"

ProductOwner::ProductOwner():
    Member()
{
    type = "NORMAL";
}

ProductOwner::ProductOwner(const ProductOwner& po):
    Member(po)
{
    type = "NORMAL";
}

ProductOwner::ProductOwner(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID, const string& type):
    Member(name, email, password, username, phone, description, experience, pfpURL, memberID),
    type(type)
{
}

//setters
void ProductOwner::setType(const string& type)
{
    this->type = type;
}
void ProductOwner::setAssignedProjects(const string* assignedProjects, int assignedProjectsCount)
{
    this->assignedProjects.clear();
    for(int i = 0; i < assignedProjectsCount; i++)
    {
        this->assignedProjects.add(assignedProjects[i]);
    }
}
void ProductOwner::setAssignedTeams(const string* assignedTeams, int assignedTeamsCount)
{
    this->assignedTeams.clear();
    for(int i = 0; i < assignedTeamsCount; i++)
    {
        this->assignedTeams.add(assignedTeams[i]);
    }
}
void ProductOwner::setTeams(const string* teams, int teamsCount)
{
    this->teams.clear();
    for(int i = 0; i < teamsCount; i++)
    {
        this->teams.add(teams[i]);
    }
}
void ProductOwner::setEditLog(const EditLog* editLog, int editLogCount)
{
    this->editLog.clear();
    for(int i = 0; i < editLogCount; i++)
    {
        this->editLog.add(editLog[i]);
    }
}
//getters
string ProductOwner::getType() const
{
    return type;
}
Lists<string> ProductOwner::getAssignedProjects() const
{
    return assignedProjects;
}
Lists<string> ProductOwner::getAssignedTeams() const
{
    return assignedTeams;
}
Lists<string> ProductOwner::getTeams() const
{
    return teams;
}
Lists<EditLog> ProductOwner::getEditLog() const
{
    return editLog;
}
int ProductOwner::getAssignedProjectCount() const
{
    return assignedProjects.getSize();
}
int ProductOwner::getAssignedTeamCount() const
{
    return assignedTeams.getSize();
}
int ProductOwner::getTeamsCount() const
{
    return teams.getSize();
}
int ProductOwner::getEditLogCount() const
{
    return editLog.getSize();
}
//search functions
bool ProductOwner::searchEditLog(const string& editLog) const
{
    return searchInListByID<EditLog>(this->editLog, editLog);
}
bool ProductOwner::searchAssignedProject(const string& projectID) const
{
    if(assignedProjects.search(projectID))
    {
        return true;
    }
    return false;
}
bool ProductOwner::searchProject(const string& projectID) const
{
    if(teams.search(projectID))
    {
        return true;
    }
    return false;
}
//print functions
void ProductOwner::print() const
{
    cout << "Product Owner: " << endl;
    Member::print();
    cout << "Type: " << type << endl;
    cout << "Teams: ";
    teams.print();
    cout << "Assigned Projects: ";
    assignedProjects.print();
    cout << "Assigned Teams: ";
    assignedTeams.print();
    cout << "Edit Log: ";
    editLog.print();
}
void ProductOwner::print(ofstream& out) const
{
    out << "Product Owner: " << endl;
    Member::print(out);
    out << "Type: " << type << endl;
    out << "Teams: ";
    teams.print(out);
    out << "Assigned Projects: ";
    assignedProjects.print(out);
    out << "Assigned Teams: ";
    assignedTeams.print(out);
    out << "Edit Log: ";
    editLog.print(out);
}
void ProductOwner::print(const string& fileName) const{
    ofstream out(fileName);
    print(out);
    out.close();
}
//operator overloads
ProductOwner& ProductOwner::operator=(const ProductOwner& po)
{
    if(this != &po)
    {
        Member::operator=(po);
        type = po.type;
        assignedProjects = po.assignedProjects;
        assignedTeams = po.assignedTeams;
        teams = po.teams;
        editLog = po.editLog;
    }
    return *this;
}
bool ProductOwner::operator==(const ProductOwner& po) const
{
    bool isEqual = true;
    if (Member::operator!=(po) || type != po.type || assignedProjects != po.assignedProjects || assignedTeams != po.assignedTeams || teams != po.teams || editLog != po.editLog)
    {
        isEqual = false;
    }
    return isEqual;
}
bool ProductOwner::operator!=(const ProductOwner& po) const
{
    return !(*this == po);
}
//destructor
ProductOwner::~ProductOwner()
{
}
