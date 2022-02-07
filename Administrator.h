#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#pragma once
#include "member.h"
#include "DataManagementSystem.h"
extern class RoadMapMangementSystem;
extern class RoadMap;
class Administrator :
    public Member
{
protected:
    string* editLog;
    int editLogCount;
public:
    //constructors
    Administrator();
    Administrator(const Administrator&);
    Administrator(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID);
    //destructor
    ~Administrator();
    //adders and removers
    bool addEditLog(const string& editLog);
    bool editEditLog(const string& editLogID);
    bool removeEditLog(const string& editLog);
    //getters
    const string* getEditLog() const;
    int getEditLogCount() const;
    //setters
    void setEditLog(string* editLog);
    void setEditLogCount(int editLogCount);
    //search functions
    bool searchEditLog(const string& editLog) const;
    //print functions
    void print() const override;
    void print(const string& fileName) const override;
    void print(ofstream& out) const override;
    //overloaded operators
    Administrator& operator=(const Administrator& administrator);
    bool operator==(const Administrator& admin) const;
    bool operator!=(const Administrator& admin) const;
    //admin functions
    void createMembers(DataManagementSystem& dataBase);
    bool editMembers(DataManagementSystem& dataBase);
    bool deleteMembers(DataManagementSystem& dataBase);
    void createProject(DataManagementSystem& dataBase);
    bool editProject(DataManagementSystem& dataBase);
    bool deleteProject(DataManagementSystem& dataBase);
    void createTeams(DataManagementSystem& dataBase);
    bool editTeams(DataManagementSystem& dataBase);
    bool deleteTeams(DataManagementSystem& dataBase);
    void createRoadMap(DataManagementSystem& dataBase);
    bool editRoadMap(DataManagementSystem& dataBase);
    bool deleteRoadMap(DataManagementSystem& dataBase);
    bool editTimeline(RoadMap& map);
    //other functions
    string getMemberInfo() const override;
};
#endif // !ADMINISTRATOR_H