#ifndef plik_hpp

#define plik_hpp
#define _CRT_SECURE_NO_WARNINGS
#include "gracz.hpp"
class plik {
	char nazwa[20];
public:
	plik() { strcpy(nazwa, "statystyki.txt"); };
	~plik() {};
	plik(char* n) { strcpy(nazwa, n); strcat(nazwa, ".txt");};
	void set_nazwa(char*n) { strcpy(nazwa, n); strcat(nazwa, ".txt"); };
	void zapisz(gracz *g);
	void zapisz(gracz* g1, gracz* g2);
	void wczytaj();
};


#endif