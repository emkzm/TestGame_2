#include "Object.h"

Object::Object()
{
	this->weight = 0;
	this->rare = 0;
	this->cost = 0;
	this->name = "Unknown";
	this->description = "No description";
}

Object::Object(float w = 0.0, unsigned int r = 0, unsigned int c = 0, std::string n = "Unknown", std::string d = "No description")
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

void Object::set_name(std::string n)
{
	this->name = n;
}

void Object::set_description(std::string d)
{
	this->description = d;
}

void Object::use()
{

}