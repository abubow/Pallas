#ifndef PRODUCTOWNER_H
#define PRODUCTOWNER_H
#pragma once
#include"member.h"
#include"Backlog.h"
#include"Team.h"
#include"Sprint.h"
class ProductOwner :
    public Member
{
protected:
    string* listOfAssignedTeams;
    int assignedTeamCount;
    string* listOfAssignedProjects;
    int assignedProjectCount;
    string type;
    string* listOfTeams;
    string* editLog;
    int editLogCount;
    int teamCount;
public:
    ProductOwner();
    ProductOwner(const ProductOwner&);
    ProductOwner(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID, const string& type);
    //Destructor 
    ~ProductOwner();
    //adders and removers
    bool addAssignedTeam(const string& teamID);
    bool editAssignedTeam(const string& teamID);
    bool removeAssignedTeam(const string& teamID);
    bool addAssignedProject(const string& ProjectID);
    bool editAssignedProject(const string& ProjectID);
    bool removeAssignedProject(const string& ProjectID);
    bool addEditLogEntry(const string& logEntryID);
    bool editEditLogEntry(const string& logEntryID);
    bool removeEditLogEntry(const string& logEntryID);
    //setters
    void setAssignedTeamCount(int count);
    void setAssignedProjectCount(int count);
    void setTeamsCount(int count);
    void setEditLogCount(int count);
    void setlistOfAssignedTeams(const string* listOfTeams);
    void setlistOfAssignedProjects(const string* listOfProjects);
    void setlistOfTeams(const string* listOfTeams);
    void setEditLog(const string* editLog);
    void setType(const string& type);
    //getters
    const string* getListOfAssignedTeams() const;
    const string* getListOfAssignedProjects() const;
    const string* getListOfTeams() const;
    const string* getEditLog() const;
    int getAssignedTeamCount() const;
    int getAssignedProjectCount() const;
    int getTeamsCount() const;
    int getEditLogCount() const;
    //search functions
    bool searchEditLog(const string& editLog) const;
    bool searchProject(const string& projectID) const;
    bool searchAssignedItem(const string& itemID) const;
    bool searchAssignedProject(const string& projectID) const;
    //print functions
    void print() const override;
    void print(const string& fileName) const override;
    void print(ofstream& out) const override;
    void printProjects() const;
    void printAssignedItems() const;
    void printAssignedProjects() const;
    void printEditLog() const;
    //operator overloads
    ProductOwner& operator=(const ProductOwner&);
    bool operator==(const ProductOwner&) const;
    bool operator!=(const ProductOwner&) const;
    //Porduct Owner functions
    bool moveToBacklog(const string& itemID, Backlog* backlog);
    bool changeItemStatus(const string& itemID, Backlog* backlog);
    Team createTeam();//add parameters
    Sprint createSprint(Team& team);//add parameters
    void addSprint(Sprint* list);
    void startSprint(const string sprintID);
    //other functions
    string getMemberInfo() const override;
};
#endif // !PRODUCTOWNER_H