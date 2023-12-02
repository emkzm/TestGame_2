#include "ConsoleInterface.h"

void ConsoleInterface::LookInventory(Inventory* inventory)
{
	std::cout << "Кол-во вещей в инвентаре: " << inventory->get_items() << std::endl;
	std::cout << "Масса: " << inventory->get_summary_weignt() << "/" << inventory->get_max_weight() << std::endl;
	std::vector<Object*>* InventoryList = inventory->get_inventory_list();
	for (int i = 0; i < InventoryList->size(); i++)
	{
		std::cout << i << ".  NAME:" << (*InventoryList)[i]->get_name() << " WEIGHT: " << (*InventoryList)[i]->get_weight() << std::endl;
	}
}
void ConsoleInterface::SelectionToDeleteMenu(Inventory* inventory)
{
	this->LookInventory(inventory);
	std::cout << "Какой предмет удалить?" << std::endl;
	int i;
	std::cin >> i;
	inventory->smash(i);
}
