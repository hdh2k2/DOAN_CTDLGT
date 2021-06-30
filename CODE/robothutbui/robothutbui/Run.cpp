#include "Run.h"
#include"HoTro.h"
#include"Menu.h"
#include"AmTongThe.h"


/*
##################################################
#                                                #
#  CHẠY BOT										 #
#                                                #
##################################################*/

void Run::run(string  DoKho) {
	int _hoanh_do;
	int _tung_do;
	setup();
	AmTongThe amtongthe;
	int res = tralve;
	_init_FRAME();
	_display_FRAME();
	if (DoKho == "Normal" || DoKho == "Medium" || DoKho == "User") {
		while (tralve >= 0) {
			InSoCoMau(WidthConsole / 2 + HeightConsole - HeightConsole / 8, HeightConsole / 2 + HeightConsole / 6, 17, tralve);
			if (tralve == 0) {
				amtongthe._phatamthanh("Dead_battery");
				VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 - 4, ColorCode_Red, " HET DIEN ROI !!! ");
				amtongthe._phatamthanh("Dead_battery");
				amtongthe._phatamthanh("Dead_battery");
				break;
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

			if (DoKho == "User") {
				display();
				input(DoKho);
				movements_for_USER(_hoanh_do, _tung_do);
			}

			else if (DoKho == "Normal" || DoKho == "Medium" ) {
				display();
				input(DoKho);
				movements(_hoanh_do, _tung_do);
			}
			InChuoiCoMau(WidthConsole / 2 + HeightConsole - HeightConsole / 8, HeightConsole / 2 + HeightConsole / 6, ColorCode_Back, "    ");
			_hienthi_toado_HienHanh(_hoanh_do, _tung_do);
		}
	}

	else if (DoKho == "Hard") {
		BOT x;
	//	x._keKhungThongTin_TrangThaiBot();
		x._ACTICE_Hard();
		
	}
	//textColor(0);


}

void Run::_hienthi_toado_HienHanh(int& hoanh_do, int& tung_do) {
	VietBoxCoTieuDeCenTer(HeightConsole - HeightConsole / 2 + 2, 5, " TOA DO ");
	InChuoiCoMau(WidthConsole / 2 - 4, HeightConsole - HeightConsole / 2 + 5, ColorCode_Back, "        ");
	InChuoiCoMau(WidthConsole / 2 - 3, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, "( ");
	InSoCoMau(WidthConsole / 2 - 2, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, hoanh_do);
	InChuoiCoMau(WidthConsole / 2, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, ";-0");
	InSoCoMau(WidthConsole / 2 + 3, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, tung_do);
	InChuoiCoMau(WidthConsole / 2 + 4, HeightConsole - HeightConsole / 2 + 5, ColorCode_Red, ")");

}

Menu x;

void Run::_xuatthongtinRong() {
	_draw_Empty_Room();
	InChuoiCoMau((float)WidthConsole / (float)1.3, HeightConsole * 9 / 10, ColorCode_Pink, "NHAN PHIM BAT KI DE TIEP TUC !");
	InChuoiCoMau((float)WidthConsole / (float)16, HeightConsole * 9 / 10, ColorCode_Pink, "NHAN PHIM ESE DE THOAT");

}


void Run::_them_dac_ta_phim() {
	InChuoiCoMau((float)WidthConsole / (float)1.3, HeightConsole * 9 / 10, ColorCode_Pink, "NHAN PHIM BAT KI DE TIEP TUC !");
	InChuoiCoMau((float)WidthConsole / (float)16, HeightConsole * 9 / 10, ColorCode_Pink, "NHAN PHIM ESE DE THOAT");

}