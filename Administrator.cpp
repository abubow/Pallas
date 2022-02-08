#include "Administrator.h"

//constructors
Administrator::Administrator()
{
    editLog = nullptr;
    editLogCount = 0;
}
Administrator::Administrator(const Administrator& a)
:Member(a)
{
    editLogCount = a.editLogCount;
    editLog = new string[editLogCount];
    for(int i = 0; i < editLogCount; i++)
    {
        editLog[i] = a.editLog[i];
    }
}
Administrator::Administrator(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID)
:Member(name, email, password, username, phone, description, experience, pfpURL, memberID)
{
    editLogCount = 0;
    editLog = nullptr;
}
//destructor
Administrator::~Administrator()
{
    if (editLog != nullptr)
    {
        delete[] editLog;
    }
}
//adders and removers
bool Administrator::addEditLog(const string& editLogEntry)
{
    if(addToList(editLog, editLogCount, editLogEntry))
    {
        editLogCount++;
        return true;
    }
    else{
        cout << "Error: edit log entry already exists." << endl;
        return false;
    }
}
bool Administrator::removeEditLog(const string& editLogEntry)
{
    if(removeFromList(editLog, editLogCount, editLogEntry))
    {
        editLogCount--;
        return true;
    }
    else{
        cout << "Error: edit log entry does not exist." << endl;
        return false;
    }
}
//getters
int Administrator::getEditLogCount() const
{
    return editLogCount;
}
const string* Administrator::getEditLog() const
{
    return editLog;
}
//setters
void Administrator::setEditLogCount(int editLogCount)
{
    this->editLogCount = editLogCount;
}
void Administrator::setEditLog(string* editLog)
{
    this->editLog = editLog;
}
//search functions
bool Administrator::searchEditLog(const string& editLogEntry) const
{
    if (editLog == nullptr)
    {
        return false;
    }
    else
    {
        for(int i = 0; i < editLogCount; i++)
        {
            if (editLog[i] == editLogEntry)
            {
                return true;
            }
        }
        return false;
    }
}
//print functions
void Administrator::print() const
{
    Member::print();
    cout << "Edit Log: " << endl;
    for(int i = 0; i < editLogCount; i++)
    {
        cout << editLog[i] << endl;
    }
}
void Administrator::print(const string& fileName) const
{
    ofstream outFile;
    outFile.open(fileName);
    outFile << "Administrator" << endl;
    Member::print(outFile);
    outFile << "Edit Log: " << endl;
    for(int i = 0; i < editLogCount; i++)
    {
        outFile << editLog[i] << endl;
    }
    outFile.close();
}
void Administrator::print(ofstream& file) const
{
    file << "Administrator" << endl;
    Member::print(file);
    file << "Edit Log: " << endl;
    for(int i = 0; i < editLogCount; i++)
    {
        file << editLog[i] << endl;
    }
}
//overloaded operators
Administrator& Administrator::operator=(const Administrator& admin)
{
    if (this != &admin)
    {
        Member::operator=(admin);
        editLogCount = admin.editLogCount;
        if (editLog != nullptr)
        {
            delete[] editLog;
        }
        editLog = new string[editLogCount];
        for(int i = 0; i < editLogCount; i++)
        {
            editLog[i] = admin.editLog[i];
        }
    }
    return *this;
}
bool Administrator::operator==(const Administrator& admin) const
{
    bool same = true;
    if (editLogCount != admin.editLogCount)
    {
        same = false;
    }
    else
    {
        for(int i = 0; i < editLogCount; i++)
        {
            if (editLog[i] != admin.editLog[i])
            {
                same = false;
                break;
            }
        }
    }
    return (Member::operator==(admin) && same);
}
bool Administrator::operator!=(const Administrator& admin) const
{
    return !(operator==(admin));
}
//other functions
string Administrator::getMemberInfo() const
{
    stringstream ss;
    ss << "Administrator" << endl;
    ss << Member::getMemberInfo();
    ss << "Edit Log: " << endl;
    for(int i = 0; i < editLogCount; i++)
    {
        ss << editLog[i] << endl;
    }
    return ss.str();
}