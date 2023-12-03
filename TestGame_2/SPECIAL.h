#pragma once
class SPECIAL
{
private:
	short int Strength;
	short int Perception;
	short int Endurance;
	short int Charisma;
	short int Intelligence;
	short int Agility;
	short int Luck;
public:
	SPECIAL();
	SPECIAL(short int&, short int&, short int&, short int&, short int&, short int&, short int&);

	short int get_Strenght();
	short int get_Perception();
	short int get_Endurance();
	short int get_Charisma();
	short int get_Intelligence();
	short int get_Agility();
	short int get_Luck();

	void set_Strenght(short int&);
	void set_Perception(short int&);
	void set_Endurance(short int&);
	void set_Charisma(short int&);
	void set_Intelligence(short int&);
	void set_Agility(short int&);
	void set_Luck(short int&);
};
