#include "Team.h"

//constructor
Team::Team(){
    this->teamID="NULL";
    this->leaderID="NULL";
    this->memberIDs.clear();
}
Team::Team(const Team& other){
    this->teamID=other.teamID;
    this->leaderID=other.leaderID;
    this->memberIDs=other.memberIDs;
}
Team::Team(const std::string& TeamID, const std::string& leaderID, const std::string* memberIDs, int size){
    this->teamID=TeamID;
    this->leaderID=leaderID;
    this->memberIDs.clear();
    for(int i=0;i<size;i++){
        this->memberIDs.add(memberIDs[i]);
    }
}
//destructor
Team::~Team(){
}
//adders and removers
void Team::addMember(const std::string& memberID){
    if(memberIDs.search(memberID)){
        std::cout << "Error: member already exists." << std::endl;
    }
    else{
        memberIDs.add(memberID);
    }
}
void Team::removeMember(const std::string& memberID){
    if(memberIDs.search(memberID)){
        memberIDs.remove(memberID);
    }
    else{
        std::cout << "Error: member does not exist." << std::endl;
    }
}
//setters
void Team::setTeamID(const std::string& teamID){
    this->teamID=teamID;
}
void Team::setLeaderID(const std::string& leaderID){
    this->leaderID=leaderID;
}
void Team::setMemberIDs(const std::string* memberIDs, int size){
    this->memberIDs.clear();
    for(int i=0;i<size;i++){
        this->memberIDs.add(memberIDs[i]);
    }
}
//getters
const std::string& Team::getTeamID() const{
    return teamID;
}
const std::string& Team::getLeaderID() const{
    return leaderID;
}
const std::string* Team::getMemberIDs() const{
    return memberIDs.getList();
}
const Lists<std::string>& Team::getMemberIDsList() const{
    return memberIDs;
}
const std::string& Team::getMemberID(int index) const{
    return memberIDs.get(index);
}
int Team::getSize() const{
    return memberIDs.getSize();
}
//print functions
void Team::print() const{
    std::cout << "Team ID: " << teamID << std::endl;
    std::cout << "Leader ID: " << leaderID << std::endl;
    std::cout << "Members: " << std::endl;
    memberIDs.print();
}
void Team::print(int index) const{
    std::cout << "Member ID: " << memberIDs.get(index) << std::endl;
}
void Team::print(const std::string& fileName) const{
    std::ofstream out;
    out.open(fileName);
    out << "Team ID: " << teamID << std::endl;
    out << "Leader ID: " << leaderID << std::endl;
    out << "Members: " << std::endl;
    memberIDs.print(out);
    out.close();
}
void Team::print(std::ofstream& out) const{
    out << "Team ID: " << teamID << std::endl;
    out << "Leader ID: " << leaderID << std::endl;
    out << "Members: " << std::endl;
    memberIDs.print(out);
}
//read functions
void Team::read(const std::string& fileName){
    std::ifstream in;
    in.open(fileName);
    read(in);
    in.close();
}
void Team::read(std::ifstream& in){
    std::string temp;
    in >> temp;
    setTeamID(temp);
    in >> temp;
    setLeaderID(temp);
    in >> temp;
    memberIDs.read(in);
}
void Team::read(std::istream& in){
    std::string temp;
    in >> temp;
    setTeamID(temp);
    in >> temp;
    setLeaderID(temp);
    in >> temp;
    memberIDs.read(in);
}
//overloaded operators
Team& Team::operator=(const Team& other){
    this->teamID=other.teamID;
    this->leaderID=other.leaderID;
    this->memberIDs=other.memberIDs;
    return *this;
}
bool Team::operator==(const Team& other) const{
    return (this->teamID==other.teamID && this->leaderID==other.leaderID && this->memberIDs==other.memberIDs);
}
bool Team::operator!=(const Team& other) const{
    return !(*this==other);
}
Team& Team::operator+=(const std::string& memberID){
    this->addMember(memberID);
    return *this;
}
Team& Team::operator-=(const std::string& memberID){
    this->removeMember(memberID);
    return *this;
}
Team& Team::operator+=(const Team& other){
    for(int i=0;i<other.getSize();i++){
        this->addMember(other.getMemberID(i));
    }
    return *this;
}
Team& Team::operator-=(const Team& other){
    for(int i=0;i<other.getSize();i++){
        this->removeMember(other.getMemberID(i));
    }
    return *this;
}
Team& Team::operator+(const std::string& memberID) const
{
    Team temp(*this);
    temp+=memberID;
    return temp;
}
Team& Team::operator-(const std::string& memberID) const
{
    Team temp(*this);
    temp-=memberID;
    return temp;
}
Team& Team::operator+(const Team& other) const
{
    Team temp(*this);
    temp+=other;
    return temp;
}
Team& Team::operator-(const Team& other) const
{
    Team temp(*this);
    temp-=other;
    return temp;
}
std::string& Team::operator[](int index) const
{
    return memberIDs.get(index);
}
std::ostream& operator<<(std::ostream& out, const Team& other)
{
    out << "Team ID: " << other.getTeamID() << std::endl;
    out << "Leader ID: " << other.getLeaderID() << std::endl;
    out << "Members: " << std::endl;
    out << other.getMemberIDs();
    return out;
}
std::istream& operator>>(std::istream& in, Team& other)
{
    //in format: {TeamID} {LeaderID} {number of memberID} {MemberID1} {MemberID2} ... {MemberIDn}
    std::string temp;
    int size;
    in >> temp;
    other.setTeamID(temp);
    in >> temp;
    other.setLeaderID(temp);
    in >> size;
    std::string* memberIDs=new std::string[size];
    for(int i=0;i<size;i++){
        in >> temp;
        memberIDs[i]=temp;
    }
    other.setMemberIDs(memberIDs,size);
    delete[] memberIDs;
    return in;
}
std::ifstream& operator>>(std::ifstream& in, Team& other)
{
    //in format: {TeamID} {LeaderID} {number of memberID} {MemberID1} {MemberID2} ... {MemberIDn}
    std::string temp;
    int size;
    in >> temp;
    other.setTeamID(temp);
    in >> temp;
    other.setLeaderID(temp);
    in >> size;
    std::string* memberIDs=new std::string[size];
    for(int i=0;i<size;i++){
        in >> temp;
        memberIDs[i]=temp;
    }
    other.setMemberIDs(memberIDs,size);
    delete[] memberIDs;
    return in;
}
std::ofstream& operator<<(std::ofstream& out, const Team& other)
{
    //in format: {TeamID} {LeaderID} {number of memberID} {MemberID1} {MemberID2} ... {MemberIDn}
    out << other.getTeamID() << " " << other.getLeaderID() << " " << other.getSize() << " ";
    for(int i=0;i<other.getSize()-1;i++){
        out << other.getMemberID(i) << " ";
    }
    out << other.getMemberID(other.getSize()-1) << std::endl;
    return out;
}

