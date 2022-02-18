import Schiffe
import spielfeld
import Controller


class Spieler:

    name = ''
    punkte = 0
    ### konstruktor spielerclasse ###########################
    def __init__(self):
        self.spielfeld = spielfeld.Spielfeld()
        self.flotte = Schiffe.Schiffe.flotte
        self.punkte
        self.gegnerschussfeld = []
        self.name

    ### Funktion zum schiessen ##############################
    def schiessen(self, gegnerspielfeld):

        if self.punkte == 30:
            print("Sie haben Gewonnen!")
        else:

            self.gegnerspielfeld = gegnerspielfeld

            freierplatz = True
            while freierplatz:
                try:
                    ### Prüfungs block eingabe auf die x achse
                    bisxeingabetrue = True
                    while bisxeingabetrue:
                        aufschlagspunkt_1 = int(input("Geben sie die Position an wo sie Hinschiessen wollen ( x ):"))
                        if aufschlagspunkt_1 < 1 or aufschlagspunkt_1 > 10:
                            print("fehler eingabe!")
                        else:
                            print("Eingabe erfolgreich kannst passieren")
                            bisxeingabetrue = False

                    ### prüfungsblock auf die eingabe der y achse
                    bisyeingabetrue = True
                    while bisyeingabetrue:
                        aufschlagspunkt_2 = int(input("Geben sie die Position an wo sie Hinschiessen wollen ( y ):"))
                        if aufschlagspunkt_2 < 1 or aufschlagspunkt_2 > 10:
                            print("fehler eingabe!")
                        else:
                            print("Eingabe erfolgreich kannst passieren")
                            bisyeingabetrue = False
                    aufschlagspunkt_1 = aufschlagspunkt_1 - 1
                    aufschlagspunkt_2 = aufschlagspunkt_2 - 1
######      Noch mal genau prüfen und erneut schiessen lassen!
                    ### punkte überprüfen

                    if self.gegnerspielfeld[aufschlagspunkt_1][aufschlagspunkt_2] == 'X':
                        print("Sie haben dort schon ein mal hin geschossen")
                    if self.gegnerspielfeld[aufschlagspunkt_1][aufschlagspunkt_2] == 'O':
                        print("Sie haben dort schon ein mal hin geschossen")



                    if self.gegnerspielfeld[aufschlagspunkt_1][aufschlagspunkt_2] == ' ':
                        self.gegnerspielfeld[aufschlagspunkt_1][aufschlagspunkt_2] = 'O'
                        self.spielfeld.schuss_feld[aufschlagspunkt_1][aufschlagspunkt_2] = 'O'
                        print("Wasser")
                        freierplatz = False

                    if self.gegnerspielfeld[aufschlagspunkt_1][aufschlagspunkt_2] == "S":
                        self.gegnerspielfeld[aufschlagspunkt_1][aufschlagspunkt_2] = 'X'
                        self.spielfeld.schuss_feld[aufschlagspunkt_1][aufschlagspunkt_2] = 'X'
                        self.punkte += 1
                        print(self.punkte)
                        print("Treffer")
                        freierplatz = False




                except ValueError:
                    print("deine Eingabe ist falsch!")
                else:
                    break







        return self.gegnerspielfeld

    ### Funktion zum setzen der schiffe auf die karte #################

    def setze_schiffe(self, flotte):





        ################################################################################## schleife durch die flotte
        for a, b in flotte:
            zähler = a
            while zähler:
                zähler = zähler - 1
                platzfrei = False
                while platzfrei != True:
                    ############################################################# Eingabe wo die schiffe plaziert werden


                    c = Controller.Controller()
                    richtigeEingabe = True
                    richtigeEingabe2 = True
                    while richtigeEingabe:
                        x = c.richtigeEingabeX()
                        if type(x) == int:
                            richtigeEingabe = False

                    while richtigeEingabe2:
                        y = c.richtigeEingabeY()

                        if type(y) == int:
                            richtigeEingabe2 = False


                    platzfrei = c.feldLeer(x, y, self.spielfeld.spielfeld_liste)

                    platzfrei = c.pruefungAusbreitung2(b, x, y)


                print("Das U-Boote soll gelegt werden. auf der x oder y achse?")
                ausbreitung = False
                while ausbreitung != True:
                    z = c.richtungsEingabe()
                    ausbreitung = c.pruefungAusbreitung(b, x, y, z, self.spielfeld.spielfeld_liste)
                ################################################################# test ob schiff liegt



                ########################################################  größe der schiffe auf die karte eintragen
                if z == 'x':
                    print("prüfe auf x achse")
                    zahler = 0
                    while zahler < b:
                        zahler = zahler + 1
                        self.spielfeld.spielfeld_liste[x][y] = 'S'
                        x = x + 1

                if z == 'y':
                    zahler = 0
                    while zahler < b:
                        zahler = zahler + 1
                        self.spielfeld.spielfeld_liste[x][y] = 'S'
                        y = y + 1
                ####################################################################################################
                self.spielfeld.drawSchussfeld()
                self.spielfeld.drawSpielfeld(self.name)

        return self.spielfeld.spielfeld_liste

    ### funktion zum spielfeld returnen #########################
    def get_spielfeld(self):
        return self.spielfeld.spielfeld_liste

    ### funktion zum namen festlegen #######################
    def get_name(self):
        self.name = str(input("Geben sie ihren Namen ein:"))
