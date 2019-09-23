//
//  main.cpp
//  MeetTheFamily
//
//  Created by Kunal Kalra on 19/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Models/Person.h"
#include "Models/Family.h"
#include "Models/FamilyTree.h"
#include "Models/Gender.h"
#include "Models/Relationship.h"

using namespace std;

// Helper Methods to find Relationships

int main(int argc, const char * argv[]) {
    // Initialising Family
    
    // Creating all People
    Person* shan = new Person("Shan", male);
    Person* anga = new Person("Anga", female);
    Person* chit = new Person("Chit", male);
    Person* ish = new Person("Ish", male);
    Person* vich = new Person("Vich", male);
    Person* aras = new Person("Aras", male);
    Person* satya = new Person("Satya", female);
    Person* amba = new Person("Amba", female);
    Person* dhritha = new Person("Dhritha", female);
    Person* tritha = new Person("Tritha", female);
    Person* vritha = new Person("Vritha", male);
    Person* jaya = new Person("Jaya", male);
    Person* yodhan = new Person("Yodhan", male);
    
    Family* rootFamily = new Family(shan, anga, vector <Person*>());
    FamilyTree* familyTree = new FamilyTree(rootFamily);
    
    familyTree->addChild("Anga", chit);
    familyTree->addChild("Anga", ish);
    familyTree->addChild("Anga", vich);
    familyTree->addChild("Anga", aras);
    familyTree->addChild("Anga", satya);
    
    Family* chitFamily = new Family(chit, amba, vector <Person*>());
    chitFamily->addToChildren(dhritha);
    chitFamily->addToChildren(tritha);
    chitFamily->addToChildren(vritha);
    
    familyTree->addFamily(chitFamily);
    
    Family* dhrithaFamily = new Family(jaya, dhritha, vector<Person*>());
    dhrithaFamily->addToChildren(yodhan);
    
    familyTree->addFamily(dhrithaFamily);
    
    Relationship* relationship = new Relationship(familyTree);
    cout << relationship->getMaternalAunts("Chit").size();
    
    cout << endl << "Hello, World!";
    return 0;
}
