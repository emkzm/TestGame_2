#include "ScriptReaderInterface.h"

void ScriptReaderInterface::ScriptReaderMethod(Person* Player)
{
	std::string TestScriptFileString;

	std::ifstream TestScriptFile("TestScriptFile.txt");
	if (TestScriptFile.is_open())
	{
		while (std::getline(TestScriptFile, TestScriptFileString))
		{
			if (TestScriptFileString.find("//") != TestScriptFileString.npos) continue;

			if (TestScriptFileString.find("set ") != TestScriptFileString.npos)
			{
				this->SetScriptMethod(Player, TestScriptFileString);
			}
			else if (TestScriptFileString.find("get ") != TestScriptFileString.npos)
			{
				this->GetScriptMethod(Player, TestScriptFileString);
			}
			else if (TestScriptFileString.find("give ") != TestScriptFileString.npos)
			{
				this->GiveScriptMethod(Player, TestScriptFileString);
			}
		}
	}
	TestScriptFile.close();
}

void ScriptReaderInterface::SetScriptMethod(Person* Player, const std::string& TestScriptFileString)
{
	if (TestScriptFileString.find("Player") != TestScriptFileString.npos)
	{
		this->SetPlayerScriptMethod(Player, TestScriptFileString);
	}
}

void ScriptReaderInterface::GetScriptMethod(Person* Player, const std::string& TestScriptFileString)
{
	if (TestScriptFileString.find("Player") != TestScriptFileString.npos)
	{
		this->GetPlayerScriptMethod(Player, TestScriptFileString);
	}
}

void ScriptReaderInterface::GiveScriptMethod(Person* Player, const std::string& TestScriptFileString)
{
	std::cout << TestScriptFileString << std::endl;
}

void ScriptReaderInterface::SetPlayerScriptMethod(Person* Player, const std::string& TestScriptFileString)
{
	if (TestScriptFileString.find("name") != TestScriptFileString.npos)
	{
		std::string* name = new std::string(TestScriptFileString);
		(*name).replace(0, 16, "");
		Player->set_name((*name));
		delete name;
	}
	else if (TestScriptFileString.find("health") != TestScriptFileString.npos)
	{
		std::string* health = new std::string(TestScriptFileString);
		(*health).replace(0, 18, "");
		Player->set_health(std::stoi(*health));
		delete health;
	}
}

void ScriptReaderInterface::GetPlayerScriptMethod(Person* Player, const std::string& TestScriptFileString)
{
	if (TestScriptFileString.find("name") != TestScriptFileString.npos)
	{
		std::cout << Player->get_name() << std::endl;
	}
	else if (TestScriptFileString.find("health") != TestScriptFileString.npos)
	{
		std::cout << Player->get_health() << std::endl;
	}
}