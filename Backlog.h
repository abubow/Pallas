#ifndef BACKLOG_H
#define BACKLOG_H
#pragma once
#include<iostream>
using namespace std;
#include "Lists.h"
#include "Item.h"
//#include "productOwner.h"
class Backlog
{
protected:
	Lists<Item> items;
	Lists<string> editLog;
	string ownerID;
public:
	Backlog();
	Backlog(const Backlog&);
	Backlog(const string&);
	//destructor
	~Backlog();
	//adders and removers
	bool addItem(const Item& item);
	bool editItem(const Item& item);
	bool removeItem(const Item& item);
	bool addEditLogEntry(const string& logEntryID);
	bool editEditLogEntry(const string& logEntryID);
	bool removeEditLogEntry(const string& logEntryID);
	//setters
	void setOwnerID(const string& ownerID);
	//getters
	const string& getOwnerID() const;
	const Lists<Item>& getItems() const;
	//search functions
	bool searchItem(const string& itemID) const;
	bool searchEditLog(const string& editLog) const;
	//print functions
	void print() const;
};
#endif // !BACKLOG_H