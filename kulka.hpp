

#ifndef kulka_hpp

#define kulka_hpp
enum { pusty = 0, zielony = 1, ¿ó³ty = 2, czerwony = 3, fioletowy = 4, niebieski = 5 };

class kulka {
	int kolor;
public:
	kulka() { kolor = pusty; };
	kulka(int k) { kolor = k; };
	kulka(kulka& k) { kolor = k.kolor; };
	int get_kolor() { return kolor; };
	void zmien_kolor(int k) { kolor = k; };
};

#endif
