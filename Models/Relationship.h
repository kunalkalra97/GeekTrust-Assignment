//
//  Relationship.h
//  MeetTheFamily
//
//  Created by Kunal Kalra on 23/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <vector>
#include <string>
#include "Family.h"
#include "Person.h"
#include "FamilyTree.h"
#ifndef Relationship_h
#define Relationship_h

using namespace std;

class Relationship {
    FamilyTree* familyTree;
public:
    
    //Constructor
    Relationship(FamilyTree*);
    
    //Methods
    vector <Person*> getPaternalUncles(string name);
    vector <Person*> getMaternalUncles(string name);
    vector <Person*> getPaternalAunts(string name);
    vector <Person*> getMaternalAunts(string name);
    vector <Person*> getSistersInLaw(string name);
    vector <Person*> getBrothersInLaw(string name);
    vector <Person*> getSons(string name);
    vector <Person*> getDaughters(string name);
    vector <Person*> getSiblings(string name);
    Person* getFather(string name);
    Person* getMother(string name);
};

#endif /* Relationship_h */
