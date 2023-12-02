#pragma once
#include <string>

class Object
{
private:
	float weight;
	unsigned int rare;
	unsigned int cost;
	std::string name;
	std::string description;

public:
	Object();
	Object(float, unsigned int, unsigned int, std::string, std::string); // weight, rare, cost, name, description
	
	float get_weight();
	unsigned int get_rare();
	unsigned int get_cost();
	std::string get_name();
	std::string get_description();

	void set_name(std::string);
	void set_description(std::string);

	void use();
};

