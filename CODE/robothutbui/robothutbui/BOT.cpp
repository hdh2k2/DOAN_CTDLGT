#include "BOT.h"
#include"Graphics.h"
#include"AmTongThe.h"
#include"HoTro.h"
#include<string>
#include<fstream>



BOT::BOT() {

}

BOT::~BOT() {

}

string BOT::_getter_tenthuongHieu() {
	return this->_tenthuongHieu;
}
string BOT::_getter_masosanPham() {
	return this->_masosanPham;
}

int BOT::getterHoanhdo() {
	return this->_hoanhDo;
}

int BOT::getterTungdo() {
	return this->_tungDo;
}

char BOT::getter_Dir() {
	return this->dir;
}

int BOT::getterDelay() {
	return this->delay;
}

int BOT::gettercount_Delay() {
	return this->count_delay;
}

int BOT::getter_Volte() {
	return this->Volte;
}

void BOT::_setter_tenthuongHieu(string _tenthuongHieu) {
	this->_tenthuongHieu = _tenthuongHieu;
}

void BOT::_setter_masosanPham(string _masosanPham) {
	this->_masosanPham = _masosanPham;
}

void BOT::setterHoanhdo(int _hoanhDo) {
	this->_hoanhDo = _hoanhDo;
}

void BOT::setterTungdo(int _tungDo) {
	this->_tungDo = _tungDo;
}

void BOT::setterDir(char dir) {
	this->dir = dir;
}

void BOT::setterDelay(int delay) {
	this->delay = delay;
}


void BOT::settercount_Delay(int count_delay) {
	this->count_delay = count_delay;
}


void BOT::setterVolte(int Volte) {
	this->Volte = Volte;
}


void BOT::draw() {
	
	if (dir == 'U') {
		textColor(4);
		map[_tungDo][_hoanhDo] = 2;
	}
	else if (dir == 'D') {
		textColor(4);
		map[_tungDo][_hoanhDo] = 2;
	}
	else if (dir == 'L') {
		textColor(4);
		map[_tungDo][_hoanhDo] = 2;
	}
	else if (dir == 'R' || dir == 'S') {
		textColor(4);
		map[_tungDo][_hoanhDo] = 2;
	}
}


void BOT::_hienthitoadohienhanh(int& hoanh_do, int& tung_do) {
	VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 + 2, 5, " TOA DO ");
	InChuoiCoMau(WidthConsole / 2 - 4, HeightConsole - HeightConsole / 2 + 5, ColorCode_Back, "        ");
	InChuoiCoMau(WidthConsole / 2 - 3, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, "( ");
	InSoCoMau(WidthConsole / 2 - 2, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, hoanh_do);
	InChuoiCoMau(WidthConsole / 2, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, ";-0");
	InSoCoMau(WidthConsole / 2 + 3, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, tung_do);
	InChuoiCoMau(WidthConsole / 2 + 4, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, ")");

}


void BOT::move(int &_hoanhdo, int& _tungdo) {
	Sleep(100);
	if (count_delay == delay) {
		if (dir == 'U' && !collision(_hoanhDo, _tungDo - 1)) {
			_tungDo--;
			tralve--;
		}
		if (dir == 'D' && !collision(_hoanhDo, _tungDo + 1)) {
			_tungDo++;
			tralve--;
		}
		if (dir == 'L' && !collision(_hoanhDo - 1, _tungDo)) {
			_hoanhDo--;
			tralve--;
		}

		if (dir == 'R' && !collision(_hoanhDo + 1, _tungDo)) {
			_hoanhDo++;
			tralve--;
		}
		count_delay = 0;
		dir = rand() % 4;
	}
	count_delay++;
	_hut_bui();

	_hoanhdo = _hoanhDo;
	_tungdo = _tungDo;
}


void BOT::move_for_USER(int& _hoanhdo, int& _tungdo) {


	Sleep(100);
	if (count_delay == delay) {
		if (dir == 'U' && !collision(_hoanhDo, _tungDo - 1)) {
			_tungDo--;
			tralve--;
		}
		if (dir == 'D' && !collision(_hoanhDo, _tungDo + 1)) {
			_tungDo++;
			tralve--;
		}
		if (dir == 'L' && !collision(_hoanhDo - 1, _tungDo)) {
			_hoanhDo--;
			tralve--;
		}

		if (dir == 'R' && !collision(_hoanhDo + 1, _tungDo)) {
			_hoanhDo++;
			tralve--;
		}
		count_delay = 0;
		
	}
	count_delay++;
	_hut_bui();

	_hoanhdo = _hoanhDo;
	_tungdo = _tungDo;
}


