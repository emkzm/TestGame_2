#include "Inventory.h"

Object* Inventory::erase(obj_node* on)
{
	if (on == NULL) return NULL;

	if (on == this->first && this->first == this->last && this->items == 1) // IF ONE OBJECT
	{
		this->first = this->last = NULL;
		this->items = 0;
		this->summary_weignt = 0;
		return on->value;
	}
	
	else if (this->first != NULL && this->last != NULL && this->first != this->last && this->items > 1) // IF MANY OBJECTS
	{		
		if (on == this->first) // IF TARGET OBJ IS FIRST IN LIST
		{
			this->first = this->first->next;
			this->summary_weignt -= on->value->get_weight();
			this->items--;
			return on->value;
		}
		else if (on == this->last) // IF TARGET OBJ IS LAST IN LIST
		{
			this->last = this->last->prev;
			this->summary_weignt -= on->value->get_weight();
			this->items--;
			return on->value;
		}
		else // IF TARGET OBJ IS IN CENTER IN LIST
		{
			on->prev->next = on->next;
			on->next->prev = on->prev;
			this->summary_weignt -= on->value->get_weight();
			this->items--;
			return on->value;
		}
	}
	return NULL;
}

Inventory::Inventory(const float& mw)
{
	this->first = NULL;
	this->last = NULL;
	this->items = 0;
	this->max_weight = mw;
	this->summary_weignt = 0;
}

unsigned int Inventory::get_items()
{
	return this->items;
}

float Inventory::get_max_weight()
{
	return this->max_weight;
}
float Inventory::get_summary_weignt()
{
	return this->summary_weignt;
}

void Inventory::set_max_weight(const float& mw)
{
	this->max_weight = mw;
}

void Inventory::put(Object* o)
{
	if (o == NULL) return;

	obj_node* obj = new obj_node();
	obj->next = NULL;
	obj->prev = NULL;
	obj->value = o;

	if (this->items == 0 && this->first == NULL && this->last == NULL) // IF NO OBJECTS
	{
		this->first = this->last = obj;
		this->items = 1;
		this->summary_weignt += o->get_weight();
		return;
	}

	else if ( (this->items == 1) && (this->first == this->last)) // IF 1 OBJECT 
	{
		this->last = obj;
		this->last->prev = this->first;
		this->first->next = this->last;
		this->summary_weignt += o->get_weight();
		this->items = 2;
		return;
	}

	else if ((this->items > 1) && (this->first != NULL && this->last != NULL)) // IF MANY OBJECTS 
	{
		this->last->next = obj;
		obj->prev = this->last;
		this->last = obj;
		this->items += 1;
		this->summary_weignt += o->get_weight();
		return;
	}
	return;
}

Object* Inventory::remove(const unsigned int& n)
{
	if (n > this->items - 1) return NULL;

	obj_node* curr = this->first;
	unsigned int i = 0;
	while (curr != NULL)
	{
		if (i == n)
		{
			return this->erase(curr);
		}
		if (curr->next == NULL) return NULL;
		else
		{
			curr = curr->next;
			i++;
		}
	}
	return NULL;
}

std::vector<Object*>* Inventory::get_inventory_list()
{
	std::vector<Object*>* InventoryList = new std::vector<Object*>();
	obj_node* curr = this->first;
	for (int i = 0; i < this->items; i++)
	{
		InventoryList->push_back(curr->value);
		curr = curr->next;
	}
	//delete curr;
	return InventoryList;
}