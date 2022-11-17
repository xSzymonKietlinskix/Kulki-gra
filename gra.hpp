#ifndef gra_hpp

#define gra_hpp
#define _CRT_SECURE_NO_WARNINGS
#include "ruch.hpp"
#include "gracz.hpp"
#include "plik.hpp"

class gra : public ruch {
public:
	virtual void graj(gracz* g1,gracz *g2, int poziom_trudnosci);
	int sprawdz(int poziom_trudnosci);
	int pytaj();
	void wypisz_kolory(int* kolory, int poziom_trudnosci);
};


class gra_dwuosobowa : public gra {
public:
	void graj(gracz* g1, gracz* g2, int poziom_trudnosci);
};
#endif
