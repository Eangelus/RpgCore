#pragma once

#include "Item.h"


class Waffen : public Item
{

private:
	int schadenMin;
	int schadenMax;




public:

	Waffen(int schadenMin = 0, int schadenMax = 0,
		std::string ItemName = "", int itemLevel = 0,
		int Epreis = 0, int Vpreis = 0, int scheltenheit = 0);

	virtual ~Waffen();


	std::string toString();

	// pure virtual 
	virtual Waffen* clone() const;


};

