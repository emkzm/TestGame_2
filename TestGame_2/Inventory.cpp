#include "Inventory.h"
#include <iostream>

void Inventory::erase(obj_node* on)
{
	if (on == NULL) return;

	if (on == this->first && this->first == this->last && this->items == 1) // IF ONE OBJECT
	{
		this->first = this->last = NULL;
		this->summary_weignt -= on->value->get_weight();
		delete on;
		return;
	}
	
	else if (this->first != NULL && this->last != NULL && this->first != this->last && this->items > 1) // IF MANY OBJECTS
	{		

		if (on == this->first) // IF TARGET OBJ IS FIRST IN LIST
		{
			this->first = this->first->next;
			this->summary_weignt -= on->value->get_weight();
			delete on;
			return;
		}
		else if (on == this->last) // IF TARGET OBJ IS LAST IN LIST
		{
			this->last = this->last->prev;
			this->summary_weignt -= on->value->get_weight();
			delete on;
			return;
		}
		else // IF TARGET OBJ IS IN CENTER IN LIST
		{
			on->prev = on->next;
			on->next = on->prev;
			delete on;
			return;
		}
	}
}

Inventory::Inventory(float mw = 60.0)
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

void Inventory::set_max_weight(float mw)
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
		std::cout << "NO OBJECTS" << std::endl;
		this->first = this->last = obj;
		this->items = 1;
		this->summary_weignt += o->get_weight();
		std::cout << o->get_name() << " ADDRESS:" << &o << std::endl;
		std::cout << this->last->value->get_name() << " ADDRESS:" << &this->last->value << std::endl;
		return;
	}

	else if ( (this->items == 1) && (this->first == this->last)) // IF 1 OBJECT 
	{
		std::cout << "1 OBJECT" << std::endl;
		this->last = obj;
		this->last->prev = this->first;
		this->first->next = this->last;
		this->summary_weignt += o->get_weight();
		this->items = 2;
		std::cout << o->get_name() << " ADDRESS:" << &o << std::endl;
		std::cout << this->last->value->get_name() << " ADDRESS:" << &this->last->value << std::endl;
		return;
	}

	else if ((this->items > 1) && (this->first != NULL && this->last != NULL)) // IF MANY OBJECTS 
	{
		std::cout << "MANY OBJECTS" << std::endl;
		this->last->next = obj;
		obj->prev = this->last;
		this->last = obj;
		this->items += 1;
		this->summary_weignt += o->get_weight();
		std::cout << o->get_name() << " ADDRESS:" << &o << std::endl;
		std::cout << this->last->value->get_name() << " ADDRESS:" << &this->last->value << std::endl;
		return;
	}
	return;
}

void Inventory::smash(unsigned int n)
{
	if (n > this->items - 1) return;

	obj_node* curr = this->first;
	for (int i = 0; i < this->items; i++)
	{
		if (i = n)
		{
			this->erase(curr);
			return;
		}
		curr = curr->next;
	}
	delete curr;
	return;
}

Object* Inventory::remove(unsigned int)
{
	return NULL;
}

std::vector<Object*>* Inventory::get_inventory_list()
{
	std::vector<Object*>* InventoryList = new std::vector<Object*>();
	obj_node* curr = this->first;
	for (int i = 0; i < this->items; i++)
	{
		InventoryList->push_back(curr->value);
	}
	//delete curr;
	return InventoryList;
}