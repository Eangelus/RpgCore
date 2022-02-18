#include "Gegner.h"

Gegner::Gegner(int level)
{
	this->level = level;

	this->hpMax = level * 10;
	this->hp = this->hpMax;
	
	this->schadenMin = this->level*4;
	this->schadenMax = this->level*5;

	this->dropChance = rand() % 100;
	this->verteidigung = rand() % 100;
	this->genauigkeit = rand() % 100;


}

std::string Gegner::getAstring() const {

	return "Level: " + std::to_string(this->level) + "\n" +
		"HP: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"Schaden: " + std::to_string(this->schadenMin) + " / " + std::to_string(this->schadenMax) + "\n" +
		"Verteidigung: " + std::to_string(this->verteidigung) + "\n" +
		"Genauigkeit: " + std::to_string(this->genauigkeit) + "\n" +
		"Drop chance: " + std::to_string(this->dropChance) + "\n";
}

Gegner::~Gegner()
{
}
