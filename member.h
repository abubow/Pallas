#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;
class Member
{
protected:
    string name;
    string email;
    string password;
    string username;
    string phone;
    string description;
    string experience;
    string pfpURL;
    string memberID;
public:
    //constructors
    Member();
    Member(const Member&);
    Member(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID);
    //setters
    void setName(const string& name);
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setUsername(const string& username);
    void setPhone(const string& phone);
    void setDescription(const string& description);
    void setExperience(const string& experience);
    void setPFP(const string& pfpURL);
    void setMemberID(const string& memberID);
    //getters
    string getName() const;
    string getEmail() const;
    string getPassword() const;
    string getUsername() const;
    string getPhone() const;
    string getDescription() const;
    string getExperience() const;
    string getPFP() const;
    string getMemberID() const;
    //print functions
    virtual void print() const;
    virtual void print(const string& fileName) const;
    virtual void print(ofstream& file) const;
    //other functions
    void printMember() const;
    //virtual functions
    virtual string getMemberInfo() const;
    //overloaded operators
    Member& operator=(const Member& member);
    bool operator==(const Member& member) const;
    bool operator!=(const Member& member) const;
    //destructor
    virtual ~Member();
};
inline bool searchList(const string* list, const int& listCount, const string& item)
{
    bool found = false;
    for (int i = 0; i < listCount; i++)
    {
        if (list[i] == item)
        {
            found = true;
            break;
        }
    }
    return found;
}
inline bool removeFromList(string* list, int& listCount, const string& item)
{
    if (listCount == 0)
    {
        cerr << "Error: List is empty" << endl;
        return false;
    }
    if(searchList(list, listCount, item))
    {
        if(listCount == 1)
        {
            delete[] list;
            list = nullptr;
            listCount = 0;
            return true;
        }
        string* newList = new string[listCount - 1];
        int newListCount = 0;
        for(int i = 0; i < listCount; i++)
        {
            if(list[i] != item)
            {
                newList[newListCount] = list[i];
                newListCount++;
            }
        }
        delete[] list;
        list = newList;
        listCount = newListCount;
        return true;
    }
    return false;
}
inline bool addToList(string*& list, int& listCount, const string& item)
{
    if (listCount == 0)
    {
        list = new string[1];
        list[0] = item;
        listCount = 1;
        return true;
    }
    if(searchList(list, listCount, item))
    {
        cerr << "Error: Item already exists in list." << endl;
        return false;
    }
    string* newList = new string[listCount + 1];
    for(int i = 0; i < listCount; i++)
    {
        newList[i] = list[i];
    }
    newList[listCount] = item;
    delete[] list;
    list = newList;
    listCount++;
    return true;
}
#endif // MEMBER_H
