#ifndef MANAGER_HR_H
#define MANAGER_HR_H
#include "member.h"
//#include "DataManagementSystem.h"
class Manager_HR :
    public Member
{
protected:
    string* listOfAssignedTeams;
    int assignedTeamCount;
    string* listOfAssignedProjects;
    int assignedProjectCount;
    string title;
    string department;
public:
    //constructors
    Manager_HR();
    Manager_HR(const Manager_HR&);
    Manager_HR(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID, const string& title, const string& department);
    //destructor
    ~Manager_HR();
    //adders and removers
    void addAssignedTeam(const string& teamID);
    void addAssignedProject(const string& projectID);
    void removeAssignedTeam(const string& teamID);
    void removeAssignedProject(const string& projectID);
    //getters
    const string& getTitle() const;
    const string& getDepartment() const;
    string* getListOfAssignedTeams() const;
    string* getListOfAssignedProjects() const;
    int getAssignedTeamCount() const;
    int getAssignedProjectCount() const;
    //setters
    void setTitle(const string& title);
    void setDepartment(const string& department);
    void setListOfAssignedTeams(string* listOfAssignedTeams);
    void setListOfAssignedProjects(string* listOfAssignedProjects);
    void setAssignedTeamCount(int assignedTeamCount);
    void setAssignedProjectCount(int assignedProjectCount);
    //print functions
    void print() const override;
    void print(const string& fileName) const override;
    void print(ofstream& out) const override;
    void printAssignedTeams() const;
    void printAssignedProjects() const;
    //operator overloads
    Manager_HR& operator=(const Manager_HR&);
    bool operator==(const Manager_HR&) const;
    bool operator!=(const Manager_HR&) const;
    //search functions
    bool searchAssignedTeam(const string& teamID) const;
    bool searchAssignedProject(const string& projectID) const;
    //Manager Functions
    /*template<class T>
    bool addMember(DataManagementSystem&, T&);
    template<class T>
    bool editMember(DataManagementSystem&, T&);
    template<class T>
    bool removeMember(DataManagementSystem&, T&);*/
    //other functions
    string getMemberInfo() const override;
};
#endif // MANAGER_HR_H
