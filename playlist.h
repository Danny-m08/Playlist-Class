#include"song.h"

class Playlist{

public:
	Playlist();
	~Playlist();

	void Addsong(char *s, char *a, Style c, int size);
	void Removesong(const char *search);
	void Show()const;
	void Menu()const;
	void Find(const char *search)const;
	void Sort(const char x);
	void ShowCategory(const Style genre)const;

	double Showsize()const;

private:

	void expand();			//expand by 5 when full
	void contract(int a);		//shrink by 1

	Song *library;
	int filledslots, slots;
};