bool BOT::collision(int fx, int fy) {
	if (map[fy][fx] == 9) return true;
	return false;
}


bool BOT::empty(int fx, int fy) {
	if (map[fy][fx] == 0 ) return true;
	return false;
}


void BOT::_hut_bui() {
	AmTongThe amtongthe;
	if (map[_tungDo][_hoanhDo] == 8) {
		stage[_tungDo][_hoanhDo] = ' ';
		amtongthe._phatamthanh("eat");
	}
}


void BOT:: _hut_bui_for_hard() {
	AmTongThe amtongthe;
	if (map_for_pathfinding[_tungDo][_hoanhDo] == 8) {
		map_for_pathfinding[_tungDo][_hoanhDo] = ' ';
		amtongthe._phatamthanh("eat");
	}
}


void BOT::_luuthongtin_tubanphim() {
	int y = HeightConsole / 5;
	do {
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, " MA SO SAN PHAM GOM TOI DA 10 KI TU (SO HOAC CHU) ");
		gotoXY((float)WidthConsole / (float)7.53 + 26, y + 2);
		getline(cin, this->_masosanPham);
		// xoa du lieu cu
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                                                                 ");
		if (this->_masosanPham.length() > 10 || this->_masosanPham.length() < 1) {
			gotoXY((float)WidthConsole / (float)7.53 + 26, y + 2);
			cout << "                      ";
			if (this->_masosanPham.length() > 10) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " MA SO SAN PHAM QUA DAI! ");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " MA SO SAN PHAM TOI THIEU 1 KI TU ! ");
			}
		}
	} while (this->_masosanPham.length() > 10 || this->_masosanPham.length() < 1);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

	do {
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, " TEN THUONG HIEU GOM TOI DA 10 KI TU! ");
		gotoXY((float)WidthConsole / (float)7.53 + 27, y + 7);
		getline(cin, this->_tenthuongHieu);
		// xoa du lieu cu
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                                             ");
		if (this->_tenthuongHieu.length() > 10 || this->_tenthuongHieu.length() < 1) {
			gotoXY((float)WidthConsole / (float)7.53 + 27, y + 7);
			cout << "                     ";
			if (this->_tenthuongHieu.length() > 10) {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " TEN THUONG HIEU QUA DAI ! ");
			}
			else {
				VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " TEN THUONG HIEU TOI THIEU 1 KI TU ! ");
			}
		}
	} while (this->_tenthuongHieu.length() > 10 || this->_tenthuongHieu.length() < 1);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

	bool check = true;
	do {
		check = true;
		VietBoxCoTieuDeCenTer(HeightConsole - 7, 10, " NGUON DIEN TOI DA 1000 VOLTE, TOI THIEU 25 VOLTE ! ");
		gotoXY((float)WidthConsole / (float)1.57 + 14, y + 2);
		cin >> this->Volte;
		// xoa du lieu cu
		VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                                            ");
		gotoXY((float)WidthConsole / (float)1.57 + 14, y + 2);
		cout << "       ";

		if (this->Volte > 1000) {
			check = false;
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " NGUON DIEN QUA LON ! ");
			
		}

		else if (this->Volte < 25){
			check = false;
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " NGUON DIEN TOI THIEU 25 VOLTE ! ");
		
		}

		else if (cin.fail()) {
			
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Back, "                                            ");
			cin.clear();
			cin.ignore();
			VietBoxCoTieuDeCenTer(HeightConsole - 10, ColorCode_Red, " NHAP SAI DINH DANG, VOLTE: INT ! ");
			check = false;
		}
		
	} while (check == false);

	VietBoxCoTieuDeCenTer(HeightConsole - 7, ColorCode_Back, "                                                        ");

}


void BOT::input() {
	VeBoxInput();
	_luuthongtin_tubanphim();
	
}


void BOT::_inputfromfile() {
	ifstream nhapfile;
	nhapfile.open("dulieubot.txt", ios_base::in);
	getline(nhapfile, this->_masosanPham,',');
	nhapfile.seekg(1, 1);
	getline(nhapfile, this->_tenthuongHieu, ',');
	nhapfile.seekg(1, 1);
	nhapfile >> this->Volte;

	nhapfile.close();

}


void BOT::_keKhungThongTin_TrangThaiBot() {
	VeBoxOutput();
	_getthongTin();
	
}

