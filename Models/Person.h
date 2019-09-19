//
//  Person.h
//  MeetTheFamily
//
//  Created by Kunal Kalra on 20/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <string>
#include "Gender.h"
#ifndef Person_h
#define Person_h

using namespace std;

class Person {
    
    string name;
    Gender gender;

public:
    
    //Constructor
    Person(string name, Gender gender);
    
    //Methods
    bool isEqual(Person* person);
    
    //Getters
    string getName();
    Gender getGender();
};


#endif /* Person_h */
