#include "robotface.h"

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



