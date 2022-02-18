import spieler

spieler1 = spieler.Spieler()
spieler2 = spieler.Spieler()

verloren = False
                                        # 5               8             9           8 = 30
# jeder spieler hat ein spielfeld und 1 schlachtschiff , 2 kreutzer, 3 zerstörer und 4 uboote
# sind 10 legungen

class GameCore:

    ### Konstruktor ####################################
    def __init__(self):
        self.verloren = False

    ### funktion des game loop ########################
    def GameLoop(self):


        ## versuche aktive spieler zu wechseln


        spieler1.get_name()
        spieler2.get_name()

        spieler1.spielfeld.drawSchussfeld()
        spieler1.spielfeld.drawSpielfeld(spieler1.name)

        spieler1.setze_schiffe(spieler1.flotte)
        print()
        print("Spieler 2 ist jetzt dran")
        print()

        spieler2.spielfeld.drawSchussfeld()
        spieler2.spielfeld.drawSpielfeld(spieler2.name)
        spieler2.setze_schiffe(spieler2.flotte)

        print(" beide sind fertig mit setzen")
        print()
        print(" das schiessen beginnt ")
        while spieler.Spieler.punkte < 30: #########  TO DO   <<<<<< hilfe aktive spieler evtl liste packen

            spieler1.schiessen(spieler2.spielfeld.spielfeld_liste)
            spieler1.spielfeld.drawSpielfeld(spieler1.name)
            spieler1.spielfeld.drawSchussfeld()

            spieler2.schiessen(spieler1.spielfeld.spielfeld_liste)
            spieler2.spielfeld.drawSpielfeld(spieler2.name)
            spieler2.spielfeld.drawSchussfeld()

        print("gewonnen sie haben alle schiffe verstenkt ")
###  jetzt muss ich die spieler abwechseln lassen

### dan nocht siegesbedinungen festlegen  und out of range legen verhindern