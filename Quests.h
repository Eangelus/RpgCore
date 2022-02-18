#pragma once

#include <string>
#include <vector>
#include <fstream>



class Quests
{

private:
	std::string question;
	std::vector<std::string> antworten;
	int correcteAntwort = 0;

public:

	inline const int& getCorrectAns()const { return this->correcteAntwort; }
	Quests(std::string fileName);
	virtual ~Quests();
	std::string getAsString();

};

