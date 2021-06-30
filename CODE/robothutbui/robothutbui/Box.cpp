#include "Box.h"

Box::Box() {
	this->x = this->y = this->w = this->h = 0;
	this->tColor = 1;
	this->text = "";
}
Box::~Box() {
	this->x = this->y = this->w = this->h = 0;
	this->tColor = 1;
	this->text = "";
}

void Box::Set(int x, int y, int w, int h, int tColor, string text) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->tColor = tColor;
	this->text = text;
}
void Box::VeBox() {
	textColor(this->tColor);
	int i;
	for (i = 0; i <= this->w; i++)
	{
		gotoXY(this->x + i, this->y);
		cout << (char)196;
		gotoXY(this->x + i, this->y + this->h);
		cout << (char)196;
	}
	for (i = 0; i <= this->h; i++)
	{
		gotoXY(this->x, this->y + i);
		cout << (char)179;
		gotoXY(this->x + this->w, this->y + i);
		cout << (char)179;
	}
	gotoXY(this->x, this->y);
	cout << (char)218;
	gotoXY(this->x + this->w, this->y);
	cout << (char)191;
	gotoXY(this->x, this->y + this->h);
	cout << (char)192;
	gotoXY(this->x + this->w, this->y + this->h);
	cout << (char)217;
	this->InChuoi();
	gotoXY(this->x + this->w, this->y + this->h);
}
void Box::VeBoxChuCenter() {
	this->VeBox();
	this->XoaChuoi();
	this->InChuoiCenter();
}
void Box::VeBoxChon() {
	this->x -= 2;
	gotoXY(this->x - 3, this->y + 2);
	textColor(this->tColor);
	cout << ">>";
	textColor(7);
	this->VeBox();
	this->x += 2;
}
void Box::InChuoi() {
	textColor(this->tColor);
	gotoXY(this->x + 1, this->h / 2 + this->y);
	cout << this->text;
	textColor(7);
}
void Box::InChuoiCenter() {
	int xx = this->w / 2 - this->text.length() / 2 + this->x;
	int yy = this->h / 2 + this->y;
	gotoXY(xx, yy);
	textColor(tColor);
	cout << this->text;
	textColor(7);
}
void Box::XoaChuoi() {
	textColor(7);
	for (int i = 1; i <= this->text.length(); i++)
	{
		gotoXY(this->x + i, this->h / 2 + this->y);
		cout << " ";
	}
}
void Box::XoaBox() {
	for (int i = this->x - 5; i <= this->x + this->w; i++)
	{
		for (int j = this->y; j <= this->y + this->h; j++) {
			gotoXY(i, j);
			cout << " ";
		}
	}
}
void Box::XoaVien() {
	int i;
	for (i = 0; i <= this->w; i++)
	{
		gotoXY(this->x + i, this->y);
		cout << " ";
		gotoXY(this->x + i, this->y + this->h);
		cout << " ";
	}
	for (i = 0; i <= this->h; i++)
	{
		gotoXY(this->x, this->y + i);
		cout << " ";
		gotoXY(this->x + this->w, this->y + i);
		cout << " ";
	}
}