#include"AmTongThe.h"
#include"Room.h"
#include"BOT.h"
#include"Graphics.h"
#include"HoTro.h"
#include"Run.h"


#if 1
extern int const _docaoStage = 11;
extern int const _dorongStage = 20;

extern int const XX = 15;
extern int const YY = 32;
char map[_docaoStage][_dorongStage];
char stage[_docaoStage][_dorongStage];
char map_for_pathfinding[_docaoStage][_dorongStage];
char FRAME[XX][YY];
char FRAME_MAP[XX][YY];


#endif 

AmTongThe amtongthe;

BOT bot;
Run run;

vector<target> walk_queue;
vector<walk> bfs_neighbor;

extern int tralve = bot.getter_Volte();



void setup() {
	srand(time(NULL));
	bot.setterHoanhdo(9);
	bot.setterTungdo(9);
	bot.setterDir('S');
	bot.setterDelay(2);
}

bool check_EmptyPath(int a, int b) {

	for (int j = 0; j < _dorongStage; j++) {
		if (map[a][j] != 0)
			return false;
		if (map[_docaoStage - 1 - a][j] != 0)
			return false;
	}

	for (int i = 0; i < _docaoStage; i++) {
		if (map[i][b] != 0)
			return false;
		if (map[i][_dorongStage - 1 -b] != 0)
			return false;

	}

	return true;
}

void layout() {
	for (int i = 0; i < _docaoStage; i++) {
		for (int j = 0; j < _dorongStage; j++) {
			if (stage[i][j] == '1') map[i][j] = 9;
			else if (stage[i][j] == '0') map[i][j] = 8;
			else map[i][j] = 0;
		}
	}
}

void init_MAP() {
	textColor(5);
	for (int i = 0; i < _docaoStage; i++) {
		for (int j = 0; j < _dorongStage; j++) {
			gotoXY(j + (WidthConsole / 2 - _dorongStage / 2 + 2), i + 7);
			if (map[i][j] == 9) cout << char(219);
			if (map[i][j] == 8) cout << char(250);
			if (map[i][j] == 2) cout << char(254);
			if (map[i][j] == 0) cout << ' ';


		}
	}
}

void init_MAP_FOR_HARD() {
	textColor(5);
	for (int i = 0; i < _docaoStage; i++) {
		for (int j = 0; j < _dorongStage; j++) {
			gotoXY(j + (WidthConsole / 2 - _dorongStage / 2 + 2), i + 7);
			if (stage[i][j] == '1') cout << char(219);
			if (stage[i][j] == '0') cout << char(250);
			//cout << stage[i][j];
		}
		cout << endl;
	}
}

void display() {
	layout();
	bot.draw();
	init_MAP();
}

void branchMaster() {
	
	for (int i = 0; i < bot.getter_Volte() + 1000; i++) {
		display();
		bot.setterDir('R');

	}
}

int CASE = 0;

void input(string  DoKho) {

	run._them_dac_ta_phim();

	if (DoKho == "Normal") { // Não bình thường
		bot._ACTICE_Normal();
	}


	// 80: xuong, 72 len, 75 trai, 77 phai
	if (DoKho == "Medium") { // Não check va chạm
		bot._ACTICE_Medium(CASE);
		
	}

	if (DoKho == "User") { // Người dùng di chuyển && bị ràng buộc
		bot._ACTICE_FOR_USER();
	}


}


void movements(int& _hoanhdo, int& _tungdo) {
	bot.move(_hoanhdo,_tungdo);
}

void movements_for_USER(int& _hoanhdo, int& _tungdo) {
	bot.move_for_USER(_hoanhdo, _tungdo);
}

void init(int index) {
	if (index == 1) {

		int a[_docaoStage][_dorongStage];

		for (int j = 0; j < _dorongStage; j++) {
			a[0][j] = 1;
			stage[0][j] = '1';
		}

		for (int j = 0; j < _dorongStage; j++) {
			a[_docaoStage - 1][j] = 1;
			stage[_docaoStage - 1][j] = '1';
		}

		for (int i = 0; i < _docaoStage; i++) {
			a[i][_dorongStage - 1] = 1;
			stage[i][_dorongStage - 1] = '1';
		}

		for (int i = 0; i < _docaoStage; i++) {
			a[i][0] = 1;
			stage[i][0] = '1';
		}

		srand(time(NULL));
		for (int i = 1; i < _docaoStage - 1; i++) {
			for (int j = 1; j < _dorongStage - 1; j++) {

				a[i][j] = rand() % 3;
				if (a[i][j] == 0) stage[i][j] = '1';
				else if (a[i][j] != 0) stage[i][j] = '0';
			}
		}

	}

	else  if (index == 2) {
		ifstream nhapFileMenu;
		nhapFileMenu.open("room_11x20.txt", ios_base::in);
		for (int i = 0; i < _docaoStage; i++) {
			for (int j = 0; j < _dorongStage; j++) {

				nhapFileMenu >> stage[i][j];
			}

		}
		nhapFileMenu.close();
	}
}

void _init_FRAME() {
	ifstream nhapFileMenu;
	nhapFileMenu.open("FRAME.txt", ios_base::in);
	for (int i = 0; i < XX; i++) {
		for (int j = 0; j < YY; j++) {

			nhapFileMenu >> FRAME[i][j];
		}

	}
	nhapFileMenu.close();
}

void _display_FRAME() {


	for (int i = 0; i < XX; i++) {
		for (int j = 0; j < YY; j++) {
			if (FRAME[i][j] == '0') FRAME_MAP[i][j] = 0;
			else if (FRAME[i][j] == '1') FRAME_MAP[i][j] = 1;
			
		}
	}

	textColor(5);
	for (int i = 0; i < XX; i++) {
		for (int j = 0; j < YY; j++) {
			gotoXY(j + (WidthConsole / 2 - YY / 2 + 2), i + 5);
			
			if (FRAME_MAP[i][j] == 1) cout << ' ';
			if (FRAME_MAP[i][j] == 0) cout << char(250);


		}
	}
}

void add_neighbor(int x, int y, int wc, int back) {
	if (map_for_pathfinding[y][x] == '0' || map_for_pathfinding[y][x] == ' ') {
		map_for_pathfinding[y][x] = '1';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		bfs_neighbor.push_back(tmp);
	}
}


void pathfinding(int sx, int sy, int x, int y) {
	memcpy(map_for_pathfinding, stage, sizeof(stage));
	bfs_neighbor.clear();
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	bfs_neighbor.push_back(tmp);

	int i = 0;
	while (i < bfs_neighbor.size()) {
		if (bfs_neighbor[i].x == x && bfs_neighbor[i].y == y) {
			walk_queue.clear();
			target tmp2;
			while (bfs_neighbor[i].walk_count != 0) {
				tmp2.x = bfs_neighbor[i].x;
				tmp2.y = bfs_neighbor[i].y;
				walk_queue.push_back(tmp2);

				i = bfs_neighbor[i].back;
			}

			break;
		}

		add_neighbor(bfs_neighbor[i].x + 1, bfs_neighbor[i].y, bfs_neighbor[i].walk_count + 1, i);
		add_neighbor(bfs_neighbor[i].x - 1, bfs_neighbor[i].y, bfs_neighbor[i].walk_count + 1, i);
		add_neighbor(bfs_neighbor[i].x, bfs_neighbor[i].y + 1, bfs_neighbor[i].walk_count + 1, i);
		add_neighbor(bfs_neighbor[i].x, bfs_neighbor[i].y - 1, bfs_neighbor[i].walk_count + 1, i);

		
		i++;
	}

	bfs_neighbor.clear();
}
