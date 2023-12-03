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
    char gender;
    //SPECIAL* SPECIAL_LIST;
    //vector<Perk*>* perks;
    
public:
    Person();
    Person(Inventory* inventory,
        const short int& health,
        const char& gender,
        const float& weight,
        const unsigned int& rare,
        const unsigned int& cost,
        const std::string& name,
        const std::string& description);
        

    Inventory* get_inventory();
    short int get_health();
    //SPECIAL* get_SPECIAL_LIST();
    //vector<Perk*>* get_perks;
    unsigned int take_to_inventory(Object*);
};

