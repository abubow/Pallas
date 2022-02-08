#ifndef SPRINTBACKLOG_H
#define SPRINTBACKLOG_H

#pragma once
#include "Backlog.h"
class SprintBacklog :
    public Backlog
{
private:
    Lists<int> WIPlimits;//WIP limits for each phase of the sprint, in order TODO, BUILD, TEST
    Lists<std::string> TODOIDs;
    Lists<std::string> BUILDIDs;
    Lists<std::string> TESTIDs;
public:
    SprintBacklog();
    SprintBacklog(const std::string& backlogID,const std::string& ownerID);
    SprintBacklog(const std::string& backlogID,const std::string& ownerID, const Lists<int>& WIPlimits, const Lists<std::string>& TODOIDs, const Lists<std::string>& BUILDIDs, const Lists<std::string>& TESTIDs);
    SprintBacklog(const SprintBacklog&);
    ~SprintBacklog();
    //setters
    void setWIPlimits(const Lists<int>& WIPlimits);
    void setTODOIDs(const Lists<std::string>& TODOIDs);
    void setBUILDIDs(const Lists<std::string>& BUILDIDs);
    void setTESTIDs(const Lists<std::string>& TESTIDs);
    //getters
    Lists<int> getWIPlimits() const;
    Lists<std::string> getTODOIDs() const;
    Lists<std::string> getBUILDIDs() const;
    Lists<std::string> getTESTIDs() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    SprintBacklog& operator=(const SprintBacklog&);
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const SprintBacklog& sprintBacklog);
    friend std::istream& operator>>(std::istream& in, SprintBacklog& sprintBacklog);
    friend std::ofstream& operator<<(std::ofstream& out, const SprintBacklog& sprintBacklog);
    friend std::ifstream& operator>>(std::ifstream& in, SprintBacklog& sprintBacklog);
};
#endif // SPRINTBACKLOG_H