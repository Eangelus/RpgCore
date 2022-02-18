#include "Armor.h"


Armor::Armor(int type, int defence,
	std::string ItemName, int itemLevel,
	int Epreis, int Vpreis, int scheltenheit) : Item(ItemName, itemLevel, Epreis, Vpreis, scheltenheit) {

	this->type = type;
	this->defence = defence;

}




std::string Armor::toString()
{
	std::string str = std::to_string(this->type) + " " + std::to_string(this->defence);
	return str;
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}




Armor::~Armor() {};