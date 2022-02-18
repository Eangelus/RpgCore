#pragma once
#include <stdlib.h>
#include "Quests.h"
#include "TBSpieler.h"
#include "gArr.h"

class Event
{

private:
	int nrOfEvents;

public:
	Event();
	virtual ~Event();


	//Events
	void generateEvent(TBSpieler &Spieler, gArr<Gegner>& gegner);
	void enemyEncounter(TBSpieler &Spieler, gArr<Gegner>& gegner);
	void questEncounter(TBSpieler &Spieler);


};


