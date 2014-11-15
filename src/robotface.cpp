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
if(idOka == 0 ) {
if(!DolnaPowieka0.empty()){
_PpolozenieDolnejPowieki0 = DolnaPowieka0[1].y;
_PpolozenieGornejPowieki0 = GornaPowieka0[1].y;
}
	GornaPowieka0 = { {-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};

	DolnaPowieka0 = { {NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};
}
if(idOka == 1 ) {
if(!DolnaPowieka1.empty()){
_PpolozenieDolnejPowieki1 = DolnaPowieka1[1].y;
_PpolozenieGornejPowieki1 = GornaPowieka1[1].y;
}
	GornaPowieka1 = { {-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieGornejPowieki}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};

	DolnaPowieka1 = { {NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}
		, {	NEUTRALNE_POLOZENIE_KACIKOW_POWIEK-7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK+7,polozenieDolnejPowieki}
		, {	-NEUTRALNE_POLOZENIE_KACIKOW_POWIEK,0}};
}
}

   
bool RobotFace::Oko_zapisz(int idOka,int szybkoscZmian){
	std::stringstream ss;
	double translacja_Y = 30;
	double translacja_X = 30;
	
	ss<<"dat/Oko"<<idOka<<".dat";
	std::ofstream StrmWy(ss.str());

	if (!StrmWy.is_open())
		return false;
if(idOka == 0 ) {
Wektor2D GP;
	for (auto Iter = GornaPowieka0.begin(); Iter != GornaPowieka0.end(); ++Iter) {
		GP = *Iter;
		GP.y += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK + translacja_Y;
		GP.x += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK
				+ translacja_X * idOka;
		StrmWy << GP << std::endl;
	}
	Wektor2D DP;
	for (auto Iter = DolnaPowieka0.begin(); Iter != DolnaPowieka0.end(); ++Iter) {
		DP = *Iter;
		DP.y += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK + translacja_Y;
		DP.x += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK
				+ translacja_X * idOka;
		StrmWy << DP << std::endl;
	}
	return !StrmWy.fail();
}
if(idOka == 1 ) {
Wektor2D GP;
	for (auto Iter = GornaPowieka1.begin(); Iter != GornaPowieka1.end(); ++Iter) {
		GP = *Iter;
		GP.y += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK + translacja_Y;
		GP.x += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK
				+ translacja_X * idOka;
		StrmWy << GP << std::endl;
	}
	Wektor2D DP;
	for (auto Iter = DolnaPowieka1.begin(); Iter != DolnaPowieka1.end(); ++Iter) {
		DP = *Iter;
		DP.y += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK + translacja_Y;
		DP.x += -1.1 * NEUTRALNE_POLOZENIE_KACIKOW_POWIEK
				+ translacja_X * idOka;
		StrmWy << DP << std::endl;
	}
	return !StrmWy.fail();
}	

}




void RobotFace::Oko_simulateMovement(double polozenieDolnejPowieki,double polozenieGornejPowieki
					,int szybkoscZmiany,int idOka,std::string filename){

double roznicaGornejPowieki = 0;
double roznicaDolnejPowieki = 0;
int iloscRuchow = 0;
double aktualnePolozenieGornejPowieki = 0;
double aktualnePolozenieDolnejPowieki = 0;
/*!
 * mikroruch dla gornej powieki
 */
if(idOka == 0 ) {
std::cout<<"poprzedniePGP: "<<this->_PpolozenieGornejPowieki0<<" aktualne: "<<polozenieGornejPowieki<<std::endl;
roznicaGornejPowieki = (polozenieGornejPowieki - this->_PpolozenieGornejPowieki0) / (szybkoscZmiany+1);

/*!
 * mikroruch dla dolnej powieki
 */
roznicaDolnejPowieki = (polozenieDolnejPowieki - this->_PpolozenieDolnejPowieki0) / (szybkoscZmiany+1);
	
iloscRuchow = abs((int)(polozenieGornejPowieki - this->_PpolozenieGornejPowieki0)) /abs(roznicaGornejPowieki);
std::cout<<"Jestem w symulacji!sss"<<roznicaGornejPowieki<<" "<<roznicaDolnejPowieki <<" "<<iloscRuchow<<std::endl;
aktualnePolozenieGornejPowieki = this->_PpolozenieGornejPowieki0;
aktualnePolozenieDolnejPowieki = this->_PpolozenieDolnejPowieki0;
}

else if(idOka == 1 ) {
std::cout<<"poprzedniePGP: "<<this->_PpolozenieGornejPowieki1<<" aktualne: "<<polozenieGornejPowieki<<std::endl;
roznicaGornejPowieki = (polozenieGornejPowieki - this->_PpolozenieGornejPowieki1) / (szybkoscZmiany+1);

/*!
 * mikroruch dla dolnej powieki
 */
roznicaDolnejPowieki = (polozenieDolnejPowieki - this->_PpolozenieDolnejPowieki1) / (szybkoscZmiany+1);
	
iloscRuchow = abs((int)(polozenieGornejPowieki - this->_PpolozenieGornejPowieki1)) /abs(roznicaGornejPowieki);
std::cout<<"Jestem w symulacji!sss"<<roznicaGornejPowieki<<" "<<roznicaDolnejPowieki <<" "<<iloscRuchow<<std::endl;
 aktualnePolozenieGornejPowieki = this->_PpolozenieGornejPowieki1;
 aktualnePolozenieDolnejPowieki = this->_PpolozenieDolnejPowieki1;
}

std::cout<<filename.c_str()<<std::endl;
for(int i=0;i<iloscRuchow;i++){
	aktualnePolozenieGornejPowieki+=roznicaGornejPowieki;
	aktualnePolozenieDolnejPowieki+=roznicaDolnejPowieki;

	Oko_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejPowieki,aktualnePolozenieGornejPowieki,idOka); 

	Oko_zapisz(idOka,0);
	getLacze().DodajNazwePliku(filename.c_str(), PzG::RR_Ciagly, 6);
	getLacze().Rysuj();
	 usleep(3000 * 1000);
}
}

/*void RobotFace::Usta_simulateMovement(double polozenieDolnejWargi,double polozenieGornejWargi,double oddalenieKacikowUst,
			double _PpolozenieDolnejWargi,double _PpolozenieGornejWargi,double _PoddalenieKacikowUst,int szybkoscZmiany){
}*/

void RobotFace::Brew_simulateMovement(int nrPolecenia,string nazwaPliku){
}
