#include "TBGameClass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

//string name = "";

TBGameClass::TBGameClass()
{
	choice = 0;
	running = true;
	activSpieler = 0;
	fileName = "Spieler.txt";
}

TBGameClass::~TBGameClass()
{
}


void TBGameClass::gameInit() {

	
	if (this->Spieler.empty() ) {
		loadSpieler();
		
	}
	else {
		createNewSpieler();
	}
	
}

void TBGameClass::mainMenu()
{

	if (this->Spieler[activSpieler].getExp() >=
		this->Spieler[activSpieler].getExpNext()) {
		cout << "Level UP!\n\n";
	}
	
		cout << " Willkommen zu meinen Rollenspiel von Thomas Bernecker" << endl << endl;
		cout << "\n\n Aktiver Spieler: " << this->Spieler[activSpieler].getName() <<" " << "Nr.: " << this->activSpieler
			<< " / " << this->Spieler.size() << " == " << "\n\n";

		cout << "Hauptmenu:" << endl
			<< "Spiel starten 1." << endl

			<< "Charakter erstellen 2." << endl

			<< "Charakter Laden 3." << endl

			<< "Charakter Speichern 4." << endl
			<< "Charakter wählen 5." << endl

			<< "Reisen/Travel 6." << endl
			<< "Show stats 7." << endl
			<< "Update Spieler 8." << endl
			
			
			
			
			<< "Ausgang! 0." << endl << endl;
		cout << "Auswahl: ";

		cin >> choice;


		while (cin.fail() ) {
			cout << "Falsche eingabe!" << "\n";
			cin.clear();
			cin.ignore();

			cout << endl << "Auswahl: ";
			cin >> choice;
		}

		
		cout << endl;

		switch (choice)
		{

		case 1:  // Spielintro oder starten   idk
			intro();
			break;


		case 2:			// Neuen Spielererstellen
			cin.ignore();
			createNewSpieler();
			saveSpieler();
			
			break;

		case 3:			// Laden Spieler
			loadSpieler();
			break;


		case 4:		// Save Spieler
			saveSpieler();
			break;

		case 5:  // char wählen
			selectSpieler();

			break;
		case 6: // Reisen / travel
			Travel();

			break;
			
		case 7:
			this->Spieler[activSpieler].printStats();
			break;

		case 8:
			levelUpSpieler();

			break;
		case 9:
			break;




		case 0:  // QUIT
			running = false;
			break;
		default:
			break;
		}


	




}

void TBGameClass::intro() {


	cout << "Es ist jetzt 10 Jahre her als du aufgebrochen bist in ein neues Land.\nNach einiger Zeit hast du auserhalb deiner Siedlung ein Haus gebaut.\nSeit 4 Jahren bist du Verheiratet und vor 2 Jahren habt ihr, ein Kind bekommen.\nAlles scheint für dich super zu laufen. \n\nEines Tages, als du von der Jagt nach Hause kommst, siehst du von weitem Rauch.... \nDu rennst auf dein Haus zu und findest nur noch Verkohlte Erde vor.\nPanisch sucht du nach deiner Frau und deinem Kind....\nDu findest aber niemanden. Als du in der Siedlung nach deine Familie frägst weiss keiner wo sie sind.\nNach ein Paar wochen vergeblicher Suche entschliesst du dich in die alte Heimat zurück zu kehren.\nDu hast alles verlohren und bedrückt und zu tiefst traurig, heuerst du am nächsten Schiff an." << endl;
	cout << "Du gehst an Bord und fragst nach den Kapitän.\nDu findest ihn und bevor du was sagen kannst, frägt er dich:\n"  << endl;
	
	cout << "Kapitän:\nFreut mich sie zu sehen, "  /* << Spieler[activSpieler].getName()  MUSS auf LEERE geprüft werden !*/<< endl << "Sie haben Glück wir wollten gerade los\n" << endl << "Du stellst dich an die Reling und siehst zu wie die letzen Vorräte an Bord gebracht werden.\n Der Kapitän gibt das Singal zur abfahr und die Reise Beginnt." << endl;
	cout << "Nach einiger Zeit zieht ein Gewitter auf, der Himmel wird dunken und das Schiff fängt an immer mehr zum schwanken an." << endl;
	cout << "Als Du Dich mit not an der Reling festhalten hörst du ein Lautes geräusch.\nDie nächste Welle wirft dich gegen die Schifswand und alles wird schwarz." << endl;
	cout << "Du wachst an einen einsamen Strand auf und merken wie du frieren und hunger hast." << endl;
	cout << "Du solltest dir was zum Essen suchen bevor es weiter geht!" << endl;




}



void TBGameClass::endGame()
{
}

void TBGameClass::createNewSpieler()
{

	string name = "";
	cout << " Wie soll dein Charakter heisen? : ";
	getline(cin, name);


	
	for (size_t i = 0; i < this->Spieler.size(); i++) {

		while (name == this->Spieler[i].getName()) {

			cout << "Fehler! Dieser Spieler ist bereits vorhanden!";
			cout << " Wie soll dein Charakter heisen? : ";
			getline(cin, name);
		}
	}


	Spieler.push_back(TBSpieler());
	activSpieler = Spieler.size() - 1;
	Spieler[activSpieler].initSpieler(name);
	


	
}

