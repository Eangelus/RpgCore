#include "Inventar.h"

Inventar::Inventar()
{
	cap = 5;
	nrOfItem = 0;

	itemArr = new Item * [cap];
	this->initializeInventar();

}
#
// kopie construktor

Inventar::Inventar(const Inventar& obj) {

	this->cap = obj.cap;
	this->nrOfItem = obj.nrOfItem;
	this->itemArr = new Item * [this->cap];

	for (size_t i = 0; i < this->nrOfItem; i++) {

		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initializeInventar(this->nrOfItem);

}

Item& Inventar::operator[](const int index) {

	if (index < 0 || index >= this->nrOfItem) {
		throw("BAD INDEX!");
	}
	return *this->itemArr[index];
}

void Inventar::addItem(const Item& item){

	if (this->nrOfItem >= this->cap) {

		expand();
	}

	this->itemArr[this->nrOfItem++] = item.clone();
}

void Inventar::removeItem(int index)
{
}

void Inventar::initializeInventar(const int from)
{
	for (size_t i = from; i < cap; i++) {

		itemArr[i] = nullptr;

	}
}

void Inventar::expand()
{
	this->cap *= 2;

	Item** tempArr = new Item * [this->cap];




	for (size_t i = 0; i < this->nrOfItem; i++) {

		tempArr[i] = this->itemArr[i];

	}


	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initializeInventar(this->nrOfItem);
}



Inventar::~Inventar()
{

	for (size_t i = 0; i < this->nrOfItem; i++) {

		delete this->itemArr[i];
	}

	delete[] this->itemArr;
}