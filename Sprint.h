#ifndef SPRINT_H
#define SPRINT_H
#pragma once
#include "SprintBacklog.h"
#include <iostream>
#include <fstream>
#include "Date.h"
class Sprint
{
private:
    Date startDate;
    Date endDate;
    std::string sprintID;
    std::string projectID;
    std::string teamID;
    std::string sprintName;
    std::string sprintDescription;
    std::string sprintStatus;
public:
    Sprint();
    Sprint(const Date& startDate, const Date& endDate, const std::string& sprintID, const std::string& projectID, const std::string& teamID, const std::string& sprintName, const std::string& sprintDescription, const std::string& sprintStatus);
    Sprint(const Sprint&);
    ~Sprint();
    //setters
    void setStartDate(const Date& startDate);
    void setEndDate(const Date& endDate);
    void setID(const std::string& sprintID);
    void setProjectID(const std::string& projectID);
    void setTeamID(const std::string& teamID);
    void setSprintName(const std::string& sprintName);
    void setSprintDescription(const std::string& sprintDescription);
    void setSprintStatus(const std::string& sprintStatus);
    //getters
    Date getStartDate() const;
    Date getEndDate() const;
    std::string getID() const;
    std::string getProjectID() const;
    std::string getTeamID() const;
    std::string getSprintName() const;
    std::string getSprintDescription() const;
    std::string getSprintStatus() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    Sprint& operator=(const Sprint&);
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const Sprint& sprint);
    friend std::istream& operator>>(std::istream& in, Sprint& sprint);
    friend std::ofstream& operator<<(std::ofstream& out, const Sprint& sprint);
    friend std::ifstream& operator>>(std::ifstream& in, Sprint& sprint);
    //sprint functions
    bool startSprint();
    bool finishSprint();
    bool createSprintList(Backlog& backlog);//create a sprint list from the backlog
};
#endif // SPRINT_H