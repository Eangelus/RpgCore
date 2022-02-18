#include "Quests.h"
#include <iostream>

Quests::Quests(std::string fileName){


	this->correcteAntwort;
	std::ifstream inFile(fileName);


	int nrOfAns = 0;
	std::string antwort = "";
	int correcteAns = 0;

	if (inFile.is_open()) {


		std::getline(inFile, this->question);
		inFile >> nrOfAns;
		inFile.ignore();

		for (size_t i = 0; i < nrOfAns; i++) {

			std::getline(inFile, antwort);
			this->antworten.push_back(antwort);
		}
		inFile >> correcteAns;
		this->correcteAntwort = correcteAns;
		inFile.ignore();

	}
	else 
		std::cout << "Quests konnte nicht geladen werden !";
	inFile.close();

}



std::string Quests::getAsString()
{
	std::string antworten = "";

	for (size_t i = 0; i < this->antworten.size(); i++) {

		antworten += std::to_string(i) + ": " + this->antworten[i] + "\n";
	}
	//return this->question + "\n" + "\n"
	//	+ antworten + "\n"
	//	+ std::to_string(this->correcteAntwort) + "\n";

	return this->question + "\n" + "\n"
		+ antworten + "\n";
		
}


Quests::~Quests() {




}