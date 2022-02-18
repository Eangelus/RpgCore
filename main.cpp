
#include "TBGameClass.h"


int mAw;
int auswahl;
int auswahl2;
int auswahl3;
std::string Name;
int hp;

// Inventar
int holz = 0; // 10 holz für ein feuer
int messer = 0; // wird gebraucht um essen zu von tieren zu bekommen   MAX 1 !
int essen = 0;	// 20 essen um satt zu werden  nur wen das feuer an ist


// Spieler Atribute 
bool gewärmt = false;
bool hunger = true;



int main() {
	SetConsoleOutputCP(1252);
	srand(time(NULL));

	TBGameClass game;
	Inventar inv;
	game.gameInit();


	while (game.getPlaying())
	{
		
		game.mainMenu();
	



	}


	game.~TBGameClass();

	return 0;
		
		
	
}