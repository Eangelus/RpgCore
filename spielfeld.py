
class Spielfeld:

    spielfeld_liste = []
    schuss_feld = []

    # #################################### Konstruktor ###################### #     DONE
    def __init__(self):
        self.liste_1 = []
        self.liste_2 = []
        self.liste_3 = []
        self.liste_4 = []
        self.liste_5 = []
        self.liste_6 = []
        self.liste_7 = []
        self.liste_8 = []
        self.liste_9 = []
        self.liste_0 = []

        self.liste_a = []
        self.liste_b = []
        self.liste_c = []
        self.liste_d = []
        self.liste_e = []
        self.liste_f = []
        self.liste_g = []
        self.liste_h = []
        self.liste_i = []
        self.liste_j = []

        self.anzeige_liste = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
        self.spielfeld_liste = []

        self.schussfeld = []
        for i in range(10):
            self.liste_1.append(" ")

        for i in range(10):
            self.liste_2.append(" ")

        for i in range(10):
            self.liste_3.append(" ")

        for i in range(10):
            self.liste_4.append(" ")

        for i in range(10):
            self.liste_5.append(" ")

        for i in range(10):
            self.liste_6.append(" ")

        for i in range(10):
            self.liste_7.append(" ")

        for i in range(10):
            self.liste_8.append(" ")

        for i in range(10):
            self.liste_9.append(" ")

        for i in range(10):
            self.liste_0.append(" ")

        for i in range(10):
            self.liste_a.append(" ")

        for i in range(10):
            self.liste_b.append(" ")

        for i in range(10):
            self.liste_c.append(" ")

        for i in range(10):
            self.liste_d.append(" ")

        for i in range(10):
            self.liste_e.append(" ")

        for i in range(10):
            self.liste_f.append(" ")

        for i in range(10):
            self.liste_g.append(" ")

        for i in range(10):
            self.liste_h.append(" ")

        for i in range(10):
            self.liste_i.append(" ")

        for i in range(10):
            self.liste_j.append(" ")




        self.schuss_feld = [self.liste_a,
        self.liste_b,
        self.liste_c,
        self.liste_d,
        self.liste_e,
        self.liste_f,
        self.liste_g,
        self.liste_h,
        self.liste_i,
        self.liste_j]


        self.spielfeld_liste = [self.liste_1, self.liste_2, self.liste_3, self.liste_4, self.liste_5,
                                self.liste_6, self.liste_7, self.liste_8, self.liste_9, self.liste_0]



    ################################### Spielfeld ausgeben auf der console #################### #    DONE
    def drawSpielfeld(self, spielername):
        name = spielername
        print()
        print("___Das ist ihr Spielfeld___",name )
        a = 1
        print('  ', self.anzeige_liste)
        for i in self.spielfeld_liste:

            print(a, i)
            a = a + 1
        print()

    ######################################## printe schussfeld ################################################
    def drawSchussfeld(self):
        print()
        print("___Gegnerspielfeld___")
        a = 1
        print(' ', self.anzeige_liste)
        for i in self.schuss_feld:
            print(a, i)
            a = a + 1
        print()



