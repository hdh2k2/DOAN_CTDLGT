#pragma once
#include "Graphics.h"
#include <iostream>
#include <string>
using namespace std;

class Box
{
private:
	int x, y, w, h, tColor;
	string text;
public:
	Box();
	~Box();

	// x, y, w, h, tColor, text
	void Set(int, int, int, int, int, string);

	void VeBox();
	void VeBoxChuCenter();
	void VeBoxChon();

	void InChuoi();
	void InChuoiCenter();

	void XoaChuoi();
	void XoaBox();
	void XoaVien();
};

