#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <ctime>
using namespace std;

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

extern int WidthConsole;
extern int HeightConsole;

void clrscr();
void gotoXY(int, int);
int whereX();
int whereY();
void textColor(WORD);
void backgroundColor(WORD);
void printTextColor(int, int, string, WORD);
void resizeConsole(int, int);
void hideCur();
void showCur();
void clearLine(int, int);
void fullScreen();
void removeScrollBar();
void getWHConsole();

BOOL WINAPI SetConsoleTitle();