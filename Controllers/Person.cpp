//
//  Person.cpp
//  MeetTheFamily
//
//  Created by Kunal Kalra on 20/09/19.
//  Copyright © 2019 Kunal Kalra. All rights reserved.
//

#include <iostream>
#include "../Models/Person.h"
#include "../Models/Gender.h"

//Constructors
Person::Person(string personName, Gender gender) {
    this->name = personName;
    this->gender = gender;
}

//Methods
bool Person::isEqual(Person* person) {
    return (this->name == person->getName() && this->gender == person->getGender());
}

//Getters
string Person::getName() {
    return this->name;
}
Gender Person::getGender() {
    return this->gender;
}

