#include "ThongTinChung.h"
#include<fstream>
#include<iostream>
#include <sstream>
#include <string>
#include"Graphics.h"
#include"HoTro.h"
#include"AmTongThe.h"

using namespace std;

void ThongTinChung::DocThongTin(string luachon) {
	AmTongThe amtongthe;
	if (luachon == "gioithieuChung") {
		ifstream docfile;
		docfile.open("gioithieuChung.txt", ios_base::in);
		if (docfile.fail()) {
			cerr << "Check lai file, ban nhe" << endl;
			docfile.close();
			exit(1);
		}
		string line;
		int i = 1;
		while (getline(docfile, line)) {
			//gotoXY(WidthConsole / 2, 2);
			InChuoiCoMau(WidthConsole / 2 - 41, i, 7, line);
			amtongthe._phatamthanh("Gophim");
			i++;
		}
		
		docfile.close();
	}

	if (luachon == "huongdansudung") {
		ifstream docfile;
		docfile.open("huongdansudung.txt", ios_base::in);
		if (docfile.fail()) {
			cerr << "Check lai file, ban nhe" << endl;
			docfile.close();
			exit(1);
		}
		string line;
		int i = 1;
		while (getline(docfile, line)) {
			//gotoXY(WidthConsole / 2, 2);
			InChuoiCoMau(WidthConsole / 2 - 29, i, 7, line);
			amtongthe._phatamthanh("Gophim");
			i++;
		}

		docfile.close();
	}

	if (luachon == "thongtinthem") {
		ifstream docfile;
		docfile.open("thongtinthem.txt", ios_base::in);
		if (docfile.fail()) {
			cerr << "Check lai file, ban nhe" << endl;
			docfile.close();
			exit(1);
		}
		string line;

		int i = 1;
		while (getline(docfile, line)) {
			//gotoXY(WidthConsole / 2 , i);
			InChuoiCoMau(WidthConsole / 2 - 20, i, 7, line);
			
			amtongthe._phatamthanh("Gophim");
			//Sleep(100);
			//cout << line << endl;
			i++;
		}
	}

}



