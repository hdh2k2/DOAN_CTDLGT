#pragma once
#include <iomanip>

#include <string>
#include "Graphics.h"
#include "Box.h"
using namespace std;



void InChuoiCoMau(float, int, int, string);
void InSoCoMau(float, int, int, int);
void KeKhungXuat(int size);
void VietBoxCoTieuDeCenTer(int, int, string);
void XoaBoxCoTieuDeCenTer(int, int);


void BoxCoChuCenter(int, int, int, int, int, string);
void VeBoxInput();
void VeBoxOutput();

void _draw_Empty_Room();
void _draw_out_Information();

void FrameIntro(int speed);



