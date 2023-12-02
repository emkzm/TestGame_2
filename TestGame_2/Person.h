#pragma once
#include "Object.h"
#include "Inventory.h"
#include <string>
#include <vector>
#include "SPECIAL.h"

class Person :
    public Object
{
private:
    Inventory* inventory;
    short int health;
    SPECIAL* SPECIAL_LIST;
    //vector<Perk*>* perks[];
    std::string* name;

public:
    Person();
    Person(std::string*);
    std::string get_name();

};

