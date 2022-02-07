#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "member.h"
#include <iostream>
using namespace std;
//#include "Project.h"
#include "SprintBacklog.h"
class Developer :
	public Member
{
	double xp;
	double workPerWeek;
	string* projects;
	string teamID;
	int projectCount;
	string* listOfAssignedItems;
	int assignedItemCount;
	string* listOfAssignedProjects;
	int assignedProjectCount;
public:

	Developer();
	Developer(const Developer&);
	Developer(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID, double xp, double workPerWeek, const string& teamID);
	//destructor
	~Developer();
	//adders and removers
	void addProject(const string& projectID);
	void addAssignedItem(const string& itemID);
	void addAssignedProject(const string& projectID);
	bool removeProject(const string& projectID);
	bool removeAssignedItem(const string& itemID);
	bool removeAssignedProject(const string& projectID);
	//getters
	const string* getProjects() const;
	string getTeamID() const;
	int getProjectCount() const;
	const string* getListOfAssignedItems() const;
	int getAssignedItemCount() const;
	const string* getListOfAssignedProjects() const;
	int getAssignedProjectCount() const;
	double getXp() const;
	double getWorkPerWeek() const;
	//setters
	void setXp(double xp);
	void setWorkPerWeek(double workPerWeek);
	void setTeamID(const string& teamID);
	void setListOfAssignedItems(string* listOfAssignedItems);
	void setListOfAssignedProjects(string* listOfAssignedProjects);
	void setAssignedItemCount(int assignedItemCount);
	void setAssignedProjectCount(int assignedProjectCount);
	//print functions
	void print() const override;
	void print(const string& fileName) const override;
	void print(ofstream& out) const override;
	void printProjects() const;
	void printAssignedItems() const;
	void printAssignedProjects() const;
	//operator overloads
	Developer& operator=(const Developer&);
	bool operator==(const Developer&) const;
	bool operator!=(const Developer&) const;
	//search functions
	bool searchProject(const string& projectID);
	bool searchAssignedItem(const string& itemID);
	bool searchAssignedProject(const string& projectID);
	//developer functions
	bool changeItemStatus(SprintBacklog& item);
	//other functions
	string getMemberInfo() const override;
};

#endif // DEVELOPER_H