#pragma once
#include "Item.h"
#include "Waffen.h"
#include "Armor.h"


class Inventar
{

public:
	Inventar();
	~Inventar();

	void addItem(const Item& item);
	void removeItem(int index); 

	Inventar(const Inventar& obj); //add
	inline int size()const { return this->nrOfItem; } // add
	Item& operator[](const int index); // add
	
	



	void debugPrint() const {

		for (size_t i = 0; i < this->nrOfItem; i++) {

			std::cout << this->itemArr[i]->debugPrint() << std::endl;


		}

	};


private:

	int cap;
	int nrOfItem;
	Item** itemArr;

	void initializeInventar(const int from = 0);

	void expand();

};

