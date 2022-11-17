#ifndef plansza_hpp

#define plansza_hpp

#include "kulka.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

#define R 8

class plansza {
	kulka tab[R][R];
public:
	plansza();
	void wypisz();
	void dodaj_kulki(int ile, int* kolory);
	int get_pole(int x, int y) { return tab[x][y].get_kolor(); };
	void zmien_pole(int x, int y, kulka k) { tab[x][y] = k; };
	int sprawdz_czy_usunac();
	int sprawdz_czy_pelna();

};

#endif