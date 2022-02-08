#include "Item.h"

Item::Item(){
    title="NULL";
    description="NULL";
    stageOfApproval="NULL";
    priority=0;
    itemId="NULL";
    stateOfProgress="NULL";
    expectedComplexity=0;
    value=0;
    complexity=0;
    timeRequired=0;
    timeSpent=0;
}

Item::Item(const Item& other){
    title=other.title;
    description=other.description;
    stageOfApproval=other.stageOfApproval;
    priority=other.priority;
    itemId=other.itemId;
    stateOfProgress=other.stateOfProgress;
    expectedComplexity=other.expectedComplexity;
    value=other.value;
    complexity=other.complexity;
    timeRequired=other.timeRequired;
    timeSpent=other.timeSpent;
}


Item::Item(const string& title, const string& description, const string& stageOfApproval, const string& ProjectId, const string& id, const string& stateOfProgress, const double& expectedComplexity, const double& value, const double& priority, const double& complexity, const double& timeRequired, const double& timeSpent){
    this->title=title;
    this->description=description;
    this->stageOfApproval=stageOfApproval;
    this->ProjectId=ProjectId;
    this->itemId=id;
    this->stateOfProgress=stateOfProgress;
    this->expectedComplexity=expectedComplexity;
    this->value=value;
    this->priority=priority;
    this->complexity=complexity;
    this->timeRequired=timeRequired;
    this->timeSpent=timeSpent;
}

Item::~Item(){

}

//adders
bool Item::addFeature(const string& feature){
    if (!Features.search(feature)){
        Features.add(feature);
        return true;
    }
    else{
        cout << "Error: Feature already exists" << endl;
        return false;
    }
}

bool Item::addDependency(const string& dependency){
    if (!dependencies.search(dependency)){
        dependencies.add(dependency);
        return true;
    }
    else{
        cout << "Error: Dependency already exists" << endl;
        return false;
    }
}

bool Item::addRecommendation(const string& recommendation){
    if (!recommendationsIds.search(recommendation)){
        recommendationsIds.add(recommendation);
        return true;
    }
    else{
        cout << "Error: Recommendation already exists" << endl;
        return false;
    }
}

bool Item::addComment(const string& comment){
    if (!commentsIds.search(comment)){
        commentsIds.add(comment);
        return true;
    }
    else{
        cout << "Error: Comment already exists" << endl;
        return false;
    }
}

bool Item::addAttachment(const string& attachment){
    if (!attachmentsIds.search(attachment)){
        attachmentsIds.add(attachment);
        return true;
    }
    else{
        cout << "Error: Attachment already exists" << endl;
        return false;
    }
}

//removers
bool Item::removeFeature(const string& feature){
    if (Features.search(feature)){
        Features.remove(feature);
        return true;
    }
    else{
        cout << "Error: Feature does not exist" << endl;
        return false;
    }
}

bool Item::removeDependency(const string& dependency){
    if (dependencies.search(dependency)){
        dependencies.remove(dependency);
        return true;
    }
    else{
        cout << "Error: Dependency does not exist" << endl;
        return false;
    }
}

bool Item::removeRecommendation(const string& recommendation){
    if (recommendationsIds.search(recommendation)){
        recommendationsIds.remove(recommendation);
        return true;
    }
    else{
        cout << "Error: Recommendation does not exist" << endl;
        return false;
    }
}

bool Item::removeComment(const string& comment){
    if (commentsIds.search(comment)){
        commentsIds.remove(comment);
        return true;
    }
    else{
        cout << "Error: Comment does not exist" << endl;
        return false;
    }
}

bool Item::removeAttachment(const string& attachment){
    if (attachmentsIds.search(attachment)){
        attachmentsIds.remove(attachment);
        return true;
    }
    else{
        cout << "Error: Attachment does not exist" << endl;
        return false;
    }
}

//setters
void Item::setTitle(const string& title){
    this->title=title;
}

void Item::setDescription(const string& description){
    this->description=description;
}

void Item::setStageOfApproval(const string& stageOfApproval){
    this->stageOfApproval=stageOfApproval;
}

void Item::setProjectId(const string& ProjectId){
    this->ProjectId=ProjectId;
}

void Item::setId(const string& itemId){
    this->itemId=itemId;
}

void Item::setStateOfProgress(const string& stateOfProgress){
    this->stateOfProgress=stateOfProgress;
}

