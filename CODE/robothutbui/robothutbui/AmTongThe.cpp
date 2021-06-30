#include "AmTongThe.h"

AmTongThe::AmTongThe() {

}

AmTongThe::~AmTongThe() {

}


void AmTongThe::_phatamthanh(string s ) {
	if (s == "click") {
		PlaySound(TEXT("click.wav"), NULL, SND_SYNC);
	}

	if (s == "eat") {
		PlaySound(TEXT("eat.wav"), NULL, SND_SYNC);
	}

	if (s == "canhbao") {
		PlaySound(TEXT("canhbao.wav"), NULL, SND_SYNC);
	}

	if (s == "Battery_low") {
		PlaySound(TEXT("Battery_low.wav"), NULL, SND_SYNC);
	}

	if (s == "Gophim") {
		PlaySound(TEXT("Gophim.wav"), NULL, SND_SYNC);
	}

	if (s == "Dead_battery") {
		PlaySound(TEXT("Dead_battery.wav"), NULL, SND_SYNC);
	}


	if (s == "03 Chibi Ninja") {
		PlaySound(TEXT("03 Chibi Ninja.wav"), NULL, SND_ASYNC);
	}
}