#pragma comment(lib, "winmm.lib")
#include "_Branch_Begin.h"
#include<windows.h>
#include <iostream>

using namespace std;

_Branch_Begin::_Branch_Begin() {

}

_Branch_Begin::~_Branch_Begin() {

}

void _Branch_Begin::beging() {
	ChuTheoTiengNoi x;
	int i = 0;
	x.ChayChu(i);
	PlaySound(TEXT("loinoidau.wav"), NULL, SND_SYNC);
}