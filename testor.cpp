#include "testor.h"

//constructor
Testor::Testor(){
}
Testor::Testor(const Testor& other){
    this->teamIDs.clear();
    this->teamIDs=other.teamIDs;
}
Testor::Testor(const std::string& teamID){
    this->teamIDs.clear();
    this->teamIDs.add(teamID);
}
//destructor
Testor::~Testor(){
}
//adders and removers
bool Testor::addTeam(const std::string& teamID){
    if(teamIDs.search(teamID)){
        std::cout << "Error: team already exists." << std::endl;
        return false;
    }
    else{
        teamIDs.add(teamID);
        return true;
    }
}
bool Testor::removeTeam(const std::string& teamID){
    if(teamIDs.search(teamID)){
        teamIDs.remove(teamID);
        return true;
    }
    else{
        std::cout << "Error: team does not exist." << std::endl;
        return false;
    }
}
//setters
void Testor::setTeams(const std::string* teamIDs, int size){
    this->teamIDs.clear();
    for(int i=0;i<size;i++){
        this->teamIDs.add(teamIDs[i]);
    }
}
//getters
const std::string* Testor::getTeams() const{
    return teamIDs.getList();
}
const Lists<std::string>& Testor::getTeamsList() const{
    return teamIDs;
}
//search functions
bool Testor::searchTeam(const std::string& teamID) const{
    return teamIDs.search(teamID);
}
//Testor functions
bool Testor::changeItemStaus(const std::string& newStatus, Item& item){
    if(item.getStateOfProgress()==newStatus){
        std::cout << "Error: item status is already " << newStatus << "." << std::endl;
        return false;
    }
    else{
        item.setStateOfProgress(newStatus);
        return true;
    }
}
