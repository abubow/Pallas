#ifndef PRODUCTBACKLOG_H
#define PRODUCTBACKLOG_H
#pragma once
#include "Backlog.h"
#include "Sprint.h"
class ProductBacklog :
    public Backlog
{
private:
    Lists<Sprint> sprintList;
public:
    ProductBacklog();
    ProductBacklog(const std::string& productBacklogID);
    ProductBacklog(const std::string& backlogID,const std::string& ownerID, const Lists<Sprint>& sprintList);
    ProductBacklog(const ProductBacklog&);
    ~ProductBacklog();
    //setters
    void setProductBacklogID(const std::string& productBacklogID);
    void setSprintList(const Lists<Sprint>& sprintList);
    //getters
    std::string getProductBacklogID() const;
    Lists<Sprint> getSprintList() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    ProductBacklog& operator=(const ProductBacklog&);
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const ProductBacklog& productBacklog);
    friend std::istream& operator>>(std::istream& in, ProductBacklog& productBacklog);
    friend std::ofstream& operator<<(std::ofstream& out, const ProductBacklog& productBacklog);
    friend std::ifstream& operator>>(std::ifstream& in, ProductBacklog& productBacklog);
};
#endif // !PRODUCTBACKLOG_H