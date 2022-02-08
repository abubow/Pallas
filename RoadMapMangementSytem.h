#ifndef ROADMAPMANGEMENTSYSTEM_H
#define ROADMAPMANGEMENTSYSTEM_H
#pragma once
#include <iostream>
#include <fstream>
#include "Lists.h"
#include "RoadMap.h"
class RoadMapMangementSytem
{
private:
    Lists<RoadMap> roadMapList;
    std::string roadMapMangementSytemID;
public:
    RoadMapMangementSytem();
    RoadMapMangementSytem(const std::string& roadMapMangementSytemID);
    RoadMapMangementSytem(const std::string& roadMapMangementSytemID, const Lists<RoadMap>& roadMapList);
    RoadMapMangementSytem(const RoadMapMangementSytem&);
    ~RoadMapMangementSytem();
    //setters
    void setRoadMapMangementSytemID(const std::string& roadMapMangementSytemID);
    void setRoadMapList(const Lists<RoadMap>& roadMapList);
    //getters
    std::string getRoadMapMangementSytemID() const;
    Lists<RoadMap> getRoadMapList() const;
    //print functions
    void print() const;
    void print(const std::string& fileName) const;
    void print(std::ofstream& out) const;
    //read functions
    void read(const std::string& fileName);
    void read(std::ifstream& in);
    void read(std::istream& in);
    //operator overloads
    RoadMapMangementSytem& operator=(const RoadMapMangementSytem&);
    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const RoadMapMangementSytem& roadMapMangementSytem);
    friend std::istream& operator>>(std::istream& in, RoadMapMangementSytem& roadMapMangementSytem);
    friend std::ofstream& operator<<(std::ofstream& out, const RoadMapMangementSytem& roadMapMangementSytem);
    friend std::ifstream& operator>>(std::ifstream& in, RoadMapMangementSytem& roadMapMangementSytem);
};
#endif // !ROADMAPMANGEMENTSYSTEM_H
