#include "robotface.h"


PzG::LaczeDoGNUPlota RobotFace:: getLacze(){
	return Lacze;
}

/////////////////USTA//////////////////////

void RobotFace::Usta_zbudujPolecenieDlaGnuplota(double polozenieDolnejWargi,double polozenieGornejWargi,double oddalenieKacikowUst){

	GornaWarga = { {-NEUTRALNE_POLOZENIE_KACIKOW_UST-oddalenieKacikowUst,0}
		, {	0,polozenieGornejWargi}, {NEUTRALNE_POLOZENIE_KACIKOW_UST+oddalenieKacikowUst,0}};

	DolnaWarga = { {NEUTRALNE_POLOZENIE_KACIKOW_UST+oddalenieKacikowUst,0}
		, {	0,polozenieDolnejWargi}, {-NEUTRALNE_POLOZENIE_KACIKOW_UST-oddalenieKacikowUst,0}};

}

bool RobotFace::Usta_zapisz(int szybkoscZmian){

	double translacja_Y = -10;
	std::ofstream StrmWy("dat/Usta.dat");

	if (!StrmWy.is_open())
		return false;

	Wektor2D GW;
	for (auto Iter = GornaWarga.begin(); Iter != GornaWarga.end(); ++Iter) {
		GW = *Iter;
		GW.y += translacja_Y;
		StrmWy << GW << std::endl;
	}
	Wektor2D DW;
	for (auto Iter = DolnaWarga.begin(); Iter != DolnaWarga.end(); ++Iter) {
		DW = *Iter;
		DW.y += translacja_Y;
		StrmWy << DW << std::endl;
	}
	return !StrmWy.fail();

}

//////////////////////////OKO///////////////////////////

void RobotFace::Oko_zbudujPolecenieDlaGnuplota(double polozenieDolnejPowieki,double polozenieGornejPowieki){
 	
	GornaPowieka = { {-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};

	DolnaPowieka = { {NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};
}

bool RobotFace::Oko_zapisz(int idOka,int szybkoscZmian){
	std::stringstream ss;
	double translacja_Y = -10;
	
	ss<<"dat/Oko"<<idOka<<".dat";
	std::ofstream StrmWy(ss.str());

	if (!StrmWy.is_open())
		return false;

	Wektor2D GW;
	for (auto Iter = GornaWarga.begin(); Iter != GornaWarga.end(); ++Iter) {
		GW = *Iter;
		GW.y += translacja_Y;
		StrmWy << GW << std::endl;
	}
	Wektor2D DW;
	for (auto Iter = DolnaWarga.begin(); Iter != DolnaWarga.end(); ++Iter) {
		DW = *Iter;
		DW.y += translacja_Y;
		StrmWy << DW << std::endl;
	}
	return !StrmWy.fail();

}
