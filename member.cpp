#include "member.h"

Member::Member(){
    name = "";
    email = "";
    password = "";
    username = "";
    phone = "";
    description = "";
    experience = "";
    pfpURL = "";
    memberID = "";
}

Member::Member(const Member& m){
    name = m.name;
    email = m.email;
    password = m.password;
    username = m.username;
    phone = m.phone;
    description = m.description;
    experience = m.experience;
    pfpURL = m.pfpURL;
    memberID = m.memberID;
}

Member::Member(const string& name, const string& email, const string& password, const string& username, const string& phone, const string& description, const string& experience, const string& pfpURL, const string& memberID){
    this->name = name;
    this->email = email;
    this->password = password;
    this->username = username;
    this->phone = phone;
    this->description = description;
    this->experience = experience;
    this->pfpURL = pfpURL;
    this->memberID = memberID;
}

//setters
void Member::setName(const string& name){
    this->name = name;
}
void Member::setEmail(const string& email){
    this->email = email;
}
void Member::setPassword(const string& password){
    this->password = password;
}
void Member::setUsername(const string& username){
    this->username = username;
}
void Member::setPhone(const string& phone){
    this->phone = phone;
}
void Member::setDescription(const string& description){
    this->description = description;
}
void Member::setExperience(const string& experience){
    this->experience = experience;
}
void Member::setPFP(const string& pfpURL){
    this->pfpURL = pfpURL;
}
void Member::setID(const string& memberID){
    this->memberID = memberID;
}
//getters
string Member::getName() const{
    return name;
}
string Member::getEmail() const{
    return email;
}
string Member::getPassword() const{
    return password;
}
string Member::getUsername() const{
    return username;
}
string Member::getPhone() const{
    return phone;
}
string Member::getDescription() const{
    return description;
}
string Member::getExperience() const{
    return experience;
}
string Member::getPFP() const{
    return pfpURL;
}
string Member::getID() const{
    return memberID;
}
//print functions
void Member::print() const{
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Username: " << username << endl;
    cout << "Phone: " << phone << endl;
    cout << "Description: " << description << endl;
    cout << "Experience: " << experience << endl;
    cout << "PFP URL: " << pfpURL << endl;
    cout << "Member ID: " << memberID << endl;
}
void Member::print(const string& fileName) const{
    ofstream outFile;
    outFile.open(fileName, ios::app);
    outFile << "Name: " << name << endl;
    outFile << "Email: " << email << endl;
    outFile << "Password: " << password << endl;
    outFile << "Username: " << username << endl;
    outFile << "Phone: " << phone << endl;
    outFile << "Description: " << description << endl;
    outFile << "Experience: " << experience << endl;
    outFile << "PFP URL: " << pfpURL << endl;
    outFile << "Member ID: " << memberID << endl;
    outFile.close();
}
void Member::print(ofstream& file) const{
    file << "Name: " << name << endl;
    file << "Email: " << email << endl;
    file << "Password: " << password << endl;
    file << "Username: " << username << endl;
    file << "Phone: " << phone << endl;
    file << "Description: " << description << endl;
    file << "Experience: " << experience << endl;
    file << "PFP URL: " << pfpURL << endl;
    file << "Member ID: " << memberID << endl;
}
//other functions
void Member::printMember() const{
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Username: " << username << endl;
    cout << "Phone: " << phone << endl;
    cout << "Description: " << description << endl;
    cout << "Experience: " << experience << endl;
    cout << "PFP URL: " << pfpURL << endl;
    cout << "Member ID: " << memberID << endl;
}
//operator overloads
Member& Member::operator=(const Member& m){
    name = m.name;
    email = m.email;
    password = m.password;
    username = m.username;
    phone = m.phone;
    description = m.description;
    experience = m.experience;
    pfpURL = m.pfpURL;
    memberID = m.memberID;
    return *this;
}
bool Member::operator==(const Member& m) const{
    return (name == m.name && 
            email == m.email && 
            password == m.password && 
            username == m.username &&
            phone == m.phone && 
            description == m.description &&
            experience == m.experience && 
            pfpURL == m.pfpURL &&
            memberID == m.memberID);
}
bool Member::operator!=(const Member& m) const{
    return !(*this == m);
}
//virtual functions
string Member::getMemberInfo() const{
    stringstream ss;
    ss << "Name: " << name << endl;
    ss << "Email: " << email << endl;
    ss << "Password: " << password << endl;
    ss << "Username: " << username << endl;
    ss << "Phone: " << phone << endl;
    ss << "Description: " << description << endl;
    ss << "Experience: " << experience << endl;
    ss << "PFP URL: " << pfpURL << endl;
    ss << "Member ID: " << memberID << endl;
    return ss.str();
}