#pragma once
#include "Box.h"

class Menu
{
private:
	int x, y; // toa do cua box dau tien
	int w, h;
	int current; // toa do hien tai cua y
	int numboxs; // so luong box
	int tColor;
	Box* box; // list box
	string* text; // list chuoi
public:
	Menu();
	Menu(int, int, int, int, string*); // x, y, tColor, text
	~Menu();

	void SetWiHe(int, int);
	void VeMenu();
	void XoaMenu();
	void ChayMenu(int&); // bien check bam phim nao
};

