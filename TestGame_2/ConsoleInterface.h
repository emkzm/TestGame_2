#pragma once
#include "Object.h"
#include "Inventory.h"
#include <iostream>

class ConsoleInterface
{
public:
	void LookInventory(Inventory* inventory);
	void SelectionToDeleteMenu(Inventory* inventory);
};

