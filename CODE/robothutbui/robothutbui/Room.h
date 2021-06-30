#pragma once
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include <algorithm>
#include<vector>


using namespace std;

extern int const _docaoStage;
extern int const _dorongStage;
extern int const XX;
extern int const YY;

extern int tralve;



#if 1 // 11x20
extern	char map[11][20];
extern	char stage[11][20];
extern	char map_for_pathfinding[11][20];
extern	char FRAME[15][32];
extern	char FRAME_MAP[15][32];
#endif 


void setup();
void input(string  DoKho);
void layout();
void init_MAP();
void init_MAP_FOR_HARD();
void display();
void movements(int& _hoanhdo, int& _tungdo);
void movements_for_USER(int& _hoanhdo, int& _tungdo);

void init(int index);
void branchMaster();
bool check_EmptyPath(int a, int b);

void _init_FRAME();
void _display_FRAME();
void _layout_FRAME();


struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

struct bui {
	int x;
	int y;
};

extern vector<target> walk_queue;
extern vector<walk> bfs_neighbor;

void add_neighbor(int x, int y, int wc, int back);
void pathfinding(int sx, int sy, int x, int y);
// void _ACTICE_Hard();