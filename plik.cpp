#include "plik.hpp"
#include <string>
#include <time.h>
#define R 8
void plik::zapisz(gracz *g) {
	//metoda zapisuj¹ca do pliku
	FILE* source;
	if ((source = fopen(nazwa, "a+")) == NULL) {
		perror("Nie udalo sie otworzyc pliku!");
	}
	else {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		fprintf(source, "%s %s usuniecia: %d kolejki: %d \n", buf, g->get_nick(), g->get_punkty(), g->get_ile_kolejek());
		fclose(source);
	}
}

void plik::zapisz(gracz* g1, gracz *g2) {
	//jw, z tym ¿e dla dwóch graczy
	FILE* source;
	if ((source = fopen(nazwa, "a+")) == NULL) {
		perror("Nie udalo sie otworzyc pliku!");
	}
	else {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		fprintf(source, "%s Tryb Dwuosobowy Gracz 1: %s usuniecia: %d Gracz 2: %s usuniecia: %d kolejki: %d\n", buf, g1->get_nick(), g1->get_punkty(), g2->get_nick(), g2->get_punkty(), g1->get_ile_kolejek());
		fclose(source);
	}
}

void plik::wczytaj() {
	//wczytywanie z pliku
	ifstream source;
	string line;
	source.open(nazwa); 
	if (!source) {
		cerr << "Blad: nie mozna otworzyc pliku" << endl;
		exit(1);
	}
	getline(source, line);
	cout << line << endl;
	while (!source.eof()) {
		getline(source, line);
		cout << line << endl;
	}
	source.close();

}