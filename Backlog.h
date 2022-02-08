#ifndef BACKLOG_H
#define BACKLOG_H
#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include "Lists.h"
#include "Item.h"
#include "Editlog.h"
//#include "productOwner.h"
class Backlog
{
protected:
	Lists<Item> items;
	Lists<EditLog> editLog;
	std::string backlogID;
	std::string ownerID;
public:
	Backlog();
	Backlog(const Backlog&);
	Backlog(const std::string& backlogID,const std::string& ownerID);
	//destructor
	~Backlog();
	//adders and removers
	bool addItem(const Item& item);
	bool editItem(const Item& item);
	bool removeItem(const Item& item);
	bool addDependecy(const Item& item);
	bool removeDependecy(const Item& item);
	bool addEditLogEntry(const EditLog& logEntryID);
	bool editEditLogEntry(const EditLog& logEntryID);
	bool removeEditLogEntry(const std::string& logEntryID);
	bool removeEditLogEntry(const EditLog& logEntryID);
	//setters
	void setOwnerID(const std::string& ownerID);
	void setID(const std::string& backlogID);
	//getters
	const std::string& getOwnerID() const;
	const Lists<Item>& getItems() const;
	const Lists<EditLog>& getEditLog() const;
	const std::string& getBacklogID() const;
	//search functions
	bool searchItem(const std::string& itemID) const;
	bool searchEditLog(const std::string& editLog) const;
	//sort by value
	void sortItemsByValue();
	//operator overloads
	Backlog& operator=(const Backlog&);
	Backlog& operator+=(const Backlog&);
	Backlog& operator+=(const Item&);
	Backlog& operator-=(const Backlog&);
	Backlog& operator-=(const Item&);
	Backlog operator+(const Backlog&) const;
	Backlog operator+(const Item&) const;
	Backlog operator-(const Backlog&) const;
	Backlog operator-(const Item&) const;
	bool operator==(const Backlog&) const;
	bool operator!=(const Backlog&) const;
	//friend functions
	friend ostream& operator<<(ostream&, const Backlog&);
	friend istream& operator>>(istream&, Backlog&);
	friend ofstream& operator<<(ofstream&, const Backlog&);
	friend ifstream& operator>>(ifstream&, Backlog&);
	//print functions
	void print() const;
	//virtual function
	virtual void finish(Backlog& moveBack);
};
#endif // !BACKLOG_H