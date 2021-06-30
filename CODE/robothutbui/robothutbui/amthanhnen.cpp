#pragma comment(lib, "winmm.lib")
#include "amthanhnen.h"
#include<thread>


amthanhnen::amthanhnen() {

}

amthanhnen::~amthanhnen(){

}



void amthanhnen::_phatamthanh() {
	PlaySound(TEXT("always_with_me_spirited_away_piano.wav"), NULL, SND_ASYNC|SND_LOOP);
}