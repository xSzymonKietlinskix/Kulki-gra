#include "gra.hpp"

#define WAR_PRZEG 12
#define R 8

using namespace std;

void gra::wypisz_kolory(int* kolory, int poziom_trudnosci) {
	for (int i = 0; i < poziom_trudnosci; i++) {
		switch (kolory[i]) {
		case zielony:
			cout << "Z ";
			break;
		case niebieski:
			cout << "N ";
			break;
		case czerwony:
			cout << "C ";
			break;
		case ¿ó³ty:
			cout << "X ";
			break;
		case fioletowy:
			cout << "F ";
			break;
		}
	}
}


int gra::pytaj() {
	//metoda odpowiadj¹ca za komunikowanie siê z u¿ytkowniem w kwesti wykonywania ruchów
	int f_x;
	int f_y;
	int t_x;
	int t_y;
	cout << "skad?:";
	cin >> f_x;
	if (f_x != 1313) {
		cin >> f_y;
		while (f_x > 7 || f_x < 0 || f_y > 7 || f_y < 0) {
			cout << "Podales nie istniejace wspolrzedne! Popraw sie." << endl;
			cout << "skad?:";
			cin >> f_x;
			cin >> f_y;
		}
		cout << "dokad?";
		cin >> t_x;
		cin >> t_y;
		while (t_x > 7 || t_x < 0 || t_y > 7 || t_y < 0) {
			cout << "Podales nie istniejace wspolrzedne! Popraw sie." << endl;
			cout << "dokad?:";
			cin >> t_x;
			cin >> t_y;
		}
		dodaj_ruch(f_x, f_y, t_x, t_y);
		wykonaj_ruch();
		return 0;
	}
	return 1313;
}


void gra::graj(gracz* g1, gracz *g2, int poziom_trudnosci) {
	int* nastepne_kolory = new int[poziom_trudnosci + 1];
	//metoda odpowiadj¹ca za wywo³ywanie innych metod w odpowiedniej kolejnoœci
	int ile_usunietych = 0;
	int ile_kolejek = 0;
	plik* txt = new plik;
	wypisz();
	while (sprawdz_czy_pelna() >= WAR_PRZEG) {
		for (int i = 0; i < poziom_trudnosci; i++)
			nastepne_kolory[i] = rand() % 5 + 1;

		cout << "punkty gracza " << g1->get_nick() << ": " << g1->get_punkty() << endl;
		cout << "nastepne kolory: ";
		wypisz_kolory(nastepne_kolory,poziom_trudnosci);
		cout << endl;
		if (pytaj() == 1313)
			break;
		ile_usunietych = sprawdz_czy_usunac();
		if (ile_usunietych == 0) {
			dodaj_kulki(poziom_trudnosci, nastepne_kolory);
		}
		wypisz();
		if (ile_usunietych != 0)
			g1->dodaj_punkty(ile_usunietych);
		ile_kolejek++;
	}
	g1->set_ile_kolejek(ile_kolejek);
	txt->zapisz(g1);
}

void gra_dwuosobowa::graj(gracz* g1,gracz *g2, int poziom_trudnosci) {
	int* nastepne_kolory = new int[poziom_trudnosci];
	int ile_usunietych = 0;
	int ile_kolejek = 0;
	int czyja_kolej = 2;
	plik* txt = new plik;
	wypisz();
	while (sprawdz_czy_pelna() >= WAR_PRZEG) {
		for (int i = 0; i < poziom_trudnosci; i++)
			nastepne_kolory[i] = rand() % 5 + 1;
		cout << "punkty gracza " << g1->get_nick() << ": " << g1->get_punkty() << endl;
		cout << "punkty gracza " << g2->get_nick() << ": " << g2->get_punkty() << endl;
		wypisz_kolory(nastepne_kolory,poziom_trudnosci);

		cout << "Kolej gracza: ";
		if (czyja_kolej == 1)
			cout << g1->get_nick() << endl;
		else
			cout << g2->get_nick() << endl;
		if (pytaj() == 1313)
			break;
		ile_usunietych = sprawdz_czy_usunac();
		if (ile_usunietych == 0) {
			dodaj_kulki(poziom_trudnosci, nastepne_kolory);
		}
		if (ile_usunietych != 0) {
			if (czyja_kolej == 1)
				g1->dodaj_punkty(ile_usunietych);
			else
				g2->dodaj_punkty(ile_usunietych);
		}
		if (ile_kolejek % 2 != 0)
			czyja_kolej = 2;
		else
			czyja_kolej = 1;
		ile_kolejek++;
	}
	g1->set_ile_kolejek(ile_kolejek);
	txt->zapisz(g1,g2);
}
