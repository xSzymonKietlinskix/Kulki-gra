#ifndef gracz_hpp

#define gracz_hpp
#include <iostream> 
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class gracz {
	char nick[20];
	int punkty;
	int ile_kolejek;
public:
	gracz() { strcpy(nick, "brak"); punkty = 0; ile_kolejek = 0; };
	~gracz() {};
	gracz(char *n) { strcpy(nick, n); punkty = 0; ile_kolejek = 0;};
	gracz(gracz& g) { strcpy(nick, g.nick); punkty = g.punkty; ile_kolejek = g.ile_kolejek; };
	char* get_nick() { return nick; };
	int get_punkty() { return punkty; };
	int get_ile_kolejek() { return ile_kolejek; };
	void set_ile_kolejek(int ile) { ile_kolejek = ile; };
	void set_nick(char *n) { strcpy(nick, n); };
	void set_punkty(int p) { punkty = p; };
	void dodaj_punkty(int ile) { punkty = punkty + ile; };
};

#endif
