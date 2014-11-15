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

void RobotFace::Oko_zbudujPolecenieDlaGnuplota(double polozenieDolnejPowieki,double polozenieGornejPowieki,int idOka){

if(!DolnaPowieka##idOka.empty()){
_PpolozenieDolnejPowieki##idOka = DolnaPowieka[1].y;
_PpolozenieGornejPowieki##idOka = GornaPowieka[1].y;
}
	GornaPowieka##idOka = { {-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};

	DolnaPowieka##idOka = { {NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};
}
   
bool RobotFace::Oko_zapisz(int idOka,int szybkoscZmian){
	std::stringstream ss;
	double translacja_Y = 30;
	double translacja_X = 30;
	
	ss<<"dat/Oko"<<idOka<<".dat";
	std::ofstream StrmWy(ss.str());

	if (!StrmWy.is_open())
		return false;

	Wektor2D GP;
	for (auto Iter = GornaPowieka##idOka.begin(); Iter != GornaPowieka##idOka.end(); ++Iter) {
		GP = *Iter;
		GP.y += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK + translacja_Y;
		GP.x += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK
				+ translacja_X * idOka;
		StrmWy << GP << std::endl;
	}
	Wektor2D DP;
	for (auto Iter = DolnaPowieka##idOka.begin(); Iter != DolnaPowieka##idOka.end(); ++Iter) {
		DP = *Iter;
		DP.y += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK + translacja_Y;
		DP.x += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK
				+ translacja_X * idOka;
		StrmWy << DP << std::endl;
	}
	return !StrmWy.fail();

}




void RobotFace::Oko_simulateMovement(double polozenieDolnejPowieki,double polozenieGornejPowieki
					,int szybkoscZmiany,int idOka,std::string filename){


/*!
 * mikroruch dla gornej powieki
 */

std::cout<<"poprzedniePGP: "<<this->_PpolozenieGornejPowieki##idOka<<" aktualne: "<<polozenieGornejPowieki<<std::endl;
double roznicaGornejPowieki = (polozenieGornejPowieki - this->_PpolozenieGornejPowieki##idOka) / (szybkoscZmiany+1);

/*!
 * mikroruch dla dolnej powieki
 */
double roznicaDolnejPowieki = (polozenieDolnejPowieki - this->_PpolozenieDolnejPowieki##idOka) / (szybkoscZmiany+1);
	
int iloscRuchow = abs((int)(polozenieGornejPowieki - this->_PpolozenieGornejPowieki##idOka)) /abs(roznicaGornejPowieki);
std::cout<<"Jestem w symulacji!sss"<<roznicaGornejPowieki<<" "<<roznicaDolnejPowieki <<" "<<iloscRuchow<<std::endl;
double aktualnePolozenieGornejPowieki = this->_PpolozenieGornejPowieki##idOka;
double aktualnePolozenieDolnejPowieki = this->_PpolozenieDolnejPowieki##idOka;
std::cout<<filename.c_str()<<std::endl;
for(int i=0;i<iloscRuchow;i++){
	aktualnePolozenieGornejPowieki+=roznicaGornejPowieki;
	aktualnePolozenieDolnejPowieki+=roznicaDolnejPowieki;

	Oko_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejPowieki,aktualnePolozenieGornejPowieki); 

	Oko_zapisz(idOka,0);
	//getLacze().DodajNazwePliku(filename.c_str(), PzG::RR_Ciagly, 6);
	//getLacze().Rysuj();
	 usleep(10 * 1000);
}
}

/*void RobotFace::Usta_simulateMovement(double polozenieDolnejWargi,double polozenieGornejWargi,double oddalenieKacikowUst,
			double _PpolozenieDolnejWargi,double _PpolozenieGornejWargi,double _PoddalenieKacikowUst,int szybkoscZmiany){
}*/

void RobotFace::Brew_simulateMovement(int nrPolecenia,string nazwaPliku){
}