void Item::setExpectedComplexity(const double& expectedComplexity){
    this->expectedComplexity=expectedComplexity;
}

void Item::setValue(const double& value){
    this->value=value;
}

void Item::setPriority(const double& priority){
    this->priority=priority;
}

void Item::setComplexity(const double& complexity){
    this->complexity=complexity;
}

void Item::setTimeRequired(const double& timeRequired){
    this->timeRequired=timeRequired;
}

void Item::setTimeSpent(const double& timeSpent){
    this->timeSpent=timeSpent;
}

//getters
string Item::getTitle() const{
    return title;
}

string Item::getDescription() const{
    return description;
}

string Item::getStageOfApproval() const{
    return stageOfApproval;
}

string Item::getProjectId() const{
    return ProjectId;
}

string Item::getId() const{
    return itemId;
}

string Item::getStateOfProgress() const{
    return stateOfProgress;
}

double Item::getExpectedComplexity() const{
    return expectedComplexity;
}

double Item::getValue() const{
    return value;
}

double Item::getPriority() const{
    return priority;
}

double Item::getComplexity() const{
    return complexity;
}

double Item::getTimeRequired() const{
    return timeRequired;
}

double Item::getTimeSpent() const{
    return timeSpent;
}
Lists<string> Item::getFeatures() const{
    return Features;
}
Lists<string> Item::getDependencies() const{
    return dependencies;
}
Lists<string> Item::getRecommendationsIds() const{
    return recommendationsIds;
}
Lists<string> Item::getCommentsIds() const{
    return commentsIds;
}
Lists<string> Item::getAttachmentsIds() const{
    return attachmentsIds;
}

//print functions
void Item::print() const {
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Stage of approval: " << stageOfApproval << endl;
    cout << "Project ID: " << ProjectId << endl;
    cout << "Item ID: " << itemId << endl;
    cout << "State of progress: " << stateOfProgress << endl;
    cout << "Expected complexity: " << expectedComplexity << endl;
    cout << "Value: " << value << endl;
    cout << "Priority: " << priority << endl;
    cout << "Complexity: " << complexity << endl;
    cout << "Time required: " << timeRequired << endl;
    cout << "Time spent: " << timeSpent << endl;
    cout << "Features: " << endl;
    Features.print();
    cout << "Dependencies: " << endl;
    dependencies.print();
    cout << "Recommendations: " << endl;
    recommendationsIds.print();
    cout << "Comments: " << endl;
    commentsIds.print();
    cout << "Attachments: " << endl;
    attachmentsIds.print();
}

void Item::print(const string& fileName) const{
    ofstream file;
    file.open(fileName);
    file << *this;
}

void Item::print(ofstream& file) const{
    file << *this;
}

//read functions
void Item::read(const string& fileName){
    ifstream file;
    file.open(fileName);
    file >> *this;
}

void Item::read(ifstream& file){
    file >> *this;
}

//virtual functions
string Item::getItemInfo() const{
    stringstream ss;
    ss << "Title: " << title << endl;
    ss << "Description: " << description << endl;
    ss << "Stage of approval: " << stageOfApproval << endl;
    ss << "Project ID: " << ProjectId << endl;
    ss << "Item ID: " << itemId << endl;
    ss << "State of progress: " << stateOfProgress << endl;
    ss << "Expected complexity: " << expectedComplexity << endl;
    ss << "Value: " << value << endl;
    ss << "Priority: " << priority << endl;
    ss << "Complexity: " << complexity << endl;
    ss << "Time required: " << timeRequired << endl;
    ss << "Time spent: " << timeSpent << endl;
    ss << "Features: " << endl;
    ss << Features;
    ss << "Dependencies: " << endl;
    ss << dependencies;
    ss << "Recommendations: " << endl;
    ss << recommendationsIds;
    ss << "Comments: " << endl;
    ss << commentsIds;
    ss << "Attachments: " << endl;
    ss << attachmentsIds;
    return ss.str();
}

//operators overloading
Item& Item::operator=(const Item& item){
    if (this!=&item){
        title=item.title;
        description=item.description;
        stageOfApproval=item.stageOfApproval;
        ProjectId=item.ProjectId;
        itemId=item.itemId;
        stateOfProgress=item.stateOfProgress;
        expectedComplexity=item.expectedComplexity;
        value=item.value;
        priority=item.priority;
        complexity=item.complexity;
        timeRequired=item.timeRequired;
        timeSpent=item.timeSpent;
        Features=item.Features;
        dependencies=item.dependencies;
        recommendationsIds=item.recommendationsIds;
        commentsIds=item.commentsIds;
        attachmentsIds=item.attachmentsIds;
    }
    return *this;
}

