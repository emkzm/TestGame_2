#include "ConsoleInterface.h"
#include "ScriptReaderInterface.h"
#include <conio.h>
#include <fstream>
#include <string>
#define PAUSE system("pause");
#define CLS system("cls");

void ConsoleInterface::LookInventory(Inventory* inventory)
{
	std::cout << "Number of items: " << inventory->get_items() << std::endl;
	std::cout << "Weight:          " << inventory->get_summary_weignt() << "/" << inventory->get_max_weight() << std::endl;
	std::vector<Object*>* InventoryList = inventory->get_inventory_list();
	for (int i = 0; i < InventoryList->size(); i++)
	{
		std::cout << i << ". NAME: " << (*InventoryList)[i]->get_name() << " WEIGHT: " << (*InventoryList)[i]->get_weight() << std::endl;
	}
}
void ConsoleInterface::SelectionToDeleteMenu(Inventory* inventory)
{
	while (true)
	{
		CLS;
		this->LookInventory(inventory);
		std::cout << "999 - Exit" << std::endl << "Which item to delete ? : ";
		int n;
		std::cin >> n;
		if (n == 999) return;
		inventory->remove(n);
	}
}

void ConsoleInterface::ShowPersonInfo(Person* p)
{
	std::cout << "Name:   " << p->get_name()   << std::endl;
	std::cout << "Health: " << p->get_health() << std::endl;
}

void ConsoleInterface::GiveMenu(Person* Player1, Person* Player2)
{
	while (true)
	{
		CLS;
		this->LookInventory(Player1->get_inventory());
		std::cout << "999 - Exit" << std::endl << "Which item to give ? : ";
		int n;
		std::cin >> n;
		if (n == 999) return;
		Player2->take_to_inventory(Player1->get_inventory()->remove(n));
	}
}

void ConsoleInterface::TakeMenu(Person* Player1, Person* Player2)
{
	while (true)
	{
		CLS;
		this->LookInventory(Player2->get_inventory());
		std::cout << "999 - Exit" << std::endl << "Which item to take ? : ";
		int n;
		std::cin >> n;
		if (n == 999) return;
		Player1->take_to_inventory(Player2->get_inventory()->remove(n));
	}
}

void ConsoleInterface::TradeMenu(Person* Player1, Person* Player2)
{
	while (true)
	{
		CLS;
		std::cout << " ================== YOU ================== " << std::endl;
		this->ShowPersonInfo(Player1);
		this->LookInventory(Player1->get_inventory());
		std::cout << " ================== Player 2 ================== " << std::endl;
		this->ShowPersonInfo(Player2);
		this->LookInventory(Player2->get_inventory());
		std::cout << " ================== CHOICE ================== " << std::endl
			<< "1 - Give to " << Player2->get_name() << std::endl
			<< "2 - Take from " << Player2->get_name() << std::endl
			<< "0 - Go back" << std::endl;
		int i;
		std::cin >> i;
		if (i == 1)
		{
			this->GiveMenu(Player1, Player2);
		}
		else if (i == 2)
		{
			this->TakeMenu(Player1, Player2);
		}
		else if (i == 0)
		{
			return;
		}
	}
}

void ConsoleInterface::SaveGameMenu()
{
	std::ofstream savegamefile;
	savegamefile.open("savegame.txt");
	if (savegamefile.is_open())
	{
		savegamefile << "Hello World!" << std::endl;
		savegamefile.close();
		std::cout << "File has been written" << std::endl;
	}
	else 
		std::cout << "ERROR! File has not been written!" << std::endl;
	PAUSE;
}

void ConsoleInterface::LoadGameMenu()
{
	std::string loadgamefilestring;

	std::ifstream loadgamefile("savegame.txt");
	if (loadgamefile.is_open())
	{
		while (std::getline(loadgamefile, loadgamefilestring))
		{
			std::cout << loadgamefilestring << std::endl;
		}
	}
	loadgamefile.close();
	PAUSE;
}

void ConsoleInterface::TestGameMenu_v0_1(Person* Player1, Person* Player2)
{
	while (true)
	{
		CLS;
		std::cout << " ================== TestGameMenu_v0_1 ================== " << std::endl
			<< "Press a key to set option" << std::endl
			<< "1 - Trade with a friend" << std::endl
			<< "2 - Delete items from inventory" << std::endl
			<< "3 - Look in inventory" << std::endl
			<< "4 - Save game" << std::endl
			<< "5 - Load game" << std::endl
			<< "6 - Load Script" << std::endl
			<< "0 - Exit game" << std::endl;
		int i;
		std::cin >> i;
		if (i == 1)
		{
			this->TradeMenu(Player1, Player2);
		}
		else if (i == 2)
		{
			this->SelectionToDeleteMenu(Player1->get_inventory());
		}
		else if (i == 3)
		{
			CLS;
			this->ShowPersonInfo(Player1);
			this->LookInventory(Player1->get_inventory());
			PAUSE;
		}
		else if (i == 4)
		{
			this->SaveGameMenu();
		}
		else if (i == 5)
		{
			this->LoadGameMenu();
		}
		else if (i == 6)
		{
			ScriptReaderInterface* SRI = new ScriptReaderInterface();
			SRI->ScriptReaderMethod(Player1);
			PAUSE;
		}
		else if (i == 0)
		{
			return;
		}
	}
}
