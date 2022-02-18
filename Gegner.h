#pragma once
#include <stdlib.h>
#include <string>

class Gegner
{
public:
	Gegner(int level = 0);
	virtual ~Gegner();
	
	inline bool isAlive() { return this->hp > 0; }

	std::string getAstring() const;
	inline void takeDmg(int schaden) { this->hp -= schaden; }
	inline int getDmg() const { return rand() % this->schadenMax - this->schadenMin; }
	inline int getExp() const { return this->level * 100; }


private:

	int hp;
	int level;
	int hpMax;
	int schadenMax;
	int schadenMin;
	float dropChance;
	int verteidigung;
	int genauigkeit;

};