void TBGameClass::saveSpieler()
{
	ofstream outFile(fileName);

	if (outFile.is_open()) {

		for (size_t i = 0; i < Spieler.size(); i++) {

			outFile << Spieler[i].getAsString() << "\n";
		}
	}
	outFile.close();
}

void TBGameClass::loadSpieler()
{
	ifstream inFile(fileName);

	 this->Spieler.clear();

	string name = "";
	double xPos = 0.0;
	double yPos = 0.0;
	int level = 0;

	int exp = 0;
	int spielerStärke = 0;
	int spielerAusdauer = 0;
	int spielerAgi = 0;
	int spielerVita = 0;
	int spielerGenauigkeit = 0;
	int spielerInt = 0;
	int spielerMana = 0;
	int spielerLeben = 0;

	int spielerHunger = 0;
	int spielerDurst = 0;
	int spielerRuhe = 0;

	int verteidigung = 0;
	int statPoints = 0;

	int gold = 0;
	int distanceTravelled = 0;

	int skillPoints = 0 ;



	string line = "";
	stringstream str;

	if (inFile.is_open()) {

		while (getline (inFile, line)) {
			
			str.str (line);

			str >>  name;
			str >> xPos;
			str >> yPos;
			str >> level;


			str >> exp;
			str >> spielerStärke;
			str >> spielerAusdauer;
			str >> spielerAgi;
			str >> spielerVita;
			str >> spielerGenauigkeit;
			str >> spielerInt;
			str >> spielerMana;
			str >> spielerLeben;
			str >> spielerHunger;
			str >> spielerDurst;
			str >> spielerRuhe;
			str >> verteidigung;
			str >> statPoints;
			str >> gold;
			str >> distanceTravelled;
			str >> skillPoints;

	

			TBSpieler temp(name, xPos, yPos, level, exp, spielerStärke,
				spielerAusdauer, spielerAgi, 
				spielerVita, spielerGenauigkeit, spielerInt, spielerMana, spielerLeben, spielerHunger,
				spielerDurst, spielerRuhe, verteidigung, statPoints, gold, distanceTravelled, skillPoints);

			this->Spieler.push_back(TBSpieler(temp));

			//cout << Spieler[0].getAsString() << "\n";
			cout << str.str() << "\n";

			str.clear();
		}
	
	}

	inFile.close();

	if (this->Spieler.size() <= 0) {

		throw " spieler konnte nicht geladen werden !";
	}

}

void TBGameClass::selectSpieler()
{
	cout << "Wählen sie Ihren Spieler: " << "\n\n";

	for (size_t i = 0; i < this->Spieler.size(); i++) {

		cout << "Index: " << i <<" " <<  this->Spieler[i].getName() << " " << "Level: " << this->Spieler[i].getLevel() << "\n";
	}

	cout << "Auswahl: ";
	cin >> this->choice;


	while (cin.fail() || this->choice >= this->Spieler.size() || this-> choice < 0) {
		cout << "Falsche eingabe!" << "\n";
		cin.clear();
		cin.ignore();

		cout << endl << "Spieler auswählen: ";
		cin >> this->choice;
	}
	cout << "\n";

	this->activSpieler = this->choice;

	cout << this->Spieler[this->activSpieler].getName() << " ist jetzt ausgewählt!" << "\n";
}

void TBGameClass::levelUpSpieler()
{
	this->Spieler[activSpieler].levelUp();

	if (this->Spieler[activSpieler].getStatsPoints() > 0) {

		cout << "Statuspunkte zu vergeben !\n\n";
		cout << "Starten wir das Update: \n";
		
		cout << "Stärke 1" << "\n";
		cout << "Agilität 2" << "\n";
		cout << "Vitalität 3" << "\n";
		cout << "Intiligenz 4" << "\n";
		
		cin >> this->choice;


		while (cin.fail()|| this->choice > 4 || this->choice == 0) {
			cout << "Falsche eingabe!" << "\n";
			cin.clear();
			cin.ignore();

			cout << endl << "Auswahl:";
			cin >> this->choice;
		}
		
		cout << endl;

		switch (this->choice) {

		case 1: // Add Stärke +1
			this->Spieler[activSpieler].addToStats(1, 1);

			break;
		case 2:// add Agi +1
			this->Spieler[activSpieler].addToStats(2, 1);
			break;

		case 3: // add vita +1
			this->Spieler[activSpieler].addToStats(3, 1);
			break;

		case 4:		// add int + 1
			this->Spieler[activSpieler].addToStats(4, 1);
			break;

		default:
			cout << "kein richtige eingabe oder keine punkt vergabe möglich";
			break;
		}
		
	}




}

void TBGameClass::Travel() {

	this->Spieler[activSpieler].Travel();

	Event ev;

	ev.generateEvent(this->Spieler[activSpieler], this->gegner);

}