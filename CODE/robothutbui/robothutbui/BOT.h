#pragma once
#include"Room.h"


class BOT {
private:
	string _tenthuongHieu;
	string _masosanPham;
	int _hoanhDo;
	int _tungDo;
	char dir;
	int delay;
	int count_delay;
	int Volte;
public:
	BOT();
	~BOT();

	string _getter_tenthuongHieu();
	string _getter_masosanPham();
	int getterHoanhdo();
	int getterTungdo();
	char getter_Dir();
	int getterDelay();
	int gettercount_Delay();
	int getter_Volte();

	void _setter_tenthuongHieu(string _tenthuongHieu);
	void _setter_masosanPham(string _masosanPham);
	void setterHoanhdo(int _hoanhDo);
	void setterTungdo(int _tungDo);
	void setterDir(char dir);
	void setterDelay(int delay);
	void settercount_Delay(int count_delay);
	void setterVolte(int Volte);


	void draw();
	void move( int& _hoanhdo, int& _tungdo);
	void move_for_USER(int& _hoanhdo, int& _tungdo);
	bool collision(int fx, int fy);
	void _hut_bui();
	void _hut_bui_for_hard();
	bool empty(int fx, int fy);

	void input();
	void _luuthongtin_tubanphim();
	void _keKhungThongTin_TrangThaiBot();
	void _getthongTin();
	void _inputfromfile();

	void _ACTICE_Normal();
	void _ACTICE_Medium( int& CASE );
	void _ACTICE_Hard();
	void _ACTICE_FOR_USER();
	
	void KiemTraNguonDien(int &tralve);
	void _hienthitoadohienhanh(int& hoanh_do, int& tung_do);
	
};

