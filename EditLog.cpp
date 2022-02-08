#include "EditLog.h"

//constructor
EditLog::EditLog()
{
    this->date = Date();
    date.setSystemTime();
    this->edit = "";
    this->editorID = "";
    this->editorName = "";
}

EditLog::EditLog(const Date& date, const std::string& edit, const std::string& editorID, const std::string& editorName)
{
    this->date = date;
    this->edit = edit;
    this->editorID = editorID;
    this->editorName = editorName;
}

EditLog::EditLog(const EditLog& editLog)
{
    this->date = editLog.date;
    this->edit = editLog.edit;
    this->editorID = editLog.editorID;
    this->editorName = editLog.editorName;
}

//destructor
EditLog::~EditLog()
{
}

//setters
void EditLog::setDate(const Date& date)
{
    this->date = date;
}

void EditLog::setEdit(const std::string& edit)
{
    this->edit = edit;
}

void EditLog::setID(const std::string& editorID)
{
    this->editorID = editorID;
}

void EditLog::setEditorName(const std::string& editorName)
{
    this->editorName = editorName;
}

//getters
Date EditLog::getDate() const
{
    return this->date;
}

std::string EditLog::getEdit() const
{
    return this->edit;
}

std::string EditLog::getID() const
{
    return this->editorID;
}

std::string EditLog::getEditorName() const
{
    return this->editorName;
}

//print functions
void EditLog::print() const
{
    std::cout << *this;
}

void EditLog::print(const std::string& fileName) const
{
    std::ofstream out(fileName);
    out << *this;
    out.close();
}

void EditLog::print(std::ofstream& out) const
{
    out << *this;
}

//read functions
void EditLog::read(const std::string& fileName)
{
    std::ifstream in(fileName);
    read(in);
    in.close();
}

void EditLog::read(std::ifstream& in)
{
    in >> *this;
}

void EditLog::read(std::istream& in)
{
    in >> *this;
}

//operator overloads
EditLog& EditLog::operator=(const EditLog& editLog)
{
    if (this != &editLog)
    {
        this->date = editLog.date;
        this->edit = editLog.edit;
        this->editorID = editLog.editorID;
        this->editorName = editLog.editorName;
    }
    return *this;
}

bool EditLog::operator==(const EditLog& editLog) const
{
    return (this->date == editLog.date && this->edit == editLog.edit && this->editorID == editLog.editorID && this->editorName == editLog.editorName);
}

bool EditLog::operator!=(const EditLog& editLog) const
{
    return !(*this == editLog);
}

//friend functions
std::ostream& operator<<(std::ostream& out, const EditLog& editLog)
{
    out << editLog.date << " " << editLog.edit << " " << editLog.editorID << " " << editLog.editorName;
    return out;
}

std::istream& operator>>(std::istream& in, EditLog& editLog)
{
    in >> editLog.date >> editLog.edit >> editLog.editorID >> editLog.editorName;
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const EditLog& editLog)
{
    out << editLog.date << " " << editLog.edit << " " << editLog.editorID << " " << editLog.editorName;
    return out;
}

std::ifstream& operator>>(std::ifstream& in, EditLog& editLog)
{
    in >> editLog.date >> editLog.edit >> editLog.editorID >> editLog.editorName;
    return in;
}