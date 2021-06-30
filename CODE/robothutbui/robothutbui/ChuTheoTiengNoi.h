#pragma once
//#include"TiengKeu.h"
#include"TaoChuChay.h"

class ChuTheoTiengNoi :public TaoChuChay {
private:
public:
	ChuTheoTiengNoi();
	~ChuTheoTiengNoi();
	friend class TiengKeu;
	void ChayChu(int& index);
};

