#ifndef FEAUTURE_H
#define FEAUTURE_H
#pragma once
#include "Item.h"
class Feature :
    public Item
{
private:
    std::string requesterID;
    double estimatedTime;
    double estimatedValue;
public:
    Feature();
    Feature(const std::string& featureID, const std::string& requesterID, const std::string& ownerID, const std::string& title, const std::string& description, const double& estimatedTime, const double& estimatedValue);
    Feature(const Feature&);
    ~Feature();
    //setters
    void setRequesterID(const std::string& requesterID);
    void setEstimatedTime(const double& estimatedTime);
    void setEstimatedValue(const double& estimatedValue);
    //getters
    std::string getRequesterID() const;
    double getEstimatedTime() const;
    double getEstimatedValue() const;
    //print functions
    void print() const override;
    void print(const std::string& fileName) const override;
    void print(std::ofstream& out) const override;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    Feature& operator=(const Feature&);
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const Feature& feature);
    friend std::istream& operator>>(std::istream& in, Feature& feature);
    friend std::ofstream& operator<<(std::ofstream& out, const Feature& feature);
    friend std::ifstream& operator>>(std::ifstream& in, Feature& feature);
};
#endif // !FEAUTURE_H