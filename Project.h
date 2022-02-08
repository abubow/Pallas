#ifndef PROJECT_H
#define PROJECT_H

#pragma once
#include <iostream>
#include <fstream>
#include "Lists.h"
#include "EditLog.h"
#include "Date.h"

class Project
{
private:
    std::string name;
    std::string description;
    std::string status;
    //ids in all of the lists
    Lists<std::string> members;
    Lists<std::string> sprints;
    Lists<std::string> teams;
    Lists<std::string> sprintBacklogs;
    Lists<std::string> productBacklogs;
    Lists<std::string> featureRequests;
    Lists<std::string> bugs;
    Lists<Date> dates;
    Lists<EditLog> editLogs;
    std::string projectManager;//id
    std::string projectID;//unique
public:
    Project();
    Project(const std::string& name, const std::string& description, const std::string& status, const Lists<std::string>& members, const Lists<std::string>& sprints, const Lists<std::string>& teams, const Lists<std::string>& sprintBacklogs, const Lists<std::string>& productBacklogs, const Lists<std::string>& featureRequests, const Lists<std::string>& bugs, const std::string& projectManager, const std::string& projectID);
    Project(const Project&);
    ~Project();
    //setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setStatus(const std::string& status);
    void setMembers(const Lists<std::string>& members);
    void setSprints(const Lists<std::string>& sprints);
    void setTeams(const Lists<std::string>& teams);
    void setSprintBacklogs(const Lists<std::string>& sprintBacklogs);
    void setProductBacklogs(const Lists<std::string>& productBacklogs);
    void setFeatureRequests(const Lists<std::string>& featureRequests);
    void setBugs(const Lists<std::string>& bugs);
    void setProjectManager(const std::string& projectManager);
    void setID(const std::string& projectID);
    void setDates(const Lists<Date>& dates);
    void setEditLogs(const Lists<EditLog>& editLogs);
    //getters
    std::string getName() const;
    std::string getDescription() const;
    std::string getStatus() const;
    Lists<std::string> getMembers() const;
    Lists<std::string> getSprints() const;
    Lists<std::string> getTeams() const;
    Lists<std::string> getSprintBacklogs() const;
    Lists<std::string> getProductBacklogs() const;
    Lists<std::string> getFeatureRequests() const;
    Lists<std::string> getBugs() const;
    std::string getProjectManager() const;
    std::string getID() const;
    Lists<Date> getDates() const;
    Lists<EditLog> getEditLogs() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    Project& operator=(const Project&);
    bool operator==(const Project&) const;
    bool operator!=(const Project&) const;
    //extraction operator overloads
    friend std::ostream& operator<<(std::ostream& out, const Project& project);
    friend std::istream& operator>>(std::istream& in, Project& project);
    friend std::ofstream& operator<<(std::ofstream& out, const Project& project);
    friend std::ifstream& operator>>(std::ifstream& in, Project& project);
    //adders and removers
    bool addMember(const std::string& member);
    bool addSprint(const std::string& sprint);
    bool addTeam(const std::string& team);
    bool addSprintBacklog(const std::string& sprintBacklog);
    bool addProductBacklog(const std::string& productBacklog);
    bool addFeatureRequest(const std::string& featureRequest);
    bool addBug(const std::string& bug);
    bool removeMember(const std::string& member);
    bool removeSprint(const std::string& sprint);
    bool removeTeam(const std::string& team);
    bool removeSprintBacklog(const std::string& sprintBacklog);
    bool removeProductBacklog(const std::string& productBacklog);
    bool removeFeatureRequest(const std::string& featureRequest);
    bool removeBug(const std::string& bug);
    bool addDate(const Date& date);
    bool removeDate(const Date& date);
    bool addEditLog(const EditLog& editLog);
    bool removeEditLog(const EditLog& editLog);
    //edit functions
    bool editName(const std::string& name);
    bool editDescription(const std::string& description);
    bool editStatus(const std::string& status);
    bool editProjectManager(const std::string& projectManager);
    bool editProjectID(const std::string& projectID);
    //search functions
    bool searchMember(const std::string& member) const;
    bool searchSprint(const std::string& sprint) const;
    bool searchTeam(const std::string& team) const;
    bool searchSprintBacklog(const std::string& sprintBacklog) const;
    bool searchProductBacklog(const std::string& productBacklog) const;
    bool searchFeatureRequest(const std::string& featureRequest) const;
    bool searchBug(const std::string& bug) const;
    bool searchDate(const Date& date) const;
    bool searchEditLog(const EditLog& editLog) const;
};
#endif // PROJECT_H