#ifndef ITEM_H
#define ITEM_H
#pragma once
#include "Lists.h"
#include "member.h"
class Item
{
protected:
    string title;
    string description;
    Lists<string> Features;
    Lists<string> recommendationsIds;
    Lists<string> commentsIds;
    Lists<string> attachmentsIds;
    Lists<string> dependencies;
    string stageOfApproval;
    string ProjectId;
    string itemId;
    string stateOfProgress;
    Lists<string> Dates;
    double expectedComplexity;
    double value;
    double priority;
    double complexity;
    double timeRequired;
    double timeSpent;
public:
    Item();
    Item(const Item&);
    Item(const string& title, const string& description, const string& stageOfApproval, const string& ProjectId, const string& id, const string& stateOfProgress, const double& expectedComplexity, const double& value, const double& priority, const double& complexity, const double& timeRequired, const double& timeSpent);
    ~Item();
    //adders and removers
    bool addFeature(const string& feature);
    bool addRecommendation(const string& recommendation);
    bool addComment(const string& comment);
    bool addAttachment(const string& attachment);
	bool addDependency(const string& itemID);
	/*add sub items that would contain items within the item that composes the Item*/
	bool removeDependency(const string& itemID);
    bool removeFeature(const string& feature);
    bool removeRecommendation(const string& recommendation);
    bool removeComment(const string& comment);
    bool removeAttachment(const string& attachment);
    //setters
    void setTitle(const string& title);
    void setDescription(const string& description);
    void setStageOfApproval(const string& stageOfApproval);
    void setProjectId(const string& ProjectId);
    void setId(const string& id);
    void setStateOfProgress(const string& stateOfProgress);
    void setExpectedComplexity(const double& expectedComplexity);
    void setValue(const double& value);
    void setPriority(const double& priority);
    void setComplexity(const double& complexity);
    void setTimeRequired(const double& timeRequired);
    void setTimeSpent(const double& timeSpent);
    //getters
    string getTitle() const;
    string getDescription() const;
    Lists<string> getFeatures() const;
    Lists<string> getRecommendationsIds() const;
    Lists<string> getCommentsIds() const;
    Lists<string> getAttachmentsIds() const;
    Lists<string> getDependencies() const;
    string getStageOfApproval() const;
    string getProjectId() const;
    string getId() const;
    string getStateOfProgress() const;
    double getExpectedComplexity() const;
    double getValue() const;
    double getPriority() const;
    double getComplexity() const;
    double getTimeRequired() const;
    double getTimeSpent() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    //virtual functions
    virtual string getItemInfo() const;
    //overloaded operators
    Item& operator=(const Item& item);
    bool operator==(const Item& item) const;
    bool operator!=(const Item& item) const;
    //friend functions
    friend ofstream& operator<<(ofstream& out, const Item& item);
    friend ifstream& operator>>(ifstream& in, Item& item);
    friend ostream& operator<<(ostream& out, const Item& item);
    friend istream& operator>>(istream& in, Item& item);
};
#endif // !ITEM_H