void BOT::_getthongTin() {
	InChuoiCoMau(WidthConsole/2 - WidthConsole/5 + 2, HeightConsole/2 + HeightConsole/6 , 12, this->_getter_masosanPham());
	InChuoiCoMau(WidthConsole / 2 - WidthConsole / 5 + 3, HeightConsole / 2 + HeightConsole / 6 + 5, 12, this->_getter_tenthuongHieu());
	
}

void BOT::KiemTraNguonDien(int& tralve) {
	AmTongThe amtongthe;
	this->_keKhungThongTin_TrangThaiBot();
	InChuoiCoMau(WidthConsole / 2 + HeightConsole - HeightConsole / 8, HeightConsole / 2 + HeightConsole / 6, ColorCode_Back, "    ");
	InSoCoMau(WidthConsole / 2 + HeightConsole - HeightConsole / 8, HeightConsole / 2 + HeightConsole / 6, 17, tralve);
	if (tralve == 0) {
		amtongthe._phatamthanh("Dead_battery");
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, ColorCode_Red, " HET DIEN ROI !!! ");
		amtongthe._phatamthanh("Dead_battery");
		amtongthe._phatamthanh("Dead_battery");
		//	break;
	}

	if (tralve == 15) {
		amtongthe._phatamthanh("Battery_low");
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, ColorCode_Red, " NGUON DIEN CON: 15V ");

	}

	if (tralve == 12)
		XoaBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, 21);


	if (tralve == 10) {

		amtongthe._phatamthanh("Battery_low");
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, ColorCode_Red, " NGUON DIEN CON: 10V ");

	}

	if (tralve == 7)
		XoaBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, 21);

	if (tralve == 5) {
		amtongthe._phatamthanh("Battery_low");
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, ColorCode_Red, " NGUON DIEN CON: 5V ");

	}

	if (tralve == 2)
		XoaBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, 21);


}


void BOT::_ACTICE_Normal() {
	
	int x;
	x = rand() % 4;

	switch (x) {
	case 0:
		if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) this->setterDir('D');
		break;
	case 1:
		if (!this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) this->setterDir('U');
		break;
	case 2:
		if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) this->setterDir('L');
		break;
	case 3:
		if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) this->setterDir('R');
		break;

	}
	
}



void BOT::_ACTICE_Medium( int & CASE ) {
	
	if (this->empty(this->getterHoanhdo(), this->getterTungdo() - 1) ) {
		if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
			this->setterDir('L');
		}

		else if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo()))
			this->setterDir('L');

		else if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {
			this->setterDir('D');
			this->setterDir('D');
		}
			
	}

		
	else {

		switch (CASE) {
		
		case 0:
			if (!this->collision(this->getterHoanhdo(), this->getterTungdo() - 1))
				this->setterDir('U');

			else if (this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) {
				// CASE = 1;
				CASE = rand() % 4;
				_ACTICE_Medium(CASE);
				

			}
			break;
		
		case 1:
			if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo()))
				this->setterDir('R');

			else if (this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
				// CASE = 3;
				CASE = rand() % 4;
				_ACTICE_Medium(CASE);
				
			}

			break;

		case 2:
			if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo()))
				this->setterDir('L');

			else if (this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) {
				//  CASE = 3;
				CASE = rand() % 4;
				_ACTICE_Medium(CASE);
			//	this->setterDir('U');
			}

			break;

		case 3:
			if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1))
				this->setterDir('D');

			else if (this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {
				// CASE = 2;
				CASE = rand() % 4;
				_ACTICE_Medium(CASE);
			
			}


			break;

		}

	}
	
}



