#include "ruch.hpp"	
#define R 8

using namespace std;
lista_ruchow* ruch::mozliwe_ruchy_poziom(int act_x, int act_y) {
	//zwraca g³owê jednokierunkowej dynamicznej listy mo¿liwych ruchów w poziomie z aktualnej pozycji
	lista_ruchow* glowa = NULL;
	lista_ruchow* wsk = NULL;
	for (int i = act_y - 1; i >= 0; i--) { //sprawdzanie na lewo od aktualnej pozycji
		if (get_pole(act_x, i) == pusty) {
			if (glowa == NULL) {
				glowa = new lista_ruchow(i);
				wsk = glowa;
			}
			else {
				wsk->nast = new lista_ruchow(i);
				wsk = wsk->nast;
			}
		}
		else
			break;
	}
	if (glowa == NULL) { //dodanie aktualnej pozycji
		glowa = new lista_ruchow(act_y);
		wsk = glowa;
	}
	else {
		wsk->nast = new lista_ruchow(act_y);
		wsk = wsk->nast;
	}
	for (int i = act_y + 1 ; i <= 7; i++) { //sprawdzanie na prawo od aktualnej pozycji
		if (get_pole(act_x, i) == pusty) {
			if (glowa == NULL) {
				glowa = new lista_ruchow(i);
				wsk = glowa;
			}
			else {
				wsk->nast = new lista_ruchow(i);
				wsk = wsk->nast;
			}
		}
		else
			break;
	}
	return glowa;
}

lista_ruchow* ruch::mozliwe_ruchy_pion(int act_x, int act_y) {
	//zwraca g³owê jednokierunkowej dynamicznej listy mo¿liwych ruchów w pionie z aktualnej pozycji. Powtórzony schemat metody z ruchami w poziomie.
	lista_ruchow* glowa = NULL;
	lista_ruchow* wsk = NULL;
	for (int i = act_x - 1; i >= 0; i--) {
		if (get_pole(i, act_y) == pusty) {
			if (glowa == NULL) {
				glowa = new lista_ruchow(i);
				wsk = glowa;
			}
			else {
				wsk->nast = new lista_ruchow(i);
				wsk = wsk->nast;
			}
		}
		else
			break;
	}
	if (glowa == NULL) {
		glowa = new lista_ruchow(act_x);
		wsk = glowa;
	}
	else {
		wsk->nast = new lista_ruchow(act_x);
		wsk = wsk->nast;
	}
	for (int i = act_x + 1; i <= 7; i++) {
		if (get_pole(i, act_y) == pusty) {
			if (glowa == NULL) {
				glowa = new lista_ruchow(i);
				wsk = glowa;
			}
			else {
				wsk->nast = new lista_ruchow(i);
				wsk = wsk->nast;
			}
		}
		else
			break;
	}
	return glowa;
}


int ruch::sprawdz_czy_mozliwy() {
	//metoda weryfikuj¹ca czy ruch jest mo¿liwy
	if (get_pole(to_x, to_y) != pusty) //pierwszy najprostszy warunek - pole docelowe musi byæ puste
		return -1;
	if (get_pole(from_x, from_y) == pusty)//drugi warunek - pole startowe nie mo¿e byæ puste
		return -1;
	int act_x = from_x;
	int act_y = from_y;
	int tab[R][R] = { 0 }; //tablica mozliwych ruchow
	//cztery listy dynamiczne jednokierunkowe zawieraj¹ce mo¿liwe ruchy na zmianê w poziomie i pionie
	lista_ruchow* g1 = NULL;
	lista_ruchow* g2 = NULL;
	lista_ruchow* g3 = NULL;
	lista_ruchow* g4 = NULL;
	lista_ruchow* g5 = NULL;
	lista_ruchow* w1 = NULL;
	lista_ruchow* w2 = NULL;
	lista_ruchow* w3 = NULL;
	lista_ruchow* w4 = NULL;
	lista_ruchow* w5 = NULL;
	g1 = mozliwe_ruchy_poziom(act_x, act_y);
	w1 = g1;
	//ogólny schemat dzia£ania algorytmu: dla ka¿dego mo¿liwego ruchu w poziomie znajduje wszytskie mo¿liwe w pionie, dla nich kolejne w poziomie a nastêpnie dla tych szuka ruchów w poziomie
	while (w1 != NULL) {
		tab[act_x][w1->wsp] = 1; //za ka¿dym razem uzupe³nia tablicê "1" w miejscu w które ruch jest mo¿liwy
		g2 = mozliwe_ruchy_pion(act_x, w1->wsp);
		w2 = g2;
		while (w2 != NULL) {
			tab[w2->wsp][w1->wsp] = 1;
			g3 = mozliwe_ruchy_poziom(w2->wsp, w1->wsp);
			w3 = g3;
			while (w3 != NULL) {
				tab[w2->wsp][w3->wsp] = 1;
				g4 = mozliwe_ruchy_pion(w2->wsp, w3->wsp);
				w4 = g4;
				while (w4 != NULL) {
					tab[w4->wsp][w3->wsp] = 1;
					g5 = mozliwe_ruchy_poziom(w4->wsp, w3->wsp);
					w5 = g5;
					while (w5 != NULL) {
						tab[w4->wsp][w5->wsp] = 1;
						w5 = w5->nast;
					}
					w4 = w4->nast;
				}
				w3 = w3->nast;
			}
			w2 = w2->nast;
		}
		w1 = w1->nast;
	}

	delete g1;
	delete g2;
	delete g3;
	delete g4;
	if (tab[to_x][to_y] == 1) //je¿eli w tablicy z mo¿liwymi ruchami s¹ wspó³rzedne docelowe to zwraca 0, je¿eli nie -1
		return 0;
	return -1;
}

void ruch::wykonaj_ruch() {
	//metoda wykonuj¹ca ruch
	if (sprawdz_czy_mozliwy() == 0) {
		kulka k(get_pole(from_x, from_y));
		zmien_pole(to_x, to_y, k);
		kulka k2;
		zmien_pole(from_x, from_y, k2);
	}
	else {
		cout << endl << "Ruch niemozliwy" << endl << endl;
	}
}

void ruch::dodaj_ruch(int f_x, int f_y, int t_x, int t_y) {
	//metoda dodaj¹ca wspó³rzêdne pocz¹tkowe i docelowe to obiektu ruch
	from_x = f_x;
	from_y = f_y;
	to_x = t_x;
	to_y = t_y;
}
