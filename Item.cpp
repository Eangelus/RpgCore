#include "Item.h"

Item::Item(std::string itemName, int itemLevel,
	int Vpreis, int Epreis,
	int seltenheit)
{


this->itemName = itemName;
this->Epreis = Epreis;
this->Vpreis = Vpreis;
this->itemLevel = itemLevel;
this->seltenheit = seltenheit;


}


Item::~Item()
{
}
