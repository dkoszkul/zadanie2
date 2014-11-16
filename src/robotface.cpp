#include "robotface.h"


PzG::LaczeDoGNUPlota RobotFace:: getLacze(){
	return Lacze;
}

/////////////////USTA//////////////////////

void RobotFace::Usta_zbudujPolecenieDlaGnuplota(double polozenieDolnejWargi,double polozenieGornejWargi,double oddalenieKacikowUst){

	if(!GornaWarga.empty()){
		_PpolozenieDolnejWargi=DolnaWarga[1].y;
		_PpolozenieGornejWargi=GornaWarga[1].y;
		_PoddalenieKacikowUst=GornaWarga[2].x - NEUTRALNE_POLOZENIE_KACIKOW_UST;
	}

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
else if(idOka == 1 ) {
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

Oko_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejPowieki,aktualnePolozenieGornejPowieki,idOka); 
/*!
 * mikroruch dla gornej powieki
 */
if(idOka == 0 ) {
roznicaGornejPowieki = (polozenieGornejPowieki - this->_PpolozenieGornejPowieki0) /  (10*(szybkoscZmiany/100)+1);

/*!
 * mikroruch dla dolnej powieki
 */
roznicaDolnejPowieki = (polozenieDolnejPowieki - this->_PpolozenieDolnejPowieki0) /  (10*(szybkoscZmiany/100)+1);
	
iloscRuchow = 10*(szybkoscZmiany/100)+1;//abs((int)(polozenieGornejPowieki - this->_PpolozenieGornejPowieki0)) /abs(roznicaGornejPowieki);
aktualnePolozenieGornejPowieki = this->_PpolozenieGornejPowieki0;
aktualnePolozenieDolnejPowieki = this->_PpolozenieDolnejPowieki0;
}

else if(idOka == 1 ) {

roznicaGornejPowieki = (polozenieGornejPowieki - this->_PpolozenieGornejPowieki1) / (10*(szybkoscZmiany/100)+1);

/*!
 * mikroruch dla dolnej powieki
 */
roznicaDolnejPowieki = (polozenieDolnejPowieki - this->_PpolozenieDolnejPowieki1) / (10*(szybkoscZmiany/100)+1);
	
iloscRuchow = (10*(szybkoscZmiany/100)+1);//abs((int)(polozenieGornejPowieki - this->_PpolozenieGornejPowieki1)) /abs(roznicaGornejPowieki);
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
	 usleep(50 * 1000);
}
}

void RobotFace::Usta_simulateMovement(double polozenieDolnejWargi,double polozenieGornejWargi,
					double oddalenieKacikowUst,int szybkoscZmiany,std::string filename){

double roznicaGornejWargi = 0;
double roznicaDolnejWargi = 0;
double roznicaOddaleniaKacikowUst = 0;
int iloscRuchow = 0;
double aktualnePolozenieGornejWargi = 0;
double aktualnePolozenieDolnejWargi = 0;
double aktualneOddalenieKacikowUst = 0;

Usta_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejWargi,aktualnePolozenieGornejWargi,aktualneOddalenieKacikowUst); 
/*!
 * mikroruch dla gornej wargi
 */

roznicaGornejWargi = (polozenieGornejWargi - this->_PpolozenieGornejWargi) /  (10*(szybkoscZmiany/100)+1);

/*!
 * mikroruch dla dolnej wargi
 */
roznicaDolnejWargi = (polozenieDolnejWargi - this->_PpolozenieDolnejWargi) /  (10*(szybkoscZmiany/100)+1);
	
/*!
 * mikroruch dla odchylenia ust
 */
roznicaOddaleniaKacikowUst = (oddalenieKacikowUst - this->_PoddalenieKacikowUst) /  (10*(szybkoscZmiany/100)+1);

iloscRuchow = 10*(szybkoscZmiany/100)+1;//abs((int)(polozenieGornejWargi - this->_PpolozenieGornejWargi)) /abs(roznicaGornejWargi);
aktualnePolozenieGornejWargi = this->_PpolozenieGornejWargi;
aktualnePolozenieDolnejWargi = this->_PpolozenieDolnejWargi;
aktualneOddalenieKacikowUst = this->_PoddalenieKacikowUst;


std::cout<<filename.c_str()<<std::endl;
for(int i=0;i<iloscRuchow;i++){
	aktualnePolozenieGornejWargi+=roznicaGornejWargi;
	aktualnePolozenieDolnejWargi+=roznicaDolnejWargi;
	aktualneOddalenieKacikowUst+=roznicaOddaleniaKacikowUst;
	Usta_zbudujPolecenieDlaGnuplota(aktualnePolozenieDolnejWargi,aktualnePolozenieGornejWargi,aktualneOddalenieKacikowUst); 

	Usta_zapisz(0);
	getLacze().DodajNazwePliku(filename.c_str(), PzG::RR_Ciagly, 6);
	getLacze().Rysuj();
	 usleep(50 * 1000);
}
}


void RobotFace::Brew_simulateMovement(int nrPolecenia,string nazwaPliku){
}
