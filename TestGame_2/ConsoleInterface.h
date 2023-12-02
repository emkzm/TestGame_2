#pragma once
#include "Object.h"
#include "Inventory.h"
#include <iostream>

class ConsoleInterface
{
public:
	void Look_Inventory(Inventory* inventory)
	{
		std::cout << "Кол-во вещей в инвентаре: " << inventory->get_items() << std::endl;
		std::cout << "Масса: " << inventory->get_summary_weignt() << "/" << inventory->get_max_weight() << std::endl;
		std::vector<Object*>* InventoryList = inventory->get_inventory_list();
		for (int i = 0; i < InventoryList->size(); i++)
		{
			std::cout << i << ".  " << (*InventoryList)[i]->get_name() << " ADDRESS: " << &(*InventoryList)[i] << std::endl;
		}
	}
};

