//
//  Family.h
//  MeetTheFamily
//
//  Created by Kunal Kalra on 20/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <vector>
#include <unordered_map>
#include "Person.h"
#ifndef Family_h
#define Family_h

using namespace std;

class Family {
    Person* husband;
    Person* wife;
    vector <Person*> children;
    unordered_map <Person*, Family*> familyOfChildren;
    
public:
    
    //Constructor
    Family(Person* husband, Person* wife, vector <Person*> children);
    
    //Methods
    bool hasChild(string personName);
    bool isFamilyOf(string personName);
    bool hasMember(string personName);
    
    //Getters
    Person* getHusband();
    Person* getWife();
    vector <Person*> getChildren();
    unordered_map<Person*, Family*> getFamilyOfChildren();
    
    //Setters
    void setFamilyOfChildren(Person* child, Family* family);
};

#endif /* Family_h */
