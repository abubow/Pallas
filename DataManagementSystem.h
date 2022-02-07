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
    Lists<Project> projects;
    Lists<Backlog> backlogs;
    Lists<SprintBacklog> sprintBacklogs;
    Lists<ProductBacklog> productBacklogs;
    Lists<Sprint> sprints;
    Lists<Item> items;
    Lists<Bug> bugs;
    Lists<Feature> features;
};
#endif // !DATAMANAGEMENTSYSTEM_H