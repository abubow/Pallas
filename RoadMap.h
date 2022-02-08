#ifndef ROADMAP_H
#define ROADMAP_H
#pragma once
#include <iostream>
#include <fstream>
#include "Lists.h"
#include "EditLog.h"
#include "Date.h"
//keeps track of the current progress on each project by keeping estimations of the time it will take to complete each task
class RoadMap
{
private:
    Lists<int> projectProgress;//stores the current progress on each project
    Lists<Date> projectStartDates;
    Lists<Date> projectEndDates;
    Lists<int> projectEstimations;//stores the estimated time it will take to complete each task
    Lists<EditLog> projectEditLog;
    Lists<std::string> projectID;
    std::string RoadMapID;
public:
    RoadMap();
    RoadMap(const RoadMap&);
    ~RoadMap();
    //setters
    void setProjectIDs(const Lists<std::string>& projectIDs);
    void setProjectProgress(const Lists<int>& projectProgress);
    void setProjectStartDates(const Lists<Date>& projectStartDates);
    void setProjectEndDates(const Lists<Date>& projectEndDates);
    void setProjectEstimations(const Lists<int>& projectEstimations);
    void setProjectEditLog(const Lists<EditLog>& projectEditLog);
    void setID(const std::string& RoadMapID);
    //getters
    Lists<std::string> getProjectIDs() const;
    Lists<int> getProjectProgress() const;
    Lists<Date> getProjectStartDates() const;
    Lists<Date> getProjectEndDates() const;
    Lists<int> getProjectEstimations() const;
    Lists<EditLog> getProjectEditLog() const;
    std::string getID() const;
    //adders and removers
    bool addProject(const std::string& projectID, const int& projectProgress, const Date& projectStartDate, const Date& projectEndDate, const int& projectEstimation);
    bool addProject(const std::string& projectID, const int& projectProgress, const Date& projectStartDate, const Date& projectEndDate, const int& projectEstimation, const EditLog& projectEditLog);
    bool removeProject(const std::string& projectID);
    bool removeProject(const std::string& projectID, const EditLog& projectEditLog);
    bool editProject(const std::string& projectID, const int& projectProgress, const Date& projectStartDate, const Date& projectEndDate, const int& projectEstimation);
    bool editProject(const std::string& projectID, const int& projectProgress, const Date& projectStartDate, const Date& projectEndDate, const int& projectEstimation, const EditLog& projectEditLog);
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    RoadMap& operator=(const RoadMap&);
    bool operator==(const RoadMap&) const;
    bool operator!=(const RoadMap&) const;
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const RoadMap& roadMap);
    friend std::istream& operator>>(std::istream& in, RoadMap& roadMap);
    friend std::ofstream& operator<<(std::ofstream& out, const RoadMap& roadMap);
    friend std::ifstream& operator>>(std::ifstream& in, RoadMap& roadMap);
};

#endif // ROADMAP_H