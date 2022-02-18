#pragma once
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <fstream>
#include "Event.h"
#include "gArr.h"

using namespace std;

class TBGameClass

{

private:

	int choice;
	bool running;


	// Charakter / spieler 

	int activSpieler;
	vector<TBSpieler> Spieler; // nochmal genau an sehen 
	string fileName;


	// Gegner 
	gArr<Gegner> gegner;


public:
	TBGameClass();
	virtual ~TBGameClass();

	// opteratoren


	// funktionen
	void gameInit();
	void mainMenu();
	void intro();
	void endGame();
	void Travel();

	void createNewSpieler();
	void saveSpieler();
	void loadSpieler();
	void selectSpieler();
	void levelUpSpieler();

	// accessors
	inline bool getPlaying() const { return this->running; }

};

