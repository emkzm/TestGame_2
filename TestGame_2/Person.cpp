#include "Person.h"
Person::Person() : Object ()
{
	this->inventory = new Inventory(60);
	this->health = 100;
	this->gender = 'm';
}
Person::Person(Inventory* inventory, 
	const short int& health, 
	const char& gender, 
	const float& weight, 
	const unsigned int& rare, 
	const unsigned int& cost, 
	const std::string& name, 
	const std::string& description)
	: Object (weight, rare, cost, name, description)
{
	this->inventory = inventory;
	this->health = health;
	this->gender = gender;
}

Inventory* Person::get_inventory() { return this->inventory; }
short int Person::get_health() { return this->health; }
//SPECIAL* Person::get_SPECIAL_LIST();
//vector<Perk*>* Person::get_perks;

unsigned int Person::take_to_inventory(Object* obj)
{
	if (this->inventory->get_max_weight() < this->inventory->get_summary_weignt() + obj->get_weight() ) return 1;
	else
	{
		this->inventory->put(obj);
	}
	return 0;
}

void Person::set_health(const unsigned int& health)
{
	this->health = health;
}