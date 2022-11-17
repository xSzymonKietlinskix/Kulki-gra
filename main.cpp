#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <windows.h>  
#include <fstream>

#include "kulka.hpp"
#include "plansza.hpp"
#include "ruch.hpp"
#include "gracz.hpp"
#include "plik.hpp"
#include "gra.hpp"
using namespace std;

#define R 8


int main() {
	gracz* g1 = new gracz;
	gracz* g2 = new gracz;
	plik* txt = new plik;
	int poziom_trudnosci = 3;
	char nick[20];
	gra* new_game = NULL;
	cout << "############################" << endl;
	cout << "KULKI" << endl;
	cout << "############################" << endl;
	int wybor = 1;
	while (wybor != 6) {
		cout << "MENU:" << endl;
		cout << "1. Jeden gracz" << endl;
		cout << "2. Dwoch graczy" << endl;
		cout << "3. Pokaz statystyki" << endl;
		cout << "4. Zasady gry" << endl;
		cout << "5. Zmien poziom trudnosci" << endl;
		cout << "6. Wyjdz z gry" << endl;
		
		cin >> wybor;
		if (wybor > 6 || wybor < 0) {
			perror("Wybrales nie istniejaca opcje! Sprobuj jeszcze raz. \n");
			continue;
		}
		switch (wybor) {
		case 1:
			cout << "Podaj swoj nick:";
			cin >> nick;
			g1->set_nick(nick);
			new_game = new gra;
			new_game->graj(g1,g2,poziom_trudnosci);
			cout << "Koniec gry" << endl << endl;
			break;
		case 2:
			cout << "Podaj nick gracza pierwszego:";
			cin >> nick;
			g1->set_nick(nick);
			cout << "Podaj nick drugiego gracza:";
			cin >> nick;
			g2->set_nick(nick);
			new_game = new gra_dwuosobowa;
			new_game->graj(g1, g2,poziom_trudnosci);
			cout << "Koniec gry" << endl << endl;
			break;
		case 3:
			txt->wczytaj();
			break;
		case 4:
			{
			plik * zasady = new plik;
			char nazwa[20] = "zasady";
			zasady->set_nazwa(nazwa);
			zasady->wczytaj();
			delete zasady;
			break;
			}
		case 5:
			cout << "Wybierz poziom trudnosci:" << endl;
			cout << "1. Latwy (3 kulki co ruch)" << endl << "2. trudny (5 kulek co ruch)" << endl << "3. absurdalny (10 kulek co ruch)" << endl;
			int poz;
			cin >> poz;
			if (poz == 1)
				poziom_trudnosci = 3;
			if (poz == 2)
				poziom_trudnosci = 5;
			if (poz == 3)
				poziom_trudnosci = 10;
			else
				cout << "Wybrales nieistniejaca opcje! Wybrano poziom domyslny: latwy" << endl;
			break;
		case 6:
			break;
		default:
			break;
		}
	}

	delete txt;
	delete g1;
	delete g2;
	delete new_game;

	cout << "press any key to exit...";
	getchar();
	return 0;
}