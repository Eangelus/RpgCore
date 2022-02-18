class Controller:

    def __init__(self ):
        pass



    def richtigeEingabeX(self):

            try:
                x = int(input("Geben sie die Position der schiffe an ( 1 bis 10):"))

                ### Prüfungs block eingabe auf die x achse

                if x < 1 or x > 10:
                    print("fehler eingabe!")


                else:
                    print("X Eingabe erfolgreich kannst passieren")

                    x = x - 1
                    return x
            except ValueError:
                print("deine Eingabe ist falsch!")


    def richtigeEingabeY(self):

        try:
            y = int(input("Geben sie die Position der schiffe an ( a bis j (1 bis 10):"))

            ### prüfungsblock auf die eingabe der y achse

            if y < 1 or y > 10:
                print("fehler eingabe!")

            else:
                y = y - 1
                return y
            ### abziehen wegen listen index

        except ValueError:
            print("deine Eingabe ist falsch!")


    def feldLeer(self, x, y, liste):

        if liste[x][y] == ' ':
            print(" Platz ist frei und kann den ersten stein legen")
            return True
        else:
            print("Der platz ist belegt")
            return False

    def richtungsEingabe(self):
        bisAchseeingabeTrue = False
        while bisAchseeingabeTrue != True:
            z = input("X oder Y Achse? ( x / y) :").lower()
            if z == 'x' or z == 'y':
                print("eingabe richtig")
                return z
                bisAchseeingabeTrue = True
            else:
                print("falsche eingabe!")

    def pruefungAusbreitung2(self,b, x, y):
        summe = b + y
        summe2 = b + x
        wieviel = x - b
        wieviel2 = y - b
        if summe2 >= 10:
            print("Ihr Schiff ist auf der X Achse zu große um ", wieviel )

        if summe >= 10:
            print("Ihr Schiff ist auf der Y Achse zu große um ", wieviel2)

        elif summe >= 10 and summe2 >= 10:
            print( "Ihr Schiff passt in beide Richtungen nicht ohne über die Karte zu kommen !")
            return False


        else:
            return True

    def pruefungAusbreitung(self,b, x, y, z, liste):

        if z == 'x':
            print("prüfe auf x achse")
            zahler = 0
            while zahler < b:
                zahler = zahler + 1
                x = x + 1
                if x >= 10:
                    print("geht über die karte hinaus!")
                    break


                else:
                    if liste[x][y] == 'S':
                        print("hier ist ein patz nicht frei")
                        return False
                    else:
                        return True
        if z == 'y':
            print("prüfe auf y achse")
            zahler = 0
            while zahler < b:
                y = y + 1
                zahler = zahler + 1
                if y >= 10:
                    print("geht über die karte hinaus!")
                    break


                else:
                    if liste[x][y] == 'S':
                        print("hier ist ein patz nicht frei")
                        return False
                    else:
                        return True
