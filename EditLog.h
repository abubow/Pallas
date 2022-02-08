#ifndef EDITLOG_H
#define EDITLOG_H
#pragma once
#include "Date.h"
#include <iostream>
#include <fstream>
class EditLog
{
protected:
    Date date;
    std::string edit;
    std::string editorID;
    std::string editorName;
public:
    EditLog();
    EditLog(const Date& date, const std::string& edit, const std::string& editorID, const std::string& editorName);
    EditLog(const EditLog&);
    ~EditLog();
    //setters
    void setDate(const Date& date);
    void setEdit(const std::string& edit);
    void setID(const std::string& editorID);
    void setEditorName(const std::string& editorName);
    //getters
    Date getDate() const;
    std::string getEdit() const;
    std::string getID() const;
    std::string getEditorName() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    EditLog& operator=(const EditLog&);
    bool operator==(const EditLog&) const;
    bool operator!=(const EditLog&) const;
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const EditLog& editLog);
    friend std::istream& operator>>(std::istream& in, EditLog& editLog);
    friend std::ofstream& operator<<(std::ofstream& out, const EditLog& editLog);
    friend std::ifstream& operator>>(std::ifstream& in, EditLog& editLog);
};
#endif // !EDITLOG_H