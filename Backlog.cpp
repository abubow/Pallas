#include "Backlog.h"

Backlog::Backlog(){
    ownerID="NULL";
    items.clear();
    editLog.clear();
}

Backlog::Backlog(const Backlog& other){
    ownerID=other.ownerID;
    items=other.items;
    editLog=other.editLog;
}

Backlog::Backlog(const std::string& backlogID, const std::string& ownerID){
    this->backlogID=backlogID;
    this->ownerID=ownerID;
    items.clear();
    editLog.clear();
}

Backlog::~Backlog(){
    items.clear();
    editLog.clear();
}

//adders and removers
bool Backlog::addItem(const Item& item){
    if(items.search(item)){
        std::cout << "Error: item already exists." << std::endl;
        return false;
    }
    else{
        items.add(item);
        return true;
    }
}
bool Backlog::editItem(const Item& item){
    if(items.search(item)){
        items.remove(item);
        items.add(item);
        return true;
    }
    else{
        std::cout << "Error: item does not exist." << std::endl;
        return false;
    }
}
bool Backlog::removeItem(const Item& item){
    if(items.search(item)){
        items.remove(item);
        return true;
    }
    else{
        std::cout << "Error: item does not exist." << std::endl;
        return false;
    }
}
bool Backlog::addEditLogEntry(const EditLog& logEntryID){
    if(editLog.search(logEntryID)){
        std::cout << "Error: edit log entry already exists." << std::endl;
        return false;
    }
    else{
        editLog.add(logEntryID);
        return true;
    }
}
bool Backlog::editEditLogEntry(const EditLog& logEntryID){
    if(editLog.search(logEntryID)){
        editLog.remove(logEntryID);
        editLog.add(logEntryID);
        return true;
    }
    else{
        std::cout << "Error: edit log entry does not exist." << std::endl;
        return false;
    }
}
bool Backlog::removeEditLogEntry(const std::string& logEntryID){
    if(searchInListByID<EditLog>(editLog, logEntryID)){
        removeFromListByID<EditLog>(editLog, logEntryID);
        return true;
    }
    else{
        std::cout << "Error: edit log entry does not exist." << std::endl;
        return false;
    }
}
bool Backlog::removeEditLogEntry(const EditLog& logEntryID){
    if(editLog.search(logEntryID)){
        editLog.remove(logEntryID);
        return true;
    }
    else{
        std::cout << "Error: edit log entry does not exist." << std::endl;
        return false;
    }
}

