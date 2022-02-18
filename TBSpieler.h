#pragma once
#include <string>
#include "Inventar.h"
#include "Gegner.h"

using namespace std;


class TBSpieler
{

public:

	TBSpieler();
	TBSpieler(string name, double xPos,
		double yPos,
		int level,
		int distanceTravelled,
		int gold,
		int exp,
		int spielerStärke,
		int spielerAusdauer,
		int spielerAgi,
		int spielerInt,
		int spielerVita,
		int spielerGenauigkeit,
		int spielerMana,
		int spielerLeben,
		int spielerHunger,
		int spielerDurst,
		int spielerRuhe,
		int verteidigung,
		int statPoints,
		int skillPoints);
	virtual ~TBSpieler() {};
	

	// funktionen

	void initSpieler(const ::string name);
	string getAsString() const;
	void levelUp();
	void printStats();
	void updateStats();

	void addToStats(int stat, int value);




	// Modiffier
	//************************* Seter ***********************//

	inline void gainExp(const int& exp) { this->exp += exp; }
	inline void setDistanceTravelled(const int& distance) { this->distanceTravelled = distance; }
	inline void Travel() { this->distanceTravelled++; }

	// Accessors

	// ************************ Geter ************************//
	// Position

	inline const double& getX() const { return this->xPos; }
	inline const double& getY() const { return this->yPos; }

	inline const int& getDistanceTravelled() const { return this->distanceTravelled; }

	// Name und EXp
	inline const int& getLevel() const { return this->level; }

	inline const ::string& getName() const { return this->name; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }

	inline const int& getStatsPoints() const { return this->statPoints; }
	// Werte 

	inline const int& getLeben() const { return this->spielerLeben; }
	inline const int& getLebenMax() const { return this->spielerLebenMax; }
	inline const int& getAusdauer() const { return this->spielerAusdauer; }
	inline const int& getVita() const { return this->spielerVita; }

	inline const int& getHunger() const { return this->spielerHunger; }
	inline const int& getDurst() const { return this->spielerDurst; }
	inline const int& getRuhe() const { return this->spielerRuhe; }

	// Kampfwerte

	inline const int& getSchadenMin() const { return this->schadenMin; }
	inline const int& getSchadenMAx() const { return this->schadenMax; }
	inline const int& getVerteidigung() const { return this->verteidigung; }

	inline const int& getSträke() const { return this->spielerStärke; }
	inline const int& getInt() const { return this->spielerInt; }
	inline const int& getMana() const { return this->spielerMana; }
	inline const int& getGenauigkeit() const { return this->spielerGenauigkeit; }

	
	void feuermachen();
	void angreifen();
	void holzhacken();
	void bewegen();

private:


	// travel timer wie weit ist der spieler bisher gegangen 

	


	// inventar 

	Inventar inv;

	Waffen waffen;
	Armor armor;

	


	//					Spieler eigentschaften				
	
	::string name;
	int level; 
	int exp;
	int expNext;
	double xPos;
	double yPos;

	//					Spieler grundwerte
	int spielerLeben;		
	int spielerLebenMax;		

	int spielerStärke;
	int spielerGenauigkeit;
	int spielerAgi;
	int spielerVita;

	int spielerInt;
	int spielerMana;		
	
	int spielerAusdauerMax;
	int spielerAusdauer;	


	//					Spieler 
	int spielerHunger;
	int spielerDurst;
	int spielerRuhe;

	//					Spieler Kampf werte
	int schadenMin;		
	int schadenMax;		
	int verteidigung;	
	
	//					Spieler Level werte

	int statPoints;
	int gold;
	int distanceTravelled;
	int skillPoints;
};

