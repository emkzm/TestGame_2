#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <string>
#include "Person.h"

class ScriptReaderInterface
{
public:
	void ScriptReaderMethod(Person* Player);
	void SetScriptMethod(Person* Player, const std::string& script);
	void GetScriptMethod(Person* Player, const std::string& script);
	void GiveScriptMethod(Person* Player, const std::string& script);

	void SetPlayerScriptMethod(Person* Player, const std::string& script);
	void GetPlayerScriptMethod(Person* Player, const std::string& script);
	void GivePlayerScriptMethod(Person* Player, const std::string& script);
};

