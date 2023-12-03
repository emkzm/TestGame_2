#include "Object.h"

Object::Object()
{
	this->weight = 0;
	this->rare = 0;
	this->cost = 0;
	this->name = "Unknown";
	this->description = "No description";
}

Object::Object(const float& w = 0.0, 
	const unsigned int& r = 0, 
	const unsigned int& c = 0, 
	const std::string& n = "Unknown", 
	const std::string& d = "No description")
{
	this->weight = w;
	this->rare = r;
	this->cost = c;
	this->name = n;
	this->description = d;
}

float Object::get_weight()
{
	return this->weight;
}

unsigned int Object::get_rare()
{
	return this->rare;
}

unsigned int Object::get_cost()
{
	return this->cost;
}

std::string Object::get_name()
{
	return this->name;
}

std::string Object::get_description()
{
	return this->description;
}

void Object::set_name(const std::string& name)
{
	this->name = name;
}

void Object::set_description(const std::string& description)
{
	this->description = description;
}

void Object::use()
{

}