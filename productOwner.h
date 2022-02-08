#ifndef PRODUCTOWNER_H
#define PRODUCTOWNER_H
#pragma once
#include"member.h"
#include"Backlog.h"
#include"Team.h"
#include"Sprint.h"
#include"Lists.h"
#include"EditLog.h"
class ProductOwner :
    public Member
{
protected:
    Lists<string> assignedTeams;
    Lists<string> assignedProjects;
    string type;
    Lists<string> teams;
    Lists<EditLog> editLog;
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
    bool addEditLogEntry(const EditLog& logEntryID);
    bool editEditLogEntry(const string& logEntryID);
    bool removeEditLogEntry(const string& logEntryID);
    //setters
    void setAssignedTeams(const string* listOfTeams, int listOfTeamsCount);
    void setAssignedProjects(const string* listOfProjects, int listOfProjectsCount);
    void setTeams(const string* listOfTeams, int listOfTeamsCount);
    void setEditLog(const EditLog* editLog, int editLogCount);
    void setType(const string& type);
    //getters
    Lists<string> getAssignedTeams() const;
    Lists<string> getAssignedProjects() const;
    Lists<string> getTeams() const;
    Lists<EditLog> getEditLog() const;
    int getAssignedTeamCount() const;
    int getAssignedProjectCount() const;
    int getTeamsCount() const;
    int getEditLogCount() const;
    string getType() const;
    //search functions
    bool searchEditLog(const string& editLog) const;
    bool searchProject(const string& projectID) const;
    bool searchAssignedProject(const string& projectID) const;
    //print functions
    void print() const override;
    void print(const string& fileName) const override;
    void print(ofstream& out) const override;
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