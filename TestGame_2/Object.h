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
	Object(const float& weight,
		const unsigned int& rare,
		const unsigned int& cost,
		const std::string& name,
		const std::string& descripton);
	
	float get_weight();
	unsigned int get_rare();
	unsigned int get_cost();
	std::string get_name();
	std::string get_description();

	void set_name(const std::string& name);
	void set_description(const std::string& description);

	void use();
};

