#include "Event.h"


Event::Event()
{
	this->nrOfEvents = 2;
}

Event::~Event()
{
}

void Event::generateEvent(TBSpieler &Spieler, gArr<Gegner>& gegner)

{

	questEncounter(Spieler);

	/*int i = rand() % this->nrOfEvents ;


	switch (i)
	{

	case 0:
		enemyEncounter(Spieler);
		break;

	case 1:
		questEncounter(Spieler);
		break;

	case 2:
		questEncounter(Spieler);
		break;

	default:
		break;*/
	//}
}



void Event::enemyEncounter(TBSpieler &Spieler, gArr<Gegner> &gegner) {

	bool escape = false;
	bool spielerBesigt = false;
	bool gegnerBesigt = false;

	while (!escape && !spielerBesigt && !gegnerBesigt) {


	}
}

void Event::questEncounter(TBSpieler &Spieler)
{
	bool erfüllt = false;
	int userAntwort = 0;
	int versuche = 3;
	int gainExp = (versuche * Spieler.getLevel() * (rand() % 10 + 1));
	
	Quests q("Quests\\ha.txt");

	while (!erfüllt && versuche > 0) {
		
		std::cout << "Versuche: " << versuche << "\n\n";
		versuche--;

		std::cout << q.getAsString() << "\n";
		std::cout << "\nDeine Antwort: ";
		std::cin >> userAntwort;
		std::cout << "\n";

		while (cin.fail()) {

			cout << "Falsche Eingabe!\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\nDeine Antwort: ";
			cin >> userAntwort;
		}
		cin.ignore(100, '\n');
		cout << "\n";

		if (q.getCorrectAns() == userAntwort) {
			erfüllt = true;
			// user get exp und weiter
			Spieler.gainExp(gainExp);
			std::cout << "du hast " << gainExp << " Exp bekommen !\n";
		}
		
		
	}

	if (erfüllt) {
		std::cout << "Glückwünsche richtig!\n\n";
	}
	else {

		std::cout << "Looser !\n\n";
	}

	
}

