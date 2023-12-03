#include "SPECIAL.h"
SPECIAL::SPECIAL()
{
	this->Strength = 5;
	this->Perception = 5;
	this->Endurance = 5;
	this->Charisma = 5;
	this->Intelligence = 5;
	this->Agility = 5;
	this->Luck = 5;
}
SPECIAL::SPECIAL(short int& s, short int& p, short int& e, short int& c, short int& i, short int& a, short int& l)
{
	this->Strength = s;
	this->Perception = p;
	this->Endurance = e;
	this->Charisma = c;
	this->Intelligence = i;
	this->Agility = a;
	this->Luck = l;
}

short int SPECIAL::get_Strenght() { return this->Strength; }
short int SPECIAL::get_Perception() { return this->Perception; }
short int SPECIAL::get_Endurance() { return this->Endurance; }
short int SPECIAL::get_Charisma() { return this->Charisma; }
short int SPECIAL::get_Intelligence() { return this->Intelligence; }
short int SPECIAL::get_Agility() { return this->Agility; }
short int SPECIAL::get_Luck() { return this->Luck; }

void SPECIAL::set_Strenght(short int& s) { this->Strength = s; }
void SPECIAL::set_Perception(short int& p) { this->Perception = p; }
void SPECIAL::set_Endurance(short int& e) { this->Endurance = e; }
void SPECIAL::set_Charisma(short int& c) { this->Charisma = c; }
void SPECIAL::set_Intelligence(short int& i) { this->Intelligence = i; }
void SPECIAL::set_Agility(short int& a) { this->Agility = a; }
void SPECIAL::set_Luck(short int& l) { this->Luck = l; }