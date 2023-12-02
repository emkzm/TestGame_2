#include "ConsoleInterface.h"

void ConsoleInterface::LookInventory(Inventory* inventory)
{
	std::cout << "���-�� ����� � ���������: " << inventory->get_items() << std::endl;
	std::cout << "�����: " << inventory->get_summary_weignt() << "/" << inventory->get_max_weight() << std::endl;
	std::vector<Object*>* InventoryList = inventory->get_inventory_list();
	for (int i = 0; i < InventoryList->size(); i++)
	{
		std::cout << i << ".  " << (*InventoryList)[i]->get_name() << " ADDRESS: " << &(*InventoryList)[i] << std::endl;
	}
}
void ConsoleInterface::SelectionToDeleteMenu(Inventory* inventory)
{
	this->LookInventory(inventory);
	std::cout << "����� ������� �������?" << std::endl;
	int i;
	std::cin >> i;
	inventory->smash(i);
}
