//
//  FamilyTree.h
//  MeetTheFamily
//
//  Created by Kunal Kalra on 21/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <string>
#include "Family.h"
#include "Person.h"
#ifndef FamilyTree_h
#define FamilyTree_h

class FamilyTree {
    Family* rootFamily;
    
    //Private Methods
    Family* findParentFamily(Family* rootFamily, string name);
    Family* findFamily(Family* rootFamily, string name);
    
public:
    //Constructors
    FamilyTree(Family* rootFamily);
    
    //Getters
    Family* getRootFamily();
    
    //Methods
    void addFamily(Family* family);
    void addChild(string motherName, Person* child);
    void addChildToFamily(Family* family, Person* child);
    
};

#endif /* FamilyTree_h */