//setters
void Backlog::setOwnerID(const std::string& ownerID){
    this->ownerID=ownerID;
}
void Backlog::setID(const std::string& backlogID){
    this->backlogID=backlogID;
}
//getters
const std::string& Backlog::getOwnerID() const{
    return ownerID;
}
const std::string& Backlog::getBacklogID() const{
    return backlogID;
}
const Lists<Item>& Backlog::getItems() const{
    return items;
}
const Lists<EditLog>& Backlog::getEditLog() const{
    return editLog;
}
bool Backlog::searchItem(const std::string& itemID) const{
    return searchInListByID<Item>(items, itemID);
}
bool Backlog::searchEditLog(const std::string& editLog) const{
    return searchInListByID<EditLog>(this->editLog, editLog);
}
//sort by value
void Backlog::sortItemsByValue(){
    for (int i = 0; i < items.getSize(); i++)
    {
        for (int j = 0; j < items.getSize() - 1; j++)
        {
            if (items.get(j).getValue() > items.get(j + 1).getValue())
            {
                Item temp = items.get(j);
                items.set(j, items.get(j + 1));
                items.set(j + 1, temp);
            }
        }
    }
}
//operator overloads
Backlog& Backlog::operator=(const Backlog& other){
    if(this!=&other){
        ownerID=other.ownerID;
        items=other.items;
        editLog=other.editLog;
    }
    return *this;
}
Backlog& Backlog::operator+= (const Item& item){
    if(!items.search(item)){
        items.add(item);
    }
    else std::cout << "Error: item already exists." << std::endl;
    return *this;
}
Backlog& Backlog::operator-= (const Item& item){
    if(items.search(item)){
        items.remove(item);
    }
    else std::cout << "Error: item does not exist." << std::endl;
    return *this;
}
Backlog& Backlog::operator+= (const Backlog& other){
    for(int i=0;i<other.items.getSize();i++){
        if(!items.search(other.items.get(i))){
            items.add(other.items.get(i));
        }
    }
    return *this;
}
Backlog& Backlog::operator-= (const Backlog& other){
    for(int i=0;i<other.items.getSize();i++){
        if(items.search(other.items.get(i))){
            items.remove(other.items.get(i));
        }
    }
    return *this;
}
Backlog Backlog::operator+ (const Item& item) const{
    Backlog temp(*this);
    if(!temp.items.search(item)){
        temp.items.add(item);
    }
    else std::cout << "Error: item already exists." << std::endl;
    return temp;
}
Backlog Backlog::operator- (const Item& item) const{
    Backlog temp(*this);
    if(temp.items.search(item)){
        temp.items.remove(item);
    }
    else std::cout << "Error: item does not exist." << std::endl;
    return temp;
}
Backlog Backlog::operator+ (const Backlog& other) const{
    Backlog temp(*this);
    for(int i=0;i<other.items.getSize();i++){
        if(!temp.items.search(other.items.get(i))){
            temp.items.add(other.items.get(i));
        }
    }
    return temp;
}
Backlog Backlog::operator- (const Backlog& other) const{
    Backlog temp(*this);
    for(int i=0;i<other.items.getSize();i++){
        if(temp.items.search(other.items.get(i))){
            temp.items.remove(other.items.get(i));
        }
    }
    return temp;
}
bool Backlog::operator== (const Backlog& other) const{
    if(items.getSize()==other.items.getSize()){
        for(int i=0;i<items.getSize();i++){
            if(!items.search(other.items.get(i))){
                return false;
            }
        }
        return true;
    }
    return false;
}
bool Backlog::operator!= (const Backlog& other) const{
    if(items.getSize()!=other.items.getSize()){
        return true;
    }
    for(int i=0;i<items.getSize();i++){
        if(!items.search(other.items.get(i))){
            return true;
        }
    }
    return false;
}
//friend functions
std::ostream& operator<< (std::ostream& out, const Backlog& backlog){
    out << "Backlog ID: " << backlog.backlogID << " Owner ID: " << backlog.ownerID << std::endl;
    out << "Items: " << std::endl;
    for(int i=0;i<backlog.items.getSize();i++){
        out << backlog.items.get(i) << std::endl;
    }
    out << "Edit Log: " << std::endl;
    for(int i=0;i<backlog.editLog.getSize();i++){
        out << backlog.editLog.get(i) << std::endl;
    }
    return out;
}
std::istream& operator>> (std::istream& in, Backlog& backlog){
    string backlogID, ownerID;
    in >> backlogID >> ownerID;
    backlog.setID(backlogID);
    backlog.setOwnerID(ownerID);
    return in;
}
std::ofstream& operator<< (std::ofstream& out, const Backlog& backlog){
    out << backlog.backlogID << " " << backlog.ownerID << std::endl;
    out << backlog.items.getSize() << std::endl;
    for(int i=0;i<backlog.items.getSize();i++){
        out << backlog.items.get(i) << std::endl;
    }
    out << backlog.editLog.getSize() << std::endl;
    for(int i=0;i<backlog.editLog.getSize();i++){
        out << backlog.editLog.get(i) << std::endl;
    }
    return out;
}
std::ifstream& operator>> (std::ifstream& in, Backlog& backlog){
    string backlogID, ownerID;
    in >> backlogID >> ownerID;
    backlog.setID(backlogID);
    backlog.setOwnerID(ownerID);
    int size;
    in >> size;
    for(int i=0;i<size;i++){
        Item temp;
        in >> temp;
        backlog.items.add(temp);
    }
    in >> size;
    for(int i=0;i<size;i++){
        EditLog temp;
        in >> temp;
        backlog.editLog.add(temp);
    }
    return in;
}

//print functions
void Backlog::print() const{
    std::cout << "Backlog ID: " << backlogID << std::endl;
    std::cout << "Owner ID: " << ownerID << std::endl;
    std::cout << "Items: " << std::endl;
    for(int i=0;i<items.getSize();i++){
        std::cout << items.get(i) << std::endl;
    }
    std::cout << "Edit Log: " << std::endl;
    for(int i=0;i<editLog.getSize();i++){
        std::cout << editLog.get(i) << std::endl;
    }
}
void Backlog::print(std::ofstream& out) const{
    out << "Backlog ID: " << backlogID << std::endl;
    out << "Owner ID: " << ownerID << std::endl;
    out << "Items: " << std::endl;
    for(int i=0;i<items.getSize();i++){
        out << items.get(i) << std::endl;
    }
    out << "Edit Log: " << std::endl;
    for(int i=0;i<editLog.getSize();i++){
        out << editLog.get(i) << std::endl;
    }
}
void Backlog::print(std::string fileName) const{
    std::ofstream out(fileName);
    print(out);
    out.close();
}


//virtual function
void Backlog::finish(Backlog& decendent){
    for(int i=0;i<items.getSize();i++){
        if(items.get(i).getStateOfProgress()=="In Progress"){
            decendent.items.add(items.get(i));
        }
        items.remove(items.get(i));
    }
}