#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Item
{

public:
	Item(std::string itemName , int itemLevel = 0,
		int Vpreis = 0, int Epreis = 0, 
		int seltenheit = 0);


	virtual ~Item();

	inline std::string debugPrint() const {

		return this->itemName;
	};


	virtual Item* clone() const = 0;
	// accessors

	inline const std::string& getItemName() const { return this->itemName; }
	inline const int& getItemLevel() const { return this->itemLevel; }
	
	inline const int& getEpreis() const { return this->Epreis; }
	inline const int& getVpreis() const { return this->Vpreis; }

	inline const int& getSeltenheit() const { return this->seltenheit; }



	// modifiers





private:


	std::string itemName;
	int Vpreis;
	int Epreis;
	int itemLevel;
	int seltenheit;





};

