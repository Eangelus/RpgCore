#include "Waffen.h"

Waffen::Waffen(int schadenMin, int schadenMax, std::string ItemName, int itemLevel, int Epreis, int Vpreis, int scheltenheit) :
	Item(ItemName, itemLevel, Epreis, Vpreis, scheltenheit)
{
	this->schadenMin = schadenMin;
	this->schadenMax = schadenMax;


}









std::string Waffen::toString()
{
	std::string str = std::to_string(this->schadenMin) + " " + std::to_string(this->schadenMax);
	return str;
}

Waffen* Waffen::clone() const
{
	return new Waffen(*this);
}








Waffen::~Waffen()
{
}
