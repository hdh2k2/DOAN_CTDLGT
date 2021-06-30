#pragma once
#include "Menu.h"
#include <fstream>
#include <vector>
#include "HoTro.h"
#include "Graphics.h"

class DieuKhienMenu {
private:
	vector<Menu*> menu;
public:
	DieuKhienMenu();
	~DieuKhienMenu();

	void KhoiTaoDocDuLieu();
	void Chay();
};
