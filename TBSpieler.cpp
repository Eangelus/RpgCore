#include "TBSpieler.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>




TBSpieler::TBSpieler()
{
}

TBSpieler::TBSpieler(string name, double xPos,
double yPos,
int level,
int exp,
int spielerStärke ,
int spielerAusdauer ,
int spielerAgi ,
int spielerVita ,
int spielerGenauigkeit ,
int spielerInt,
int spielerMana ,
int spielerLeben ,
int spielerHunger ,
int spielerDurst ,
int spielerRuhe ,
int verteidigung ,
int statPoints ,
int gold,
int distanceTravelled,
int skillPoints ) {

	this->name = name;
	this->xPos = xPos;
	this->yPos = yPos;
	this->level = level;
	
	this->exp = exp;
	this->expNext = 1;
	this->spielerStärke = spielerStärke;
	this->spielerAusdauer = spielerAusdauer;
	this->spielerAgi = spielerAgi;
	this->spielerVita = spielerVita;
	this->spielerGenauigkeit = spielerGenauigkeit;
	this->spielerInt = spielerInt;
	this->spielerMana = spielerMana;
	this->spielerLeben = spielerLeben;
	this->spielerLebenMax = 0;
	this->spielerHunger = spielerHunger;
	this->spielerDurst = spielerDurst;
	this->spielerRuhe = spielerRuhe;

	this->schadenMin = 0;
	this->schadenMax = 0;
	this->verteidigung = verteidigung;

	this->statPoints = statPoints;
	this->gold = gold;
	this->distanceTravelled = distanceTravelled;
	this->skillPoints = skillPoints;





	this->updateStats();

}
void TBSpieler::initSpieler(const string name) {


	this->name = name;

	this->xPos = 0.0;
	this->yPos = 0.0;


	
	this->level = 1;
	this->exp = 0;
	this->spielerStärke = 5;
	this->spielerAusdauer = 5;
	this->spielerAgi = 5;
	this->spielerVita = 5;
	this->spielerGenauigkeit = 5;
	this->spielerInt = 5;
	this->spielerMana = 5;
	this->spielerLeben = 5;
	this->spielerHunger = 5;
	this->spielerDurst = 5;
	this->spielerRuhe = 5;
	this->verteidigung = 5;
	this->statPoints = 0;
	this->gold = 500;
	this->distanceTravelled = 0;
	this->skillPoints = 0;
	this->schadenMin = this->spielerStärke;
	this->schadenMax = this->spielerStärke + 2;

	this->expNext = static_cast<int>(
		(50 / 3) * ((pow(level, 3)
			- 6 * pow(level, 2))
			+ (17 * level) - 12)) + 100;


	this->spielerLebenMax = (this->spielerVita * 2) + (this->spielerStärke / 2);
	this->spielerLeben = spielerLeben;
	this->spielerAusdauerMax = this->spielerVita + (this->spielerStärke / 2) +
		(this->spielerAusdauer / 3);
	this->spielerAusdauer = spielerAusdauerMax;
	this->verteidigung = this->spielerAgi + (this->spielerInt / 2);
	this->spielerGenauigkeit = (this->spielerAgi / 2);
	this->updateStats();

}

::string TBSpieler::getAsString() const
{

	return 
		name + " " + 
		to_string(xPos) + " " +
		to_string(yPos) + " " +
		to_string(level) + " " +
		to_string(exp) + " " +
		to_string(spielerStärke) + " " +
		to_string(spielerAusdauer) + " " +
		to_string(spielerAgi) + " " +
		to_string(spielerVita) + " " +
		to_string(spielerGenauigkeit) + " " +
		to_string(spielerInt) + " " +
		to_string(spielerMana) + " " +
		to_string(spielerLeben) + " " +
		to_string(spielerHunger) + " " +
		to_string(spielerDurst) + " " +
		to_string(spielerRuhe) + " " +
		to_string(verteidigung) + " " +
		to_string(statPoints) + " " +
		to_string(gold) + " " +
		to_string(distanceTravelled) + " " +
		to_string(skillPoints);
	/*


	return string(); */


}

void TBSpieler::printStats() {

	cout << "= Charaterwerte: =" << endl;

	cout << "= Name: " << this->name << endl;

	cout << setw(10) << setfill('=') << endl;

	cout << "= Level: " << this->level << endl;

	cout << "= Exp: " << this->exp << endl;

	cout << "= Exp zum nächsten Level: " << this->expNext << endl;

	cout << setw(10) << setfill('=') << endl;

	cout << "= Leben: " << this->spielerLeben << " / " << this->spielerLebenMax << endl;



	cout << "= Stärke: " << this->spielerStärke << endl;

	cout << "= Inteligenz: " << this->spielerInt << endl;

	cout << "= Mana: " << this->spielerMana << endl;

	cout << "= Agilität: " << this->spielerAgi << endl;

	cout << "= Genauigkeit: " << this->spielerGenauigkeit << endl;

	cout << "= Ausdauer: " << this->spielerAusdauer << endl;

	cout << "= Vitalität: " << this->spielerVita << endl;

	cout << setw(10) << setfill('=') << endl;


	cout << "= Schaden: " << this->schadenMin << " / " << schadenMax << endl;

	cout << "= Verteidigung: " << this->verteidigung << endl;


	cout << setw(10) << setfill('=') << endl;

	cout << "= Hunger: " << this->spielerHunger << endl;

	cout << "= Durst: " << this->spielerDurst << endl;

	cout << "= Ausgeruht: " << this->spielerRuhe << endl;



	cout << setw(10) << setfill('=') << endl;

	cout << "= Statuspunkte und Skillpunkte: " << this->statPoints << " / " << this->skillPoints << endl;

	cout << endl;

}

void TBSpieler::updateStats()
{
	// level berechnung 
	this->expNext = static_cast<int>(
		(50 / 3) * ((pow(level, 3)
			- 6 * pow(level, 2))
			+ (17 * level) - 12)) +100 ;


	this->spielerLebenMax = (this->spielerVita * 2) + (this->spielerStärke / 2);

	this->spielerAusdauerMax = this->spielerVita + (this->spielerStärke / 2) +
		(this->spielerAusdauer / 3);

	this->verteidigung = this->spielerAgi + (this->spielerInt / 2);
	this->spielerGenauigkeit = (this->spielerAgi / 2);

	





}

void TBSpieler::addToStats(int stat, int value)
{
	if (this->statPoints < value)
		cout << "keine Punkte zur verfürgung ! \n";
	else{
	switch (stat) {

	case 1:
		this->spielerStärke += value;
		break;
	case 2:
		this->spielerAgi += value;
		break;

	case 3:
		this->spielerVita += value;
		break;

	case 4:
		this->spielerInt += value;
		break;

	default:
		cout << "kein richtige eingabe oder keine punkt vergabe möglich";
		break;
	}

	this->statPoints -= value;

	}
}

void TBSpieler::levelUp() {

	if (this->exp >= this->expNext) {
	
		this->exp -= this->expNext;
		this->level++;
	
	this->expNext = static_cast<int>((50 / 3) * ((pow(this->level, 3)
		- 6 * pow(level, 2))
		+ 17 * level - 12)) +100;

	this->statPoints++;
	this->skillPoints++;

	this->updateStats();

	cout << "Du hast Level UP! " << this->level << " !"<< "\n\n";
	}
	else {
		cout << "nicht genug exp" << "\n\n";
	}


}

void TBSpieler::feuermachen()
{
}

void TBSpieler::angreifen()
{
}

void TBSpieler::holzhacken()
{
}

void TBSpieler::bewegen()
{
}