void BOT::_ACTICE_Hard() {
	init(2);
// Tạo bụi	
	bui temp[31];

	temp[0].x = 1;
	temp[0].y = 1;

	temp[1].x = 12;
	temp[1].y = 9;

	temp[2].x = 18;
	temp[2].y = 9;

	temp[3].x = 16;
	temp[3].y = 8;

	temp[4].x = 2;
	temp[4].y = 8;

	temp[5].x = 2;
	temp[5].y = 2;

	temp[6].x = 5;
	temp[6].y = 2;

	temp[7].x = 5;
	temp[7].y = 8;

	temp[8].x = 18;
	temp[8].y = 1;

	temp[9].x = 10;
	temp[9].y = 1;

	temp[10].x = 4;
	temp[10].y = 3;

	temp[11].x = 3;
	temp[11].y = 8;

	temp[12].x = 8;
	temp[12].y = 7;

	temp[13].x = 11;
	temp[13].y = 3;

	temp[14].x = 4;
	temp[14].y = 6;

	temp[15].x = 4;
	temp[15].y = 7;

	temp[16].x = 6;
	temp[16].y = 3;

	temp[17].x = 8;
	temp[17].y = 3;

	temp[18].x = 12;
	temp[18].y = 2;

	temp[19].x = 13;
	temp[19].y = 2;

	temp[20].x = 12;
	temp[20].y = 4;

	temp[21].x = 17;
	temp[21].y = 2;

	temp[22].x = 15;
	temp[22].y = 2;

	temp[23].x = 15;
	temp[23].y = 3;

	temp[24].x = 16;
	temp[24].y = 3;

	temp[25].x = 18;
	temp[25].y = 6;

	temp[26].x = 13;
	temp[26].y = 6;

	temp[27].x = 12;
	temp[27].y = 7;

	temp[28].x = 18;
	temp[28].y = 7;

	temp[29].x = 18;
	temp[29].y = 8;

	temp[30].x = 17;
	temp[30].y = 8;

	int tral = 31;




	int old_x;
	int old_y;

	
	this->_hoanhDo = 10;
	this->_tungDo = 9;



	init_MAP_FOR_HARD();

	for (int i = 0; i < tral; i++) {

		gotoXY(temp[i].x + (WidthConsole / 2 - _dorongStage / 2 + 2), temp[i].y + 7);
		cout << char(250);
	}

	int frame = 0;
	int i = 0;
	textColor(5);
	int _hoanh_do;
	int _tung_do;

Finding:
	pathfinding(this->_hoanhDo, this->_tungDo, temp[i].x, temp[i].y);
	while (tralve >= 0) {
		
		this->KiemTraNguonDien(tralve);

		Sleep(200);
		gotoXY(this->_hoanhDo + (WidthConsole / 2 - _dorongStage / 2 + 2), this->_tungDo + 7); cout << " ";
	
		if (walk_queue.size() != 0) {
			this->_hoanhDo = walk_queue.back().x;
			this->_tungDo = walk_queue.back().y;
			walk_queue.pop_back();
		}

	

		gotoXY(this->_hoanhDo + (WidthConsole / 2 - _dorongStage / 2 + 2), this->_tungDo + 7); cout << char(254);
		tralve--;
		_hoanh_do = this->_tungDo;
		_tung_do = this->_hoanhDo;
		_hienthitoadohienhanh(_tung_do, _hoanh_do);

		if (this->_hoanhDo == temp[i].x && this->_tungDo == temp[i].y) {

			i++;
			if (tralve == 0 || i == tral) {
				if(i == tral)
					VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, ColorCode_DarkRed, " DA QUET SACH BUI !!! ");
				break;
			}
			else {
				goto Finding;
			}
			
		}


	
	}

	
}


void BOT::_ACTICE_FOR_USER() {
	if (_kbhit()) {

		switch (_getch()) {
		case 80:
			if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1))
				this->setterDir('D');

			else if (this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {

				if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) {
					this->setterDir('L');
				}

				else if (this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) {
					if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
						this->setterDir('R');
					}

					else if (this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
						if (!this->collision(this->getterHoanhdo(), this->getterTungdo() - 1))
							this->setterDir('U');
					}
				}
			}


			break;
		case 72:
			if (!this->collision(this->getterHoanhdo(), this->getterTungdo() - 1))
				this->setterDir('U');

			else if (this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) {
				if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
					this->setterDir('R');
				}

				else if (this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
					if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) {
						this->setterDir('L');
					}

					else if (this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) {
						if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1))
							this->setterDir('D');
					}
				}
			}
			break;
		case 75:
			if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo()))
				this->setterDir('L');

			else if (this->collision(this->getterHoanhdo() - 1, this->getterTungdo())) {
				if (!this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) {
					this->setterDir('U');
				}

				else if (this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) {
					if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {
						this->setterDir('D');
					}

					else if (this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {
						if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo()))
							this->setterDir('R');
					}
				}
			}

			break;
		case 77:
			if (!this->collision(this->getterHoanhdo() + 1, this->getterTungdo()))
				this->setterDir('R');

			else if (this->collision(this->getterHoanhdo() + 1, this->getterTungdo())) {
				if (!this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {
					this->setterDir('D');
				}

				else if (this->collision(this->getterHoanhdo(), this->getterTungdo() + 1)) {
					if (!this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) {
						this->setterDir('U');
					}

					else if (this->collision(this->getterHoanhdo(), this->getterTungdo() - 1)) {
						if (!this->collision(this->getterHoanhdo() - 1, this->getterTungdo()))
							this->setterDir('L');
					}
				}
			}

			break;

		}
	}
}
