
#ifndef ruch_hpp

#define ruch_hpp
#include "plansza.hpp"

struct lista_ruchow {
	int wsp;
	lista_ruchow* nast;
public:
	lista_ruchow(int w) { wsp = w; nast = NULL; };
	~lista_ruchow() { delete nast; };
};

class ruch: public plansza {
	int to_x;
	int to_y;
	int from_x;
	int from_y;
public:
	ruch() : plansza(){ to_x = 0; to_y = 0; from_x = 0; from_y = 0; };
	ruch(int t_x, int t_y, int f_x, int f_y) { to_x = t_x; to_y = t_y; from_x = f_x; from_y = f_y;};
	int sprawdz_czy_mozliwy();
	void wykonaj_ruch();
	lista_ruchow* mozliwe_ruchy_poziom(int act_x, int act_y);
	lista_ruchow* mozliwe_ruchy_pion(int act_x, int act_y);
	void dodaj_ruch(int f_x, int f_y, int t_x, int t_y);
};
#endif // !ruch_hpp