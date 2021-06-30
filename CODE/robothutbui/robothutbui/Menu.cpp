#include "Menu.h"

Menu::Menu() {
	this->x = this->y = this->numboxs = this->current = 0;
	this->box = NULL;
	this->text = NULL;
	this->w = 0;
	this->h = 0;
	// mac dinh w = 30, h = 4 danh cho 1 cai box
}
Menu::Menu(int x, int y, int numboxs, int tColor, string* text) {
	this->x = x;
	this->y = y;
	this->w = 30;
	this->h = 4;
	this->numboxs = numboxs;
	this->tColor = tColor;
	this->text = text;
	this->box = new Box[this->numboxs + 1];

	for (int i = 0; i < this->numboxs; i++) {
		//============= x, y, w, h, tColor, text
		this->box[i].Set(this->x, this->y + (i * 4) + i, this->w, this->h, tColor, this->text[i]);
	}

	// tao box khung
	this->box[this->numboxs].Set(this->x - 7, this->y - 2,
		this->w + 7 * 2, this->h * this->numboxs + this->numboxs + 3, tColor, ""
	);

	this->current = 0;
}
Menu::~Menu() {
	this->w = this->h = 0;
	this->x = this->x = 0;
	this->current = 0;
	this->numboxs = 0;
	delete[] this->box;
	delete[] this->text;
}
void Menu::SetWiHe(int w, int h) {
	this->w = w;
	this->h = h;
	for (int i = 0; i < this->numboxs; i++) {
		//============= x, y, w, h, tColor, text
		this->box[i].Set(this->x, this->y + (i * 4) + i, this->w, this->h, tColor, this->text[i]);
	}

	// tao box khung
	this->box[this->numboxs].Set(this->x - 7, this->y - 2,
		this->w + 7 * 2, this->h * this->numboxs + this->numboxs + 3, tColor, ""
	);
}
void Menu::VeMenu() {
	this->box[this->numboxs].VeBox(); // ve cai khung box truoc
	for (int i = 0; i < this->numboxs; i++) {
		this->box[i].VeBox();
	}
}
void Menu::XoaMenu() {
	for (int i = 0; i < this->numboxs; i++) {
		this->box[i].XoaBox();
	}
}
void Menu::ChayMenu(int& Check) {
	this->current = 0;
	int boxLast = 0;
	bool bamPhim = false;
	this->VeMenu();
	this->box[boxLast].XoaBox();
	this->box[this->current].VeBoxChon();
	while (true) {
		if (_kbhit()) // bam phim
		{
			char key = _getch();
			if (key == -32) { //  mui ten
				key = _getch();
				bamPhim = true;
				boxLast = this->current;
				if (key == 72) // up
				{
					if (this->current == 0) {
						this->current = this->numboxs - 1;
					}
					else {
						this->current--;
					}
				}
				else if (key == 80) // down
				{
					if (this->current == this->numboxs - 1) {
						this->current = 0;
					}
					else {
						this->current++;
					}
				}
			}
			else if (key == 13) // enter
			{
				this->box[this->numboxs].XoaVien();
				this->box[this->current].XoaBox();
				this->box[this->current].VeBox();
				Check = this->current + 1; // dang dung o box thu (Check)
				break;
			}
		}
		if (bamPhim == 1) {
			bamPhim = false;
			this->box[this->current].XoaBox();
			this->box[this->current].VeBoxChon();
			this->box[boxLast].XoaBox();
			this->box[boxLast].VeBox();
		}
	}
}