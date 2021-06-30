#include"DieuKhienMenu.h"
#include"BOT.h"
#include"ThongTinChung.h"
#include"AmTongThe.h"
#include"Room.h"
#include"_Branch_Begin.h"
#include"amthanhnen.h"
#include"Run.h"

_Branch_Begin _checkout_branch;



int main() {
	
	////system("color f0");
	SetConsoleTitle(L"_robothutbui_HHD");
	fullScreen(); // Chỉnh toàn bộ màn hình
	removeScrollBar(); // xóa thanh cuộn
	getWHConsole(); // lấy ra biến toàn cục của width và height của màn hình hiện tại
	hideCur(); // ẩn trỏ chuột
	FrameIntro(1);
//	_Branch_Begin _checkout_branch;
//	_checkout_branch.beging();
	system("cls");
	DieuKhienMenu x; //= new DieuKhienMenu;
	x.KhoiTaoDocDuLieu();
	x.Chay();

}