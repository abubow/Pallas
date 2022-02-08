#ifndef TEAM_H
#define TEAM_H
#pragma once
#include <iostream>
#include <fstream>
#include "Lists.h"
class Team
{
protected:
	std::string teamID;
	Lists<std::string> memberIDs;
	std::string leaderID;
public:
	Team();
	Team(const Team&);
	Team(const std::string& TeamID, const std::string& leaderID, const std::string* memberIDs, int size);
	~Team();
	//adders and removers
	void addMember(const std::string& memberID);
	void removeMember(const std::string& memberID);
	//setters
	void setTeamID(const std::string& TeamID);
	void setLeaderID(const std::string& leaderID);
	void setMemberIDs(const std::string* memberIDs, int size);
	//getters
	const std::string& getTeamID() const;
	const std::string& getLeaderID() const;
	const std::string* getMemberIDs() const;
	const Lists<std::string>& getMemberIDsList() const;
	const std::string& getMemberID(int index) const;
	int getSize() const;
	//print functions
	void print() const;
	void print(int index) const;
	void print(const std::string& fileName) const;
	void print(std::ofstream& out) const;
	//read functions
	void read(const std::string& fileName);
	void read(std::ifstream& in);
	void read(std::istream& in);
	//operator overloads
	Team& operator=(const Team&);
	Team& operator+=(const Team&);
	Team& operator+=(const std::string& memberID);
	Team& operator-=(const Team&);
	Team& operator-=(const std::string& memberID);
	Team& operator+(const Team&) const;
	Team& operator+(const std::string& memberID) const;
	Team& operator-(const Team&) const;
	Team& operator-(const std::string& memberID) const;
	bool operator==(const Team&) const;
	bool operator!=(const Team&) const;
	std::string& operator[](int index) const;
	//extraction operator overloads
	friend std::ostream& operator<<(std::ostream& out, const Team& team);
	friend std::istream& operator>>(std::istream& in, Team& team);
	friend std::ifstream& operator>>(std::ifstream& in, Team& team);
	friend std::ofstream& operator<<(std::ofstream& out, const Team& team);
};
#endif // !TEAM_H