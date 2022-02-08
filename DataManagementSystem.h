#ifndef DATAMANAGEMENTSYSTEM_H
#define DATAMANAGEMENTSYSTEM_H

#pragma once
#include "member.h"
#include "productOwner.h"
#include "developer.h"
#include "testor.h"
#include "Administrator.h"
#include "manager_HR.h"

#include "Backlog.h"
#include "ProductBacklog.h"
#include "SprintBacklog.h"

#include "Team.h"

#include "Sprint.h"

#include "Item.h"
#include "Bug.h"
#include "Feature.h"

#include "Project.h"

#include "RoadMapMangementSytem.h"

#include "Lists.h"

#include <iostream>
using namespace std;
class DataManagementSystem
{
protected:
    Lists<Project> projects;
    Lists<Team> teams;
    Lists<Administrator> administrators;
    Lists<Manager_HR> managers_HR;
    Lists<ProductOwner> productOwners;
    Lists<Developer> developers;
    Lists<Testor> testors;
    Lists<Backlog> backlogs;
    Lists<SprintBacklog> sprintBacklogs;
    Lists<ProductBacklog> productBacklogs;
    Lists<Sprint> sprints;
    Lists<Item> items;
    Lists<Bug> bugs;
    Lists<Feature> features;
    Lists<EditLog> editLogs;
    RoadMapMangementSytem* roadmapManagementSystem;
public:
    DataManagementSystem();
    DataManagementSystem(const DataManagementSystem&);
    DataManagementSystem(const Lists<Project>& projects, const Lists<Team>& teams, const Lists<Administrator>& administrators, const Lists<Manager_HR>& managers_HR, const Lists<ProductOwner>& productOwners, const Lists<Developer>& developers, const Lists<Testor>& testors, const Lists<Backlog>& backlogs, const Lists<SprintBacklog>& sprintBacklogs, const Lists<ProductBacklog>& productBacklogs, const Lists<Sprint>& sprints, const Lists<Item>& items, const Lists<Bug>& bugs, const Lists<Feature>& features, const Lists<EditLog>& editLogs, RoadMapMangementSytem* roadmapManagementSystem);
    //destructor
    ~DataManagementSystem();
    //adder functions
    bool addProject(const Project& project);
    bool addTeam(const Team& team);
    bool addAdministrator(const Administrator& administrator);
    bool addManager_HR(const Manager_HR& manager_HR);
    bool addProductOwner(const ProductOwner& productOwner);
    bool addDeveloper(const Developer& developer);
    bool addTestor(const Testor& testor);
    bool addBacklog(const Backlog& backlog);
    bool addSprintBacklog(const SprintBacklog& sprintBacklog);
    bool addProductBacklog(const ProductBacklog& productBacklog);
    bool addSprint(const Sprint& sprint);
    bool addItem(const Item& item);
    bool addBug(const Bug& bug);
    bool addFeature(const Feature& feature);
    bool addEditLog(const EditLog& editLog);
    bool addRoadMapMangementSytem(RoadMapMangementSytem* roadmapManagementSystem);
    //setters
    void setProjects(const Lists<Project>& projects);
    void setTeams(const Lists<Team>& teams);
    void setAdministrators(const Lists<Administrator>& administrators);
    void setManagers_HR(const Lists<Manager_HR>& managers_HR);
    void setProductOwners(const Lists<ProductOwner>& productOwners);
    void setDevelopers(const Lists<Developer>& developers);
    void setTestors(const Lists<Testor>& testors);
    void setBacklogs(const Lists<Backlog>& backlogs);
    void setSprintBacklogs(const Lists<SprintBacklog>& sprintBacklogs);
    void setProductBacklogs(const Lists<ProductBacklog>& productBacklogs);
    void setSprints(const Lists<Sprint>& sprints);
    void setItems(const Lists<Item>& items);
    void setBugs(const Lists<Bug>& bugs);
    void setFeatures(const Lists<Feature>& features);
    void setEditLogs(const Lists<EditLog>& editLogs);
    void setRoadMapMangementSytem(RoadMapMangementSytem* roadmapManagementSystem);
    //getters
    const Lists<Project>& getProjects() const;
    const Lists<Team>& getTeams() const;
    const Lists<Administrator>& getAdministrators() const;
    const Lists<Manager_HR>& getManagers_HR() const;
    const Lists<ProductOwner>& getProductOwners() const;
    const Lists<Developer>& getDevelopers() const;
    const Lists<Testor>& getTestors() const;
    const Lists<Backlog>& getBacklogs() const;
    const Lists<SprintBacklog>& getSprintBacklogs() const;
    const Lists<ProductBacklog>& getProductBacklogs() const;
    const Lists<Sprint>& getSprints() const;
    const Lists<Item>& getItems() const;
    const Lists<Bug>& getBugs() const;
    const Lists<Feature>& getFeatures() const;
    const Lists<EditLog>& getEditLogs() const;
    RoadMapMangementSytem* getRoadMapMangementSytem() const;
    //remove functions
    bool removeProject(const Project& project);
    bool removeTeam(const Team& team);
    bool removeAdministrator(const Administrator& administrator);
    bool removeManager_HR(const Manager_HR& manager_HR);
    bool removeProductOwner(const ProductOwner& productOwner);
    bool removeDeveloper(const Developer& developer);
    bool removeTestor(const Testor& testor);
    bool removeBacklog(const Backlog& backlog);
    bool removeSprintBacklog(const SprintBacklog& sprintBacklog);
    bool removeProductBacklog(const ProductBacklog& productBacklog);
    bool removeSprint(const Sprint& sprint);
    bool removeItem(const Item& item);
    bool removeBug(const Bug& bug);
    bool removeFeature(const Feature& feature);
    bool removeEditLog(const EditLog& editLog);
    bool removeRoadMapMangementSytem(RoadMapMangementSytem* roadmapManagementSystem);
    bool removeRoadMapMangementSytem(const RoadMapMangementSytem& roadmapManagementSystem);
    //edit functions
    bool editProject(const Project& oldProject, const Project& newProject);
    bool editTeam(const Team& oldTeam, const Team& newTeam);
    bool editAdministrator(const Administrator& oldAdministrator, const Administrator& newAdministrator);
    bool editManager_HR(const Manager_HR& oldManager_HR, const Manager_HR& newManager_HR);
    bool editProductOwner(const ProductOwner& oldProductOwner, const ProductOwner& newProductOwner);
    bool editDeveloper(const Developer& oldDeveloper, const Developer& newDeveloper);
    bool editTestor(const Testor& oldTestor, const Testor& newTestor);
    bool editBacklog(const Backlog& oldBacklog, const Backlog& newBacklog);
    bool editSprintBacklog(const SprintBacklog& oldSprintBacklog, const SprintBacklog& newSprintBacklog);
    bool editProductBacklog(const ProductBacklog& oldProductBacklog, const ProductBacklog& newProductBacklog);
    bool editSprint(const Sprint& oldSprint, const Sprint& newSprint);
    bool editItem(const Item& oldItem, const Item& newItem);
    bool editBug(const Bug& oldBug, const Bug& newBug);
    bool editFeature(const Feature& oldFeature, const Feature& newFeature);
    bool editEditLog(const EditLog& oldEditLog, const EditLog& newEditLog);
    bool editRoadMapMangementSytem(RoadMapMangementSytem* oldRoadMapMangementSytem, RoadMapMangementSytem* newRoadMapMangementSytem);
    bool editRoadMapMangementSytem(const RoadMapMangementSytem& oldRoadMapMangementSytem, RoadMapMangementSytem *newRoadMapMangementSytem);
    //Management functions
    bool authenticate(const string& username, const string& password);
    string& getDataRecords();
    void setDataRecords(const string& dataRecords);
    //encryption functions
    string& encrypt(const string& data);
    string& decrypt(const string& data);
    //compression functions
    string& compress(const string& data);
    string& decompress(const string& data);
    //pdf functions
    string& generatePDF(const string& data);
    string& generatePDF(const string& data, const string& fileName);
    
};
#endif // !DATAMANAGEMENTSYSTEM_H