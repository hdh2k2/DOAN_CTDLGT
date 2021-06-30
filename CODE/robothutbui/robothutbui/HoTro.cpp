#include "HoTro.h"
#include "Menu.h"
#include <string>
#include <cmath>
#include"Graphics.h"


/*
######################################################################################################
*/


void InChuoiCoMau(float x, int y, int tColor, string text) {
	gotoXY(x, y);
	textColor(tColor);
	cout << text;
	textColor(7);
}

void InSoCoMau(float x, int y, int tColor, int so) {
	gotoXY(x, y);
	textColor(tColor);
	cout << so;
	textColor(7);
}

void KeKhungXuat(int size) { // size la so luong hang hoa
	Box* vienXuat = new Box;
	vienXuat->Set(WidthConsole / 70, (float)HeightConsole / 6.75,
		WidthConsole - (2 * (WidthConsole / 70)),
		6 + size, 74, "");
	// bi mat di 12 pixel chieu ngang nen tru di 12
	vienXuat->VeBox();
	delete vienXuat;
}
void VietBoxCoTieuDeCenTer(int y, int tColor, string text) {
	Box* title = new Box;
	int x = (WidthConsole / 2) - (text.length() / 2);
	title->Set(x, y, text.length() + 1, 2, tColor, text);
	title->VeBox();
	delete title;
}

void XoaBoxCoTieuDeCenTer(int y, int strlen) {
	Box* title = new Box;
	int x = (WidthConsole / 2) - (strlen / 2);
	title->Set(x, y, strlen + 1, 2, 0, "                     ");
	title->VeBox();
	delete title;
}

void VeBoxInput() {
	string* ip = new string[3];
	ip[0] = " MA SO SAN PHAM: ";
	ip[1] = " TEN THUONG HIEU: ";


	string* ip2 = new string[5];
	ip2[0] = " NGUON DIEN CAP PHAT: ";
	ip2[1] = " CHUNG CHI: HHD1806 ";

	VietBoxCoTieuDeCenTer(2, 41, " NHAP THONG TIN ROBOT ");
	InChuoiCoMau((float)WidthConsole / (float)1.3, HeightConsole * 9 / 10, ColorCode_Pink, "NHAN PHIM BAT KI DE TIEP TUC !");
	InChuoiCoMau((float)WidthConsole / (float)16, HeightConsole * 9 / 10, ColorCode_Pink, "NHAN PHIM ESE DE THOAT");
	Menu* input = new Menu((float)WidthConsole / (float)5.6, HeightConsole / 5, 2, 15, ip);
	input->SetWiHe(40, 4);
	Menu* input2 = new Menu((float)WidthConsole / (float)1.7, HeightConsole / 5, 2, 17, ip2);
	input2->SetWiHe(30, 4);
	input->VeMenu();
	input2->VeMenu();
}

void VeBoxOutput() {
	string* ip = new string[3];
	ip[0] = " MA SO SAN PHAM: ";
	ip[1] = " TEN THUONG HIEU: ";

	string* ip2 = new string[5];
	ip2[0] = " NGUON DIEN HIEN HANH (V): ";
	ip2[1] = " CHUNG CHI: _HHD_1806 ";

	VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 1, 5, " THONG TIN ROBOT HIEN HANH ");
	Menu* input = new Menu((float)WidthConsole / (float)4.8, HeightConsole - HeightConsole/3 - 2, 2, 12, ip);
	input->SetWiHe(35, 4);
	Menu* input2 = new Menu((float)WidthConsole / (float)1.7, HeightConsole - HeightConsole / 3 - 2, 2, 12, ip2);
	input2->SetWiHe(35, 4);
	input->VeMenu();
	input2->VeMenu();
}

void BoxCoChuCenter(int x, int y, int w, int h, int tColor, string text) {
	Box* t = new Box;
	t->Set(x, y, w, h, tColor, text);
	t->VeBoxChuCenter();
	delete t;
}




void _draw_Empty_Room() {
	string t = "MOI BAN THIET LAP PHONG !!!";
	int tColor = ColorCode_DarkPink;
	int w = 60;
	int h = 6;
	int x = WidthConsole / 2;
	int y = 7;
	x -= (t.length() / 2);
	x -= (w / 2 - t.length() / 2);
	BoxCoChuCenter(x, y, w, h, tColor, t);
}


void FrameIntro(int speed) {
	hideCur();
	textColor(5);

	for (int i = 0; i < WidthConsole - 1; i++) {
		gotoXY(i, 0);
		cout << (char)205;
		gotoXY(WidthConsole - 1 - i, HeightConsole - 1);
		cout << (char)205;
		Sleep(speed);
		// nhan phim bat ki cho no' bo qua
		if (_kbhit() && _getch()) speed = 0;
	}

	gotoXY(WidthConsole - 1, 0);
	cout << (char)187;
	gotoXY(0, 43);
	cout << (char)200;



	for (int i = 1; i < HeightConsole; i++)
	{
		gotoXY(WidthConsole - 1, i);
		cout << (char)186;
		gotoXY(0, HeightConsole-1 - i);
		cout << (char)186;
		Sleep(speed * 3);



		// nhan phim bat ki cho no' bo qua
		if (_kbhit() && _getch()) speed = 0;
	}



	gotoXY(0, 0);
	cout << (char)201;
	gotoXY(147, 43);
	cout << (char)188;
}
/*
######################################################################################################
*/

