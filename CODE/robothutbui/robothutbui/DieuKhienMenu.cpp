#include "DieuKhienMenu.h"
#include"BOT.h"
#include"Room.h"
#include"Run.h"
#include"ThongTinChung.h"
#include"AmTongThe.h"
#include"amthanhnen.h"

amthanhnen gett;

DieuKhienMenu::DieuKhienMenu() {

}
DieuKhienMenu::~DieuKhienMenu() {

}
void DieuKhienMenu::KhoiTaoDocDuLieu() {
	ifstream nhapFileMenu;
	nhapFileMenu.open("duLieuMenu.txt", ios_base::in);
	int soLuong, mau, x, y;
	string* str, * str2, * str3, * str4, * str5, * str6, *str7;

	//======= doc x, y
	x = WidthConsole / 7; // chia width thanh 7 phan bang nhau
	y = HeightConsole / 5; // chia height thanh 5 phan bang nhau

	//======= box menu chinh
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str[i]);
	}
	Menu* t = new Menu(x, y, soLuong, mau, str);
	menu.push_back(t);

	//======== box menu nhap
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str2 = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str2[i]);
	}

	Menu* q = new Menu(x * 3, y, soLuong, mau, str2);
	menu.push_back(q);

	//========= box menu xuat
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str3 = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str3[i]);
	}

	Menu* k = new Menu(x * 3, y, soLuong, mau, str3);
	menu.push_back(k);

	//========= box menu yes or no
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str4 = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str4[i]);
	}

	Menu* r = new Menu(x * 5, y, soLuong, mau, str4);
	menu.push_back(r);

	//========= box menu thong tin
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str5 = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str5[i]);
	}

	Menu* l = new Menu(x * 3, y, soLuong, mau, str5);
	menu.push_back(l);

	//========= box menu yes or no for out
	// khi esc 
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str6 = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str6[i]);
	}

	Menu* w = new Menu(WidthConsole / 2 - 15, 3, soLuong, mau, str6);
	menu.push_back(w);

	//========= box menu yes or no for music
	nhapFileMenu >> mau;
	nhapFileMenu >> soLuong;
	str7 = new string[soLuong];
	for (int i = 0; i < soLuong; i++) {
		getline(nhapFileMenu, str7[i]);
	}

	Menu* Z = new Menu(x , y, soLuong, mau, str7);
	menu.push_back(Z);

	nhapFileMenu.close();
}
void DieuKhienMenu::Chay() {
//	gett._phatamthanh();
	
	int Check = -1;

	AmTongThe amtongthe;
	BOT bot;
	Run run;
	ThongTinChung thongtin;
	bool _informationRoom = false;
	VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole + 2, ColorCode_DarkRed, " BAN CO MUON NGHE MOT BAN NHAC KHONG ");
	menu[6]->ChayMenu(Check);
	if (Check == 1){
		gett._phatamthanh();
		
	}

	Check = -1;

	while (true)
	{
		
		hideCur();
		clrscr();
		// y, tColor, text
		VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole + 2, ColorCode_DarkRed, " DO AN MON HOC: ROBOT HUT BUI ");
		Check = -1;
		menu[0]->ChayMenu(Check);

		if (Check == 1) {
			amtongthe._phatamthanh("Gophim");
			Check = -1;
			menu[1]->ChayMenu(Check);
			if (Check == 1) {
				// nhap tay
				clrscr();
				showCur();
				init(1);
				_informationRoom = true;
				bot.input();
				//system("pause");
			}
			else if (Check == 2) {
				// nhap tu file
				amtongthe._phatamthanh("Gophim");
				Check = -1;
				menu[3]->ChayMenu(Check);
				if (Check == 1) {
					amtongthe._phatamthanh("Gophim");
					init(2);
					bot._inputfromfile();
					_informationRoom = true;
				}

				
				menu[3]->XoaMenu();

			}
			
			menu[1]->XoaMenu();
			

		}



		else if (Check == 2) {
			Check = -1;
			menu[2]->ChayMenu(Check);
			if (Check == 1) { // Normal

				if (_informationRoom == true) {
					clrscr();
					//setup();
					tralve = bot.getter_Volte();
					amtongthe._phatamthanh("Gophim");
					bot._keKhungThongTin_TrangThaiBot();
					run.run("Normal");
		
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}

				}
				else {
					clrscr();
					amtongthe._phatamthanh("Gophim");
					run._xuatthongtinRong();
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}

				}

				tralve = bot.getter_Volte();

			}
			else if (Check == 2) {// Medium
				if (_informationRoom == true) {
					clrscr();
					//setup();
					tralve = bot.getter_Volte();
					amtongthe._phatamthanh("Gophim");
					bot._keKhungThongTin_TrangThaiBot();
					run.run("Medium");
				
					if (_getch() == 27) {
						clrscr();
						
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}

				}
				else {
					clrscr();
					amtongthe._phatamthanh("Gophim");
					run._xuatthongtinRong();
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}
				}

				tralve = bot.getter_Volte();

			}
			else if (Check == 3) { // Hard

				if (_informationRoom == true) {
					clrscr();
					//setup();
					tralve = bot.getter_Volte();
					amtongthe._phatamthanh("Gophim");
					bot._keKhungThongTin_TrangThaiBot();
					run.run("Hard");
				
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}
				}
				else {
					clrscr();
					amtongthe._phatamthanh("Gophim");
					run._xuatthongtinRong();
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}
				}

				tralve = bot.getter_Volte();
			}

			else if (Check == 4) { // For user
				if (_informationRoom == true) {
					clrscr();
					//setup();
					tralve = bot.getter_Volte();
					amtongthe._phatamthanh("Gophim");
					bot._keKhungThongTin_TrangThaiBot();
					run.run("User");
					
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}
				}
				else {
					clrscr();
					amtongthe._phatamthanh("Gophim");
					run._xuatthongtinRong();
					if (_getch() == 27) {
						clrscr();
						amtongthe._phatamthanh("canhbao");
						menu[5]->ChayMenu(Check);
						if (Check == 1) {
							menu[5]->XoaMenu();
							textColor(0);
							exit(1);
						}
					}
				}

				tralve = bot.getter_Volte();

			}
			menu[2]->XoaMenu();
		}
		else if (Check == 3) { // Giới thiệu 
			amtongthe._phatamthanh("Gophim");
			Check = -1;
			menu[4]->ChayMenu(Check);
			if (Check == 1) {
				system("cls");
				thongtin.DocThongTin("gioithieuChung");
				run._them_dac_ta_phim();
				if (_getch() == 27) {
					clrscr();
					amtongthe._phatamthanh("canhbao");
					menu[5]->ChayMenu(Check);
					if (Check == 1) {
						menu[5]->XoaMenu();
						textColor(0);
						exit(1);
					}
				}

				textColor(0);
				system("pause");

			}

			else if (Check == 2) {
				system("cls");
				thongtin.DocThongTin("huongdansudung");
				run._them_dac_ta_phim();
				if (_getch() == 27) {
					clrscr();
					amtongthe._phatamthanh("canhbao");
					menu[5]->ChayMenu(Check);
					if (Check == 1) {
						menu[5]->XoaMenu();
						textColor(0);
						exit(1);
					}
				}

				textColor(0);
				system("pause");
			}

			else if (Check == 3) {
				system("cls");
				thongtin.DocThongTin("thongtinthem");
				run._them_dac_ta_phim();
				if (_getch() == 27) {
					clrscr();
					amtongthe._phatamthanh("canhbao");
					menu[5]->ChayMenu(Check);
					if (Check == 1) {
						menu[5]->XoaMenu();
						textColor(0);
						exit(1);
					}
				}

				textColor(0);
				system("pause");

			}
			menu[4]->XoaMenu();
		}
		else if (Check == 4) {
			// thoat
			clrscr();
			amtongthe._phatamthanh("canhbao");
			menu[5]->ChayMenu(Check);
			if (Check == 1) {
				menu[5]->XoaMenu();
				textColor(0);
				exit(1);
			}
	
		}
	}
}