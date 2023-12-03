#pragma once
#include "Object.h"
#include "Inventory.h"
#include "Person.h"
#include <iostream>

class ConsoleInterface
{
public:
	void LookInventory(Inventory* inventory);
	void SelectionToDeleteMenu(Inventory* inventory);
	void ShowPersonInfo(Person*);
	void GiveMenu(Person*, Person*);
	void TakeMenu(Person*, Person*);
	void TradeMenu(Person*, Person*);
	void SaveGameMenu();
	void LoadGameMenu();
	void TestGameMenu_v0_1(Person* Player1, Person* Player2);
};

