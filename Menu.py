import gameCore
g = gameCore.GameCore()

class Hauptmenu:

    ### Print aus wurf fürs hauptmenu #############################
    def print_hm(self):

        print("*" * 20)
        print('Willkommen zum Schiffeversenken')
        print("*" * 20)
        print('Bitte Wählen sie aus:')
        print('1 Start')
        print('2 Optionen')
        print('3 Exit')
        print('*' * 20)


    ### Menu loop ##############################################
    def start(self):
        run = True
        while run:
            Hauptmenu.print_hm(self)

            try:
                auswahl = int(input("Treffen sie ihre wahl:"))
            except ValueError:
                print("eine zahl zwischen 1 und 3!")


            if auswahl == 3:
                run = False

            elif auswahl == 1:
                g.GameLoop()


            elif auswahl == 2:
                print('Hier kommen irgendwan mal die Optionen')


# _____________________ eingabe prüfer erstellen ________________________