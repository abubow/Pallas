#ifndef BUG_H
#define BUG_H
#pragma once
#include "Item.h"
class Bug :
    public Item
{
private:
    std::string reporterID;
    std::string assignedToID;
    std::string status;
    double estimatedSeverity;
    double estimatedEffort;
public:
    Bug();
    Bug(const std::string& bugID, const std::string& reporterID, const std::string& assignedToID, const std::string& status, const std::string& title, const std::string& description, const double& estimatedSeverity, const double& estimatedEffort);
    Bug(const Bug&);
    ~Bug();
    //setters
    void setReporterID(const std::string& reporterID);
    void setAssignedToID(const std::string& assignedToID);
    void setStatus(const std::string& status);
    void setEstimatedSeverity(const double& estimatedSeverity);
    void setEstimatedEffort(const double& estimatedEffort);
    //getters
    std::string getReporterID() const;
    std::string getAssignedToID() const;
    std::string getStatus() const;
    double getEstimatedSeverity() const;
    double getEstimatedEffort() const;
    //print functions
    void print() const override;
    void print(const std::string& fileName) const override;
    void print(std::ofstream& out) const override;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    Bug& operator=(const Bug&);
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const Bug& bug);
    friend std::istream& operator>>(std::istream& in, Bug& bug);
    friend std::ofstream& operator<<(std::ofstream& out, const Bug& bug);
    friend std::ifstream& operator>>(std::ifstream& in, Bug& bug);
};
#endif // !BUG_H