//
//  Family.cpp
//  MeetTheFamily
//
//  Created by Kunal Kalra on 20/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../Models/Family.h"
#include "../Models/Person.h"

//Constructor
Family::Family(Person* husband, Person* wife, vector <Person *> children) {
    this->husband = husband;
    this->wife = wife;
    this->children = children;
}


//Methods
bool Family::hasChild(string personName) {
    vector <Person*> children = this->getChildren();
    for(int i=0; i<children.size(); i++) {
        if(children[i]->getName() == personName) return true;
    }
    return false;
}

bool Family::isFamilyOf(string personName) {
    return (this->getHusband()->getName() == personName || this->getWife()->getName() == personName);
}

bool Family::hasMember(string personName) {
    return this->hasChild(personName) || this->isFamilyOf(personName);
}

void Family::addToChildren(string childName, Gender gender) {
    Person* child = new Person(childName, gender);
    this->children.push_back(child);
}


//Getters
Person* Family::getHusband() {
    return this->husband;
}

Person* Family::getWife() {
    return this->wife;
}

vector <Person*> Family::getChildren() {
    return this->children;
}

unordered_map<Person*, Family*> Family::getFamilyOfChildren() {
    return this->familyOfChildren;
}

//Setters
void Family::setFamilyOfChildren(Person *child, Family *family) {
    if(!this->hasChild(child->getName())) {
        cout << "The family does not have this child, hence it cannot be added";
        return;
    }
    unordered_map <Person*, Family*> familyOfChildren = this->getFamilyOfChildren();
    familyOfChildren[child] = family;
}



