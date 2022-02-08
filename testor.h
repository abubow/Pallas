#ifndef TESTOR_H
#define TESTOR_H
#pragma once
#include "member.h"
#include "DataManagementSystem.h"
extern class Bug;
class Testor :
    public Member
{
protected:
    string* teams;
public:
    Testor();
    Testor(const Testor&);
    Testor(const string&);
    //Destructor 
    ~Testor();
    //adders and removers
    bool addTeam(const string& teamID);
    bool removeTeam(const string& teamID);
    //setters
    void setTeams(const string* teams);
    //getters
    const string* getTeams() const;
    //search functions
    bool searchTeam(const string& teamID) const;
    //Testor functions
    bool changeItemStaus(const string& newStatus, Item& item);
    Bug createBug();//add parameters
    //print functions
    void print() const override;
};
#endif // !TESTOR_H