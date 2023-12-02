#pragma once
#include "Object.h"
#include <vector>

struct obj_node
{
	obj_node* prev;
	Object* value;
	obj_node* next;
};

class Inventory
{
private:
	obj_node* first;
	obj_node* last;
	unsigned int items;
	float max_weight;
	float summary_weignt;
	void erase(obj_node*);

public:
	Inventory(float);

	unsigned int get_items();
	float get_max_weight();
	float get_summary_weignt();

	void set_max_weight(float);

	void put(Object*);
	void smash(unsigned int);
	Object* remove(unsigned int);

	std::vector<Object*>* get_inventory_list();
};

