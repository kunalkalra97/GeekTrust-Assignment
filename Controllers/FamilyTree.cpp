//
//  FamilyTree.cpp
//  MeetTheFamily
//
//  Created by Kunal Kalra on 21/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include "../Models/FamilyTree.h"
#include "../Models/Family.h"

using namespace std;


//Constructors
FamilyTree::FamilyTree(Family* rootFamily) {
    this->rootFamily = rootFamily;
}

Family* FamilyTree::findChildFamily(string name) {
    queue <Family*> familyQueue;
    familyQueue.push(this->rootFamily);
    
    //Breadth-First search to find Family, staring with root node
    while(!familyQueue.empty()) {
        Family* tempFamily = familyQueue.front();
        if(tempFamily->hasChild(name))
            return tempFamily;
        
        // Get all children with families and add their families to the queue
        unordered_map<Person*, Family*> familyOfChildren = tempFamily->getFamilyOfChildren();
        
        for(auto it = familyOfChildren.begin(); it != familyOfChildren.end(); it++)
            familyQueue.push(it->second);
        
        familyQueue.pop();
        
    }
    return NULL;
}

Family* FamilyTree::findParentFamily(string name) {
    queue <Family*> familyQueue;
    familyQueue.push(this->rootFamily);
    
    //Breadth-First search to find Family, staring with root node
    while(!familyQueue.empty()) {
        Family* tempFamily = familyQueue.front();
        if(tempFamily->isFamilyOf(name)) return tempFamily;
        
        // Get all children with families and add their families to the queue
        unordered_map<Person*, Family*> familyOfChildren = tempFamily->getFamilyOfChildren();
        
        for(auto it = familyOfChildren.begin(); it != familyOfChildren.end(); it++)
            familyQueue.push(it->second);
        
        familyQueue.pop();
        
    }
    cout << "Family could not be found, returning NULL";
    return NULL;
}


//Getters
Family* FamilyTree::getRootFamily() {
    return this->rootFamily;
}

//Methods

void FamilyTree::addFamily(Family *family) {
    Person* husband= family->getHusband();
    Person* wife = family->getWife();
    Family* husbandFamily = this->findChildFamily(husband->getName());
    Family* wifeFamily = this->findChildFamily(wife->getName());
    
    if(husbandFamily == NULL && wifeFamily == NULL) {
        return;
    }
    
    Family* parentFamily = husbandFamily == NULL ? wifeFamily : husbandFamily;
    Person* childOfParentFamily = husbandFamily == NULL? wife : husband;
    parentFamily->setFamilyOfChildren(childOfParentFamily, family);
}

void FamilyTree::addChild(string motherName, Person* child) {
    Family* motherFamily = this->findParentFamily(motherName);
    if(motherFamily == NULL) {
        cout << "Mother's family does not exist";
        return;
    }
    motherFamily->addToChildren(child);
}

void FamilyTree::addChildToFamily(Family *family, Person *child) {
    Person* husband= family->getHusband();
    Person* wife = family->getWife();
    Family* husbandFamily = this->findChildFamily(husband->getName());
    Family* wifeFamily = this->findChildFamily(wife->getName());
    
    if(husbandFamily == NULL && wifeFamily == NULL) {
        cout << "Parent family could not be found";
        return;
    }
    Family* parentFamily = husbandFamily == NULL ? wifeFamily : husbandFamily;
    parentFamily->addToChildren(child);
}




