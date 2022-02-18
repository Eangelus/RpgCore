#pragma once

#include "Item.h"
class Armor  : public Item 
{


public:


	virtual ~Armor();
	Armor(int type = 0, int defence = 0,
		std::string ItemName = "NONE", int itemLevel = 0,
		int Epreis = 0, int Vpreis = 0, int scheltenheit = 0);



	std::string toString();

	// pure virtual
	virtual Armor* clone() const;

private:

	int type;
	int defence;

};

