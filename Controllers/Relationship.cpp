//
//  Relationship.cpp
//  MeetTheFamily
//
//  Created by Kunal Kalra on 23/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "../Models/Relationship.h"

Relationship::Relationship(FamilyTree* familyTree) {
    this->familyTree = familyTree;
}

vector <Person*> Relationship::getPaternalUncles(string name) {
    vector <Person*> paternalUncles;
    Family* childFamily = this->familyTree->findChildFamily(name);
    string fatherName = childFamily->getHusband()->getName();
    vector <Person*> fatherSiblings = this->getSiblings(fatherName);
    
    for(int i=0; i<fatherSiblings.size(); i++) {
        if(fatherSiblings[i]->getGender() == male)
            paternalUncles.push_back(fatherSiblings[i]);
    }
    
    return paternalUncles;
}

vector <Person*> Relationship::getMaternalUncles(string name) {
    vector <Person*> maternalUncles;
    Family* childFamily = this->familyTree->findChildFamily(name);
    string motherName = childFamily->getWife()->getName();
    vector <Person*> motherSiblings = this->getSiblings(motherName);
    
    for(int i=0; i<motherSiblings.size(); i++) {
        if(motherSiblings[i]->getGender() == male)
            maternalUncles.push_back(motherSiblings[i]);
    }
    return maternalUncles;
}

vector <Person*> Relationship::getPaternalAunts(string name) {
    vector <Person*> paternalAunts;
    Family* childFamily = this->familyTree->findChildFamily(name);
    string fatherName = childFamily->getHusband()->getName();
    vector <Person*> fatherSiblings = this->getSiblings(fatherName);
    
    for(int i=0; i<fatherSiblings.size(); i++) {
        if(fatherSiblings[i]->getGender() == female)
            paternalAunts.push_back(fatherSiblings[i]);
    }
    
    return paternalAunts;
}

vector <Person*> Relationship::getMaternalAunts(string name) {
    vector <Person*> maternalAunts;
    Family* childFamily = this->familyTree->findChildFamily(name);
    string motherName = childFamily->getWife()->getName();
    vector <Person*> motherSiblings = this->getSiblings(motherName);
    
    for(int i=0; i<motherSiblings.size(); i++) {
        if(motherSiblings[i]->getGender() == female)
            maternalAunts.push_back(motherSiblings[i]);
    }
    return maternalAunts;
}

vector <Person*> Relationship::getSons(string name) {
    vector <Person*> sons;
    Family* parentFamily = this->familyTree->findParentFamily(name);
    vector <Person*> children = parentFamily->getChildren();
    
    for(int i=0; i<children.size(); i++) {
        if(children[i]->getGender() == male)
            sons.push_back(children[i]);
    }
    return sons;
}

vector <Person*> Relationship::getDaughters(string name) {
    vector <Person*> daughters;
    Family* parentFamily = this->familyTree->findParentFamily(name);
    vector <Person*> children = parentFamily->getChildren();
    
    for(int i=0; i<children.size(); i++) {
        if(children[i]->getGender() == female)
            daughters.push_back(children[i]);
    }
    return daughters;
}

vector <Person*> Relationship::getSiblings(string name) {
    vector <Person*> siblings;
    Family* childFamily = this->familyTree->findChildFamily(name);
    if(childFamily == NULL)
        return siblings;
    vector <Person*> children = childFamily->getChildren();
    
    for(int i=0; i<children.size(); i++) {
        if(children[i]->getName() != name)
            siblings.push_back(children[i]);
    }
    
    return siblings;
}

vector <Person*> Relationship::getBrothersInLaw(string name) {
    vector <Person*> brothersInLaw;
    //Spouse's brothers
    Family* parentFamily = this->familyTree->findParentFamily(name);
    Person* spouse = NULL;
    if(parentFamily->getWife()->getName() == name)
        spouse = parentFamily->getHusband();
    else if(parentFamily->getHusband()->getName() == name)
        spouse = parentFamily->getWife();
    
    vector <Person*> spouseSiblings = this->getSiblings(spouse->getName());
    
    for(int i=0; i<spouseSiblings.size(); i++) {
        if(spouseSiblings[i]->getGender() == male)
            brothersInLaw.push_back(spouseSiblings[i]);
    }
    
    //Husbands of Siblings
    vector <Person*> siblings = this->getSiblings(name);
    if(siblings.empty())
        return brothersInLaw;
    for(int i=0; i<siblings.size(); i++) {
        Family* siblingFamily = this->familyTree->findParentFamily(siblings[i]->getName());
        if(siblings[i]->getGender() == female && siblingFamily != NULL) {
            brothersInLaw.push_back(siblingFamily->getHusband());
        }
    }
    
    return brothersInLaw;
}

vector <Person*> Relationship::getSistersInLaw(string name) {
    vector <Person*> sistersInLaw;
    //Spouse's sister
    Family* parentFamily = this->familyTree->findParentFamily(name);
    cout << "Parent family: " << parentFamily->getHusband()->getName() << " " << parentFamily->getWife()->getName() << endl;
    Person* spouse = NULL;
    if(parentFamily->getWife()->getName() == name)
        spouse = parentFamily->getHusband();
    else if(parentFamily->getHusband()->getName() == name)
        spouse = parentFamily->getWife();
    
    vector <Person*> spouseSiblings = this->getSiblings(spouse->getName());
    for(int i=0; i<spouseSiblings.size(); i++) {
        if(spouseSiblings[i]->getGender() == female)
            sistersInLaw.push_back(spouseSiblings[i]);
    }
    
    //Wife of Siblings
    vector <Person*> siblings = this->getSiblings(name);
    if(siblings.empty())
        return sistersInLaw;
    
    for(int i=0; i<siblings.size(); i++) {
        Family* siblingFamily = this->familyTree->findParentFamily(siblings[i]->getName());
        if(siblings[i]->getGender() == male && siblingFamily != NULL) {
            sistersInLaw.push_back(siblingFamily->getWife());
        }
    }
    return sistersInLaw;
}

Person* Relationship::getFather(string name) {
    Family* childFamily = this->familyTree->findChildFamily(name);
    return childFamily->getHusband();
}
Person* Relationship::getMother(string name) {
    Family* childFamily = this->familyTree->findChildFamily(name);
    return childFamily->getWife();
}