bool Item::operator==(const Item& item) const{
    bool isEqual=true;
    if (title!=item.title||description!=item.description||stageOfApproval!=item.stageOfApproval||ProjectId!=item.ProjectId||itemId!=item.itemId||stateOfProgress!=item.stateOfProgress||expectedComplexity!=item.expectedComplexity||value!=item.value||priority!=item.priority||complexity!=item.complexity||timeRequired!=item.timeRequired||timeSpent!=item.timeSpent||Features!=item.Features||dependencies!=item.dependencies||recommendationsIds!=item.recommendationsIds||commentsIds!=item.commentsIds||attachmentsIds!=item.attachmentsIds){
        isEqual=false;
    }
    return isEqual;
}

bool Item::operator!=(const Item& item) const{
    return !(*this==item);
}

//friend functions
ostream& operator<<(ostream& os, const Item& item){
    os << "Title: " << item.title << endl;
    os << "Description: " << item.description << endl;
    os << "Stage of approval: " << item.stageOfApproval << endl;
    os << "Project ID: " << item.ProjectId << endl;
    os << "Item ID: " << item.itemId << endl;
    os << "State of progress: " << item.stateOfProgress << endl;
    os << "Expected complexity: " << item.expectedComplexity << endl;
    os << "Value: " << item.value << endl;
    os << "Priority: " << item.priority << endl;
    os << "Complexity: " << item.complexity << endl;
    os << "Time required: " << item.timeRequired << endl;
    os << "Time spent: " << item.timeSpent << endl;
    os << "Features: " << endl;
    os << item.Features;
    os << "Dependencies: " << endl;
    os << item.dependencies;
    os << "Recommendations: " << endl;
    os << item.recommendationsIds;
    os << "Comments: " << endl;
    os << item.commentsIds;
    os << "Attachments: " << endl;
    os << item.attachmentsIds;
    return os;
}

ofstream& operator<<(ofstream& os, const Item& item){
    os << "Title: " << item.title << endl;
    os << "Description: " << item.description << endl;
    os << "Stage of approval: " << item.stageOfApproval << endl;
    os << "Project ID: " << item.ProjectId << endl;
    os << "Item ID: " << item.itemId << endl;
    os << "State of progress: " << item.stateOfProgress << endl;
    os << "Expected complexity: " << item.expectedComplexity << endl;
    os << "Value: " << item.value << endl;
    os << "Priority: " << item.priority << endl;
    os << "Complexity: " << item.complexity << endl;
    os << "Time required: " << item.timeRequired << endl;
    os << "Time spent: " << item.timeSpent << endl;
    os << "Features: " << endl;
    os << item.Features;
    os << "Dependencies: " << endl;
    os << item.dependencies;
    os << "Recommendations: " << endl;
    os << item.recommendationsIds;
    os << "Comments: " << endl;
    os << item.commentsIds;
    os << "Attachments: " << endl;
    os << item.attachmentsIds;
    return os;
}

istream& operator>>(istream& is, Item& item){
    is >> item.title;
    is >> item.description;
    is >> item.stageOfApproval;
    is >> item.ProjectId;
    is >> item.itemId;
    is >> item.stateOfProgress;
    is >> item.expectedComplexity;
    is >> item.value;
    is >> item.priority;
    is >> item.complexity;
    is >> item.timeRequired;
    is >> item.timeSpent;
    is >> item.Features;
    is >> item.dependencies;
    is >> item.recommendationsIds;
    is >> item.commentsIds;
    is >> item.attachmentsIds;
    return is;
}

ifstream& operator>>(ifstream& is, Item& item){
    is >> item.title;
    is >> item.description;
    is >> item.stageOfApproval;
    is >> item.ProjectId;
    is >> item.itemId;
    is >> item.stateOfProgress;
    is >> item.expectedComplexity;
    is >> item.value;
    is >> item.priority;
    is >> item.complexity;
    is >> item.timeRequired;
    is >> item.timeSpent;
    is >> item.Features;
    is >> item.dependencies;
    is >> item.recommendationsIds;
    is >> item.commentsIds;
    is >> item.attachmentsIds;
    return is;
}

