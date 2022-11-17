#include "plansza.hpp"

#define R 8
using namespace std;
plansza::plansza() {
	//generowanie nowej planszy z trzema kulkami
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++) {
		int r_x = rand() % R;
		int r_y = rand() % R;
		while (tab[r_x][r_y].get_kolor() != pusty)
			r_y = rand() % R;
		int kolor = rand() % 5 + 1;
		tab[r_x][r_y].zmien_kolor(kolor);
	}
}

int plansza::sprawdz_czy_usunac() {
	//sprawdza czy gdzieœ na planszy jest piêæ kulek w tym samym kolorze
	int punkty = 0;
	int licznik = 0;
	int pop_kolor = get_pole(0, 0);
	int act_kolor;
	//sprawdaznie w poziomie
	for (int i = 0; i < R; i++) {
		licznik = 0;
		for (int j = 0; j < R; j++) {
			act_kolor = get_pole(i, j);
			if (pop_kolor == act_kolor && act_kolor != pusty)
				licznik++;
			else
				licznik = 0;
			if (licznik == 4) {
				punkty++;
				for (int k = 0; k < 5; k++) {
					kulka kul(pusty);
					zmien_pole(i, j - k, kul);
				}
				licznik = 0;
			}
			pop_kolor = act_kolor;
		}
	}
	//sprawdzanie w pionie
	pop_kolor = get_pole(0, 0);
	for (int i = 0; i < R; i++) {
		licznik = 0;
		for (int j = 0; j < R; j++) {
			act_kolor = get_pole(j, i);
			if (pop_kolor == act_kolor && act_kolor != pusty)
				licznik++;
			else
				licznik = 0;
			if (licznik == 4) {
				punkty++;
				for (int k = 0; k < 5; k++) {
					kulka kul(pusty);
					zmien_pole(j - k, i, kul);
				}
				licznik = 0;
			}
			pop_kolor = act_kolor;
		}
	}

	//sprawdzanie ukos

	pop_kolor = get_pole(0, 0);
	for (int i = 0; i < R; i++) {
		licznik = 0;
		for (int j = 0; j < R; j++) {
			act_kolor = get_pole(i+j, j);
			if (pop_kolor == act_kolor && act_kolor != pusty)
				licznik++;
			else
				licznik = 0;
			if (licznik == 4) {
				punkty++;
				for (int k = 0; k < 5; k++) {
					kulka kul(pusty);
					zmien_pole(j - k, i, kul);
				}
				licznik = 0;
			}
			pop_kolor = act_kolor;
		}
	}
	pop_kolor = get_pole(R-1, 0);
	for (int i = R-1; i >= 0; i--) {
		licznik = 0;
		for (int j = 0; j < R; j++) {
			act_kolor = get_pole(i - j, j);
			if (pop_kolor == act_kolor && act_kolor != pusty)
				licznik++;
			else
				licznik = 0;
			if (licznik == 4) {
				punkty++;
				for (int k = 0; k < 5; k++) {
					kulka kul(pusty);
					zmien_pole(i - j + k, j - k, kul);
				}
				licznik = 0;
			}
			pop_kolor = act_kolor;
		}
	}
	pop_kolor = get_pole(0, R-1);
	for (int i = 0; i < R; i++) {
		licznik = 0;
		for (int j = R-1; j >= 0; j--) {
			act_kolor = get_pole(i + R-1-j, j);
			if (pop_kolor == act_kolor && act_kolor != pusty)
				licznik++;
			else
				licznik = 0;
			if (licznik == 4) {
				punkty++;
				for (int k = 0; k < 5; k++) {
					kulka kul(pusty);
					zmien_pole(i + R -1 - j - k, j + k, kul);
				}
				licznik = 0;
			}
			pop_kolor = act_kolor;
		}
	}
	pop_kolor = get_pole(R-1, R-1);
	for (int i = R - 1; i >= 0; i--) {
		licznik = 0;
		for (int j = R - 1; j >= 0; j--) {
			act_kolor = get_pole(i - (R - j - 1), j);
			if (pop_kolor == act_kolor && act_kolor != pusty)
				licznik++;
			else
				licznik = 0;
			if (licznik == 4) {
				punkty++;
				for (int k = 0; k < 5; k++) {
					kulka kul(pusty);
					zmien_pole(i - (R - j - 1) + k, j + k, kul);
				}
				licznik = 0;
			}
			pop_kolor = act_kolor;
		}
	}


	//zwaraca liczbê usuniêæ
	return punkty;
}

void plansza::dodaj_kulki(int ile, int* kolory) {
	//dodaje ..ile.. kulek co kolejkê
	for (int i = 0; i < ile; i++) {
		int r_x = rand() % R;
		int r_y = rand() % R;
		while (tab[r_x][r_y].get_kolor() != pusty) {
			r_x = rand() % R;
			r_y = rand() % R;
		}
		tab[r_x][r_y].zmien_kolor(kolory[i]);
	}
}



void plansza::wypisz() {
	//wypisuje planszê
	for (int k = 0; k < R; k++) {
		if (k == 0)
			cout << " ";
		cout.width(3);
		cout << k << " ";
	}
	cout << endl;
	for (int i = 0; i < R; i++) {
		cout << "--------------------------------" << endl;
		for (int j = 0; j < R; j++) {
			if (j == 0)
				cout << i << "|";
			else {
				cout.width(3);
				cout << "|";
			}
			int to_print = tab[i][j].get_kolor();
			switch (to_print) {
			case pusty:
				cout << " ";
				break;
			case zielony:
				cout << "Z";
				break;
			case niebieski:
				cout << "N";
				break;
			case czerwony:
				cout << "C";
				break;
			case ¿ó³ty:
				cout << "X";
				break;
			case fioletowy:
				cout << "F";
				break;
			}
		}
		cout << endl;
	}
}

int plansza::sprawdz_czy_pelna(){
	//sprawdza liczbê wolnych pól na planszy
	int puste = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < R; j++) {
			if (get_pole(i, j) == pusty)
				puste++;
		}
	}
	return puste;
}